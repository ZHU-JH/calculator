#include"mainwindow.h"
#include"ui_mainwindow.h"
#include"calculator.h"
#include"global.h"
#include"Factory.h"
#include<QTextTable>
#include<QTextTableCellFormat>
#include<QTextDocument>
#include<Eigen/Dense>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonEqual_,SIGNAL(clicked()),this,SLOT(on_buttonEqual_clicked()));
    connect(ui->buttonANS_,SIGNAL(clicked()),this,SLOT(on_buttonANS_clicked()));
    connect(ui->buttonClear_,SIGNAL(clicked()),this,SLOT(on_buttonClear_clicked()));
    connect(ui->buttonDelete_,SIGNAL(clicked()),this,SLOT(on_buttonDelete_clicked()));
    connect(ui->buttonPlus_,SIGNAL(clicked()),this,SLOT(on_buttonPlus_clicked()));
    connect(ui->buttonMinus_,SIGNAL(clicked()),this,SLOT(on_buttonMinus_clicked()));
    connect(ui->buttonMultiply_,SIGNAL(clicked()),this,SLOT(on_buttonMultiply_clicked()));
    connect(ui->buttonDivide_,SIGNAL(clicked()),this,SLOT(on_buttonDivide_clicked()));
    connect(ui->buttonLeft_,SIGNAL(clicked()),this,SLOT(on_buttonLeft_clicked()));
    connect(ui->buttonRight_,SIGNAL(clicked()),this,SLOT(on_buttonRight_clicked()));
    connect(ui->buttonInverse_,SIGNAL(clicked()),this,SLOT(on_buttonInverse_clicked()));
    connect(ui->buttonPow_,SIGNAL(clicked()),this,SLOT(on_buttonPow_clicked()));
    //设置字体大小
    QFont font;
    font.setPointSize(15);
    ui->textInput->document()->setDefaultFont(font);
    ui->textOutput->document()->setDefaultFont(font);
    //设置表格格式
    tableFormat.setMargin(0);
    tableFormat.setPadding(0);
    tableFormat.setBorder(1);
    //设置单元格格式
    line.setVerticalAlignment(QTextCharFormat::AlignMiddle);//居中单元格
    //矩阵单元格
    cellFormat.setLeftBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    cellFormat.setRightBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    cellFormat.setLeftBorder(1);
    cellFormat.setRightBorder(1);
    cellFormat.setPadding(2);
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    ui->textInput->blockSignals(true);
    includeMatrix=false;
    position=0;
    Calculator::getInstance().clear();
    stream.clear();         //清空数据流
    stream.emplace_back("");
    matrix_list.clear();        //清空矩阵队列
    ui->textOutput->clear();//清空输出面板
    //输入面板初始化
    ui->textInput->clear();//清空输入面板
    cursor=ui->textInput->textCursor();
    table=cursor.insertTable(1,1,tableFormat);
    //字符居中
    table->cellAt(0,0).setFormat(line);
    ui->textInput->setTextCursor(cursor);
    ui->textInput->setFocus();
    //矩阵输入面板设置
    ui->spinBoxRow->setValue(1);
    ui->spinBoxCol->setValue(1);
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setHidden(true);//隐藏表头
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //平均分配列宽
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配行宽
    ui->textInput->blockSignals(false);
}


void MainWindow::input(string s_diplayed,string s){
    if(stream.empty())initialize();
    //保存数据  
    if(isNum(s)){
        if(isNum(stream.back()))stream.back()+=s;
        else stream.emplace_back(s);
        /*
        if(isNum(stream[position])){//在数字格内
            stream[position].insert(cursor.positionInBlock(),s);
        }
        else{
            stream.insert(stream.begin()+position,s);
            position++;
        }
        */
    }
    else{
        auto ptr=Factory::create(s);
         stream.emplace_back(s);
         //单目运算符且有右操作数则补全（
         if(ptr->numOprand==1&&ptr->haveRightOprand){
             stream.emplace_back("(");
         }
    }
    //显示数据
    cursor.beginEditBlock();
    if(isNum(s))cursor.insertText(QString::fromStdString(s_diplayed));
    else{
        //表尾单元格非空则插入新单元格
        if(table->cellAt(0,position).firstPosition()!=table->cellAt(0,position).lastPosition()){
            table->appendColumns(1);
            table->cellAt(0,++position).setFormat(line);
        }
        cursor.insertText(QString::fromStdString(s_diplayed));
        auto ptr=Factory::create(s);
        //单目运算符且有右操作数则补全（
        if(ptr->numOprand==1&&ptr->haveRightOprand){
            cursor.endEditBlock();
            cursor.beginEditBlock();
            table->appendColumns(1);
            table->cellAt(0,++position).setFormat(line);
            cursor.insertText(QString::fromStdString("("));
        }
        table->appendColumns(1);
        table->cellAt(0,++position).setFormat(line);
    }
    cursor.endEditBlock();
}

