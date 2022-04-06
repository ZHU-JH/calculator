#include"mainwindow.h"
#include"ui_mainwindow.h"
#include"calculator.h"
#include"global.h"
#include"Factory.h"
#include<QShortcut>
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
    tableFormat.setBorder(0);
    //设置单元格格式
    line.setVerticalAlignment(QTextCharFormat::AlignMiddle);//居中单元格
    //矩阵单元格
    cellFormat.setLeftBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    cellFormat.setRightBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    cellFormat.setLeftBorder(1);
    cellFormat.setRightBorder(1);
    cellFormat.setPadding(2);
    initialize();

    ui->textInput->setAttribute(Qt::WA_InputMethodEnabled, false);
    this->grabKeyboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    ui->textInput->blockSignals(true);
    _pos=0;
    includeMatrix=0;
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

void MainWindow::saveData(std::string s){
    if(isNum(s)&&s.size()==1){//插入数字
        if(isNum(stream[_pos])) stream[_pos].insert(cursor.positionInBlock(),s);
        else if(_pos<stream.size()-1&&cursor.atBlockEnd()&&isNum(stream[_pos+1])){
            cursor.movePosition(QTextCursor::Right);
            _pos++;
            stream[_pos].insert(cursor.positionInBlock(),s);
        }
        else stream.insert(stream.begin()+_pos+1,s);
    }
    else{//插入符号或PI或MATRIX
        if(cursor.atBlockEnd()){
             stream.insert(stream.begin()+_pos+1,s);
        }
        else{
            string rOprand=stream[_pos].substr(cursor.positionInBlock(),stream[_pos].size()-cursor.positionInBlock());
            stream[_pos]=stream[_pos].substr(0,cursor.positionInBlock());
            stream.insert(stream.begin()+_pos+1,rOprand);
            stream.insert(stream.begin()+_pos+1,s);

        }
        if(!isNum(s)){
            auto ptr=Factory::create(s);
             //单目运算符且有右操作数则补全（
             if(ptr->numOprand==1&&ptr->haveRightOprand){
                 stream.insert(stream.begin()+_pos+2,"(");
             }
        }
    }
}

void MainWindow::displayData(std::string s_displayed,string s){
    if(isNum(s)&&s.size()==1){//显示数字
        if(!isNum(stream[_pos])){
            _pos++;
            table->insertColumns(_pos,1);
            table->cellAt(0,_pos).setFormat(line);
        }
        cursor.insertText(QString::fromStdString(s_displayed));
    }
    else{//显示符号
        if(cursor.atBlockEnd()){
            _pos++;
            table->insertColumns(_pos,1);
            table->cellAt(0,_pos).setFormat(line);
        }
        else{
            cursor.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
            QString qs=cursor.selectedText();
            cursor.removeSelectedText();
            _pos++;
            table->insertColumns(_pos,1);
            table->cellAt(0,_pos).setFormat(line);
            cursor.insertText(qs);
            table->insertColumns(_pos,1);
            table->cellAt(0,_pos).setFormat(line);
            cursor=table->cellAt(0,_pos).firstCursorPosition();
        }
        cursor.insertText(QString::fromStdString(s_displayed));
        if(!isNum(s)){
            auto ptr=Factory::create(s);
            //单目运算符且有右操作数则补全（
            if(ptr->numOprand==1&&ptr->haveRightOprand){
                _pos++;
                table->insertColumns(_pos,1);
                table->cellAt(0,_pos).setFormat(line);
                cursor.insertText(QString::fromStdString("("));
            }
        }
    }
}

void MainWindow::input(string s_displayed,string s){
    if(stream.empty())initialize();
    saveData(s);        //保存数据
    displayData(s_displayed,s);    //显示数据
}

void MainWindow::input_matrix(const Eigen::MatrixXd& m)
{
    int row=m.rows();
    int col=m.cols();
    _pos++;
    table->insertColumns(_pos,1);
    table->cellAt(0,_pos).setFormat(cellFormat);
    //嵌套表格
    QTextTable *subtable=cursor.insertTable(row,col,tableFormat);
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            subtable->cellAt(i,j).firstCursorPosition().insertText(doubleToQString(m(i,j)));
        }
    }
    cursor=table->cellAt(0,_pos).lastCursorPosition();
    //cursor=table->lastCursorPosition();
    ui->textInput->setTextCursor(cursor);
}

