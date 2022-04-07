#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<qtablewidget.h>
#include<QTextEdit>
#include<QKeyEvent>
#include<QString>
#include<string>
#include<Eigen/Dense>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_button0_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_buttonDot_clicked();

    void on_buttonEqual_clicked();
    void on_buttonANS_clicked();
    void on_buttonPlus_clicked();
    void on_buttonMinus_clicked();
    void on_buttonMultiply_clicked();
    void on_buttonDivide_clicked();
    void on_buttonClear_clicked();
    void on_buttonDelete_clicked();

    void on_buttonLeft_clicked();
    void on_buttonRight_clicked();
    void on_buttonExp10_clicked();
    void on_buttonSin_clicked();
    void on_buttonCos_clicked();
    void on_buttonTan_clicked();
    void on_buttonLn_clicked();
    void on_buttonLog_clicked();
    void on_buttonMod_clicked();
    void on_buttonMatrix_clicked();
    void on_buttonStandard_clicked();
    void on_buttonSet_clicked();
    void on_buttonEigValues_clicked();
    void on_buttonDet_clicked();
    void on_buttonPI_clicked();
    void on_buttonPow_clicked();
    void on_buttonInverse_clicked();
    void on_textInput_textChanged();
    void on_buttonMoveLeft_clicked();
    void on_buttonMoveRight_clicked();
    void on_buttonSqrt_clicked();
    void on_buttonTrace_clicked();
    void on_buttonAdjoint_clicked();
    void on_buttonTranspose_clicked();

private:
    void input(std::string s);
    void input_matrix(const Eigen::MatrixXd& m);
    void initialize();
    void saveData(std::string s);
    void displayData(std::string s);
private:
    QTextBlockFormat blockFormat;
    QTextTableFormat tableFormat;
    QTextTableCellFormat cellFormat,line;
    QTextTable *table;
    QTextCursor cursor;
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