void MainWindow::input_matrix(const Eigen::MatrixXd& m)
{
    int row=m.rows();
    int col=m.cols();
    cursor.beginEditBlock();
    table->appendColumns(1);
    table->cellAt(0,++position).setFormat(cellFormat);
    //嵌套表格
    QTextTable *subtable=cursor.insertTable(row,col,tableFormat);
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            cursor = subtable->cellAt(i,j).firstCursorPosition();
            cursor.insertText(doubleToQString(m(i,j)));
        }
    }
    table->appendColumns(1);
    table->cellAt(0,++position).setFormat(line);
    cursor=table->cellAt(0,position).firstCursorPosition();
    cursor.endEditBlock();
}

void MainWindow::on_textInput_textChanged()
{
    ui->textInput->setFocus();
    ui->textInput->setTextCursor(cursor);
    //ui->textOutput->setText(QString::fromStdString(stream[position]));
}
/******************************************************************************************/
//按键槽函数
#define BUTTON_3(S_DISPLAYED,S_ACTUAL,S_NAME) void MainWindow::on_button##S_NAME##_clicked(){input(S_DISPLAYED,S_ACTUAL);}
#define BUTTON_2(S_DISPLAYED,S_NAME) BUTTON_3(S_DISPLAYED,S_DISPLAYED,S_NAME)
#define BUTTON_1(NUM) BUTTON_3(#NUM,#NUM,NUM)

BUTTON_1(0)
BUTTON_1(1)
BUTTON_1(2)
BUTTON_1(3)
BUTTON_1(4)
BUTTON_1(5)
BUTTON_1(6)
BUTTON_1(7)
BUTTON_1(8)
BUTTON_1(9)
BUTTON_2(".",Dot)
BUTTON_2("+",Plus)
BUTTON_2("-",Minus)
BUTTON_2("(",Left)
BUTTON_2(")",Right)
BUTTON_2("%",Mod)
BUTTON_2("e+",Exp10)
BUTTON_2("sin",Sin)
BUTTON_2("cos",Cos)
BUTTON_2("tan",Tan)
BUTTON_2("ln",Ln)
BUTTON_2("log",Log)
BUTTON_2("eigen",EigValues)
BUTTON_2("det",Det)
BUTTON_2("tr",Trace)
BUTTON_2("adj",Adjoint)
BUTTON_2("trans",Transpose)
BUTTON_3("×","*",Multiply)
BUTTON_3("÷","/",Divide)

void MainWindow::on_buttonPI_clicked()
{
    if(stream.empty())initialize();
    stream.emplace_back(doubleToString(PI));
    cursor.beginEditBlock();
    if(table->cellAt(0,position).firstPosition()!=table->cellAt(0,position).lastPosition()){
        table->appendColumns(1);
        table->cellAt(0,++position).setFormat(line);
    }
    cursor.insertText(QString::fromStdString("π"));
    table->appendColumns(1);
    table->cellAt(0,++position).setFormat(line);
    cursor.endEditBlock();
}


void MainWindow::on_buttonANS_clicked()
{
    if(stream.empty())initialize();
    if(ans_mat.size()>1&&ans_mat(0,0)!=0){
        includeMatrix=true;
        stream.emplace_back("MATRIX");
        matrix_list.emplace_back(ans_mat);
        input_matrix(ans_mat);
    }
    else{
        stream.emplace_back(doubleToString(ans_num));
        cursor.insertText(doubleToQString(ans_num));
    }
}


void MainWindow::on_buttonPow_clicked()
{
    if(stream.empty())initialize();
    //保存数据
    stream.emplace_back("pow");
    //显示数据
    cursor.beginEditBlock();
    if(table->cellAt(0,position).firstPosition()!=table->cellAt(0,position).lastPosition()){
        table->appendColumns(1);
        position++;
    }
    QTextTableCellFormat lineTop;
    lineTop.setVerticalAlignment(QTextCharFormat::AlignTop);
    lineTop.setFontPointSize(10);
    table->cellAt(0,position).setFormat(lineTop);
    cursor.endEditBlock();
}

void MainWindow::on_buttonSqrt_clicked()
{
    if(stream.empty())initialize();
    //保存数据
    stream.emplace_back("sqrt");
    //显示数据
    cursor.beginEditBlock();
    if(table->cellAt(0,position).firstPosition()!=table->cellAt(0,position).lastPosition()){
        table->appendColumns(1);
        table->cellAt(0,++position).setFormat(line);
    }
    QChar ch(0x221A);
    cursor.insertText(ch);
    table->appendColumns(1);
    table->cellAt(0,++position).setFormat(line);
    cursor.endEditBlock();
}