void MainWindow::on_textInput_textChanged()
{
    int p=cursor.blockNumber()-1;
    QTextCursor tmp=table->cellAt(0,p).firstCursorPosition();
    tmp.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
    string changedText=tmp.selectedText().toStdString();
    if(stream[p]!=changedText) stream[p]=changedText;
    ui->textInput->setFocus();
    ui->textInput->setTextCursor(cursor);
}
/******************************************************************************************/
//按键槽函数
#define BUTTON_3(S_DISPLAYED,S_ACTUAL,S_NAME) void MainWindow::on_button##S_NAME##_clicked(){input(S_DISPLAYED,S_ACTUAL);}
#define BUTTON_2(S_DISPLAYED,S_NAME)          BUTTON_3(S_DISPLAYED,S_DISPLAYED,S_NAME)
#define BUTTON_1(NUM)                         BUTTON_3(#NUM,#NUM,NUM)

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
BUTTON_2("×",Multiply)
BUTTON_2("÷",Divide)
BUTTON_3(QString(QChar(0x221A)).toStdString(),"sqrt",Sqrt)


void MainWindow::on_buttonPI_clicked()
{
    if(stream.empty())initialize();
    saveData(doubleToString(PI));
    displayData(doubleToString(PI),doubleToString(PI));
}

void MainWindow::on_buttonANS_clicked()
{
    if(stream.empty())initialize();
    saveData("ANS");
    displayData("ANS","ANS");
    if(ans_mat.size()==1&&ans_mat(0,0)==0) return;
    includeMatrix++;
}


void MainWindow::on_buttonPow_clicked()
{
    if(stream.empty())initialize();
    saveData("pow");
    _pos++;
    table->insertColumns(_pos,1);
    table->cellAt(0,_pos).setFormat(line);
    QTextTableCellFormat lineTop;
    lineTop.setVerticalAlignment(QTextCharFormat::AlignTop);
    lineTop.setFontPointSize(10);
    table->cellAt(0,_pos).setFormat(lineTop);
    if(cursor.atBlockEnd()){
        _pos++;
        table->insertColumns(_pos,1);
        table->cellAt(0,_pos).setFormat(lineTop);
    }
    else{
        cursor.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
        QString qs=cursor.selectedText();
        cursor.removeSelectedText();
        _pos++;
        table->insertColumns(_pos,1);
        table->cellAt(0,_pos).setFormat(line);
        cursor.insertText(qs);
        table->insertColumns(_pos,1);
        table->cellAt(0,_pos).setFormat(lineTop);
        cursor=table->cellAt(0,_pos).firstCursorPosition();
        ui->textInput->setTextCursor(cursor);
    }
    stream.insert(stream.begin()+_pos,"");
}


void MainWindow::on_buttonInverse_clicked(){
    if(stream.empty())initialize();
    saveData("inv");
    QTextTableCellFormat lineTop;
    lineTop.setVerticalAlignment(QTextCharFormat::AlignTop);
    if(cursor.atBlockEnd()){
        _pos++;
        table->insertColumns(_pos,1);
        table->cellAt(0,_pos).setFormat(lineTop);
    }
    else{
        cursor.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
        QString qs=cursor.selectedText();
        cursor.removeSelectedText();
        _pos++;
        table->insertColumns(_pos,1);
        table->cellAt(0,_pos).setFormat(line);
        cursor.insertText(qs);
        table->insertColumns(_pos,1);
        table->cellAt(0,_pos).setFormat(lineTop);
        cursor=table->cellAt(0,_pos).firstCursorPosition();
    }
    cursor.insertHtml("<sup>-1</sup>");
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
        includeMatrix++;
        //if(stream[_pos]=="") stream[_pos]="MATRIX";
        stream.insert(stream.begin()+_pos+1,"MATRIX");

        Eigen::MatrixXd matXd(row,col);
        for(int j=0;j<col;j++){
            for(int i=0;i<row;i++){
                if(ui->tableWidget->item(i,j)==NULL)matXd(i,j)=0;
                else matXd(i,j)=ui->tableWidget->item(i,j)->data(Qt::DisplayRole).toDouble();//取出字符串
            }
        }
    input_matrix(matXd);  //显示输入矩阵
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
    ui->textInput->setFocus();
    if(_pos==0&&cursor.atBlockStart()) return;
    if(!isNum(stream[_pos])){//删除运算符
        stream.erase(stream.begin()+_pos);
        table->removeColumns(_pos,1);
        _pos--;
    }
    else{//删除数字
        stream[_pos].erase(stream[_pos].begin()+cursor.positionInBlock()-1);
        cursor.deletePreviousChar();
        if(_pos!=0&&cursor.atBlockStart()){
            cursor.movePosition(QTextCursor::Left);
            ui->textInput->setTextCursor(cursor);
            if(stream[_pos]==""){
                table->removeColumns(_pos,1);
                stream.erase(stream.begin()+_pos);
            }
            _pos--;
        }
    }
    //合并数字
    if(_pos<stream.size()-1&&isNum(stream[_pos])&&isNum(stream[_pos+1])){
        stream[_pos]+=stream[_pos+1];
        int position=cursor.position();
        cursor.insertText(QString::fromStdString(stream[_pos+1]));
        cursor.setPosition(position);
        stream.erase(stream.begin()+_pos+1);
        table->removeColumns(_pos+1,1);
    }
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
    if(stream.empty())initialize();
    ui->textInput->setFocus();
    if(isNum(stream[_pos]))cursor.movePosition(QTextCursor::Left);
    else{
        cursor.movePosition(QTextCursor::WordLeft);
        cursor.movePosition(QTextCursor::Left);
        _pos--;
    }
    if(cursor.atBlockStart()){
        _pos--;
        cursor.movePosition(QTextCursor::Left);
    }
    if(cursor.atStart()){//越界处理
        _pos++;
        cursor.movePosition(QTextCursor::Right);
    }
    ui->textInput->setTextCursor(cursor);
    //ui->textOutput->setText(QString::number(_pos));
    ui->textOutput->setText(QString::fromStdString(stream[_pos]));
}


void MainWindow::on_buttonMoveRight_clicked()
{
    if(stream.empty())initialize();
    ui->textInput->setFocus();
    cursor.movePosition(QTextCursor::Right);
    if(_pos<stream.size()-1&&cursor.atBlockStart()&&!isNum(stream[_pos+1])){
        _pos++;
        cursor.movePosition(QTextCursor::WordRight);
    }
    if(cursor.atBlockStart()){
        _pos++;
        cursor.movePosition(QTextCursor::Right);
    }
    if(cursor.atEnd()){
        _pos--;
        cursor.movePosition(QTextCursor::Left);
    }
    ui->textInput->setTextCursor(cursor);
    //ui->textOutput->setText(QString::number(_pos));
    ui->textOutput->setText(QString::fromStdString(stream[_pos]));
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_1:
            on_button1_clicked();
            break;
        case Qt::Key_2:
            on_button2_clicked();
            break;
        case Qt::Key_3:
            on_button3_clicked();
            break;
        case Qt::Key_4:
            on_button4_clicked();
            break;
        case Qt::Key_5:
            on_button5_clicked();
            break;
        case Qt::Key_6:
             on_button6_clicked();
             break;
        case Qt::Key_7:
            on_button7_clicked();
            break;
        case Qt::Key_8:
            on_button8_clicked();
            break;
        case Qt::Key_9:
             on_button9_clicked();
             break;
        case Qt::Key_0:
            on_button0_clicked();
            break;
        case Qt::Key_Left:
            on_buttonMoveLeft_clicked();
            break;
        case Qt::Key_Right:
            on_buttonMoveRight_clicked();
            break;
        case Qt::Key_Plus:
            on_buttonPlus_clicked();
            break;
        case Qt::Key_Asterisk:
            on_buttonMultiply_clicked();
            break;
        case Qt::Key_Slash:
            on_buttonDivide_clicked();
            break;
        case Qt::Key_Period:
             on_buttonDot_clicked();
             break;
        case Qt::Key_Percent:
            on_buttonMod_clicked();
            break;
        case Qt::Key_ParenLeft:
            on_buttonLeft_clicked();
            break;
        case Qt::Key_ParenRight:
             on_buttonRight_clicked();
             break;
        case Qt::Key_Backspace:
            on_buttonDelete_clicked();
            break;

        case Qt::Key_Minus:
            on_buttonMinus_clicked();
            break;
        case Qt::Key_Equal:
            on_buttonEqual_clicked();
            break;
       default:
           break;
       }
        ui->textInput->setFocus();
}