void MainWindow::on_buttonInverse_clicked(){
    if(stream.empty())initialize();
    //保存数据
    stream.emplace_back("inv");
    //显示数据
    cursor.beginEditBlock();
    table->appendColumns(1);
    QTextTableCellFormat lineTop;
    lineTop.setVerticalAlignment(QTextCharFormat::AlignTop);
    table->cellAt(0,++position).setFormat(lineTop);
    cursor.insertHtml("<sup>-1</sup>");
    table->appendColumns(1);
    table->cellAt(0,++position).setFormat(line);
    cursor.endEditBlock();
}

void MainWindow::on_buttonSet_clicked()
{
    if(stream.empty())initialize();
    int row=ui->spinBoxRow->value();
    int col=ui->spinBoxCol->value();
    //判断矩阵为空
    QTableWidgetItem *item=ui->tableWidget->item(0,0);
    if(item==NULL||(item&&item->text()=="")){
        //设置矩阵
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(row);
        ui->tableWidget->setColumnCount(col);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //平均分配列宽
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配行宽
    }
    else{       //保存矩阵
        includeMatrix=true;
        Eigen::MatrixXd matXd(row,col);
        for(int j=0;j<col;j++){
            for(int i=0;i<row;i++){
                if(ui->tableWidget->item(i,j)==NULL)matXd(i,j)=0;
                else matXd(i,j)=ui->tableWidget->item(i,j)->data(Qt::DisplayRole).toDouble();//取出字符串
            }
        }
    input_matrix(matXd);  //显示输入矩阵

    stream.emplace_back("MATRIX");
    matrix_list.emplace_back(matXd);
    ui->tableWidget->clear();
    }
}


void MainWindow::on_buttonEqual_clicked()
{
    if(stream.empty()) return;
    try {
        Calculator::getInstance().solve(stream);
        this->ui->textOutput->clear();
        if(!includeMatrix){
            ans_num=Calculator::getInstance().num_stack.top();
            ans_mat.setZero(1,1);
            ui->textOutput->setText(doubleToQString(ans_num));
            Calculator::getInstance().num_stack.pop();
        }
        else{            
            auto result=Calculator::getInstance().mat_stack.top();
            ans_mat=result;
            ans_num=0;
            Calculator::getInstance().mat_stack.pop();
            QTextCursor cursor_out=ui->textOutput->textCursor();
            //显示输出矩阵外框
            QTextTable *box=cursor_out.insertTable(1,1,tableFormat);
            box->cellAt(0,0).setFormat(cellFormat);
            //显示输出矩阵
            QTextTable *table_out=cursor_out.insertTable(result.rows(),result.cols(),tableFormat);
            for(int i=0;i<result.rows();i++){
                for(int j=0;j<result.cols();j++){
                    QTextTableCell cell=table_out->cellAt(i,j);
                    cell.firstCursorPosition().insertText(doubleToQString(result(i,j)));
                }
            }
        }
    }
    catch (string error) {
        ui->textOutput->setText(QString::fromStdString(error));
    }
    matrix_list.clear();
    stream.clear();
}

void MainWindow::on_buttonClear_clicked()
{
    initialize();
}

void MainWindow::on_buttonDelete_clicked()
{
    if(stream.empty()) initialize();
    ui->textInput->undo();
    position=table->columns()-1;
    if(!isNum(stream.back())){
        stream.pop_back();
    }
    else if(stream.back()=="MATRIX"){
        stream.pop_back();
    }
    else{
        stream.back()=stream.back().substr(0,stream.back().size()-1);
        if(stream.back()=="")stream.pop_back();
    }
    //ui->textOutput->setText(QString::fromStdString(stream.back()));
}


void MainWindow::on_buttonMatrix_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page2);
}

void MainWindow::on_buttonStandard_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page1);
}

void MainWindow::on_buttonMoveLeft_clicked()
{
    ui->textInput->setFocus();
    if(cursor.atBlockStart()){
        cursor.movePosition(QTextCursor::Left);
    }
    cursor.movePosition(QTextCursor::Left);
    if(cursor.atStart()){
        cursor.movePosition(QTextCursor::Right);
    }
    ui->textInput->setTextCursor(cursor);
    position=cursor.blockNumber()-1;
    //ui->textOutput->setText(QString::number(cursor.blockNumber()));
}


void MainWindow::on_buttonMoveRight_clicked()
{
    ui->textInput->setFocus();
    if(cursor.atBlockEnd()){
        cursor.movePosition(QTextCursor::Right);
    }
    cursor.movePosition(QTextCursor::Right);
    if(cursor.atEnd()){
        cursor.movePosition(QTextCursor::Left);
    }
    ui->textInput->setTextCursor(cursor);
    position=cursor.blockNumber()-1;
    //ui->textOutput->setText(QString::number(cursor.blockNumber()));
}



void MainWindow::on_buttonSolveEquation_clicked()
{

}

