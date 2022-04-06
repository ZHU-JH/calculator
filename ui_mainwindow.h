/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QTextBrowser *textOutput;
    QTextEdit *textInput;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QGridLayout *gridLayout;
    QPushButton *buttonInverse;
    QPushButton *buttonMoveLeft;
    QPushButton *buttonMod;
    QPushButton *buttonDivide;
    QPushButton *buttonMatrix;
    QPushButton *buttonPI;
    QPushButton *button4;
    QPushButton *button6;
    QPushButton *button5;
    QPushButton *buttonANS;
    QPushButton *buttonMoveRight;
    QPushButton *button9;
    QPushButton *button8;
    QPushButton *buttonEqual;
    QPushButton *buttonPow;
    QPushButton *buttonLeft;
    QPushButton *buttonMultiply;
    QPushButton *button7;
    QPushButton *buttonPlus;
    QPushButton *button2;
    QPushButton *buttonMinus;
    QPushButton *buttonDelete;
    QPushButton *button3;
    QPushButton *buttonClear;
    QPushButton *buttonRight;
    QPushButton *button1;
    QPushButton *button0;
    QPushButton *buttonExp10;
    QPushButton *buttonDot;
    QPushButton *buttonSqrt;
    QPushButton *buttonSin;
    QPushButton *buttonLn;
    QPushButton *buttonCos;
    QPushButton *buttonLog;
    QPushButton *buttonTan;
    QWidget *page2;
    QGridLayout *gridLayout_4;
    QPushButton *buttonLeft_;
    QPushButton *buttonInverse_;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSpinBox *spinBoxRow;
    QPushButton *buttonStandard;
    QPushButton *buttonDelete_;
    QPushButton *buttonMinus_;
    QPushButton *buttonEqual_;
    QPushButton *buttonPow_;
    QPushButton *buttonANS_;
    QPushButton *buttonRight_;
    QPushButton *buttonSet;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *spinBoxCol;
    QPushButton *buttonMultiply_;
    QPushButton *buttonDivide_;
    QPushButton *buttonPlus_;
    QPushButton *buttonClear_;
    QTableWidget *tableWidget;
    QPushButton *buttonEigValues;
    QPushButton *buttonAdjoint;
    QPushButton *buttonLog_5;
    QPushButton *buttonTranspose;
    QPushButton *buttonSolveEquation;
    QPushButton *buttonDet;
    QPushButton *buttonTrace;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(520, 738);
        MainWindow->setMaximumSize(QSize(5000, 9600));
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setFocusPolicy(Qt::StrongFocus);
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textOutput = new QTextBrowser(centralWidget);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));
        textOutput->setMinimumSize(QSize(250, 40));
        textOutput->setMaximumSize(QSize(5000, 150));

        gridLayout_5->addWidget(textOutput, 1, 0, 1, 1);

        textInput = new QTextEdit(centralWidget);
        textInput->setObjectName(QString::fromUtf8("textInput"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textInput->sizePolicy().hasHeightForWidth());
        textInput->setSizePolicy(sizePolicy);
        textInput->setMinimumSize(QSize(250, 40));
        textInput->setMaximumSize(QSize(5000, 150));
        textInput->setStyleSheet(QString::fromUtf8(""));
        textInput->setLineWrapMode(QTextEdit::NoWrap);

        gridLayout_5->addWidget(textInput, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setMinimumSize(QSize(250, 250));
        stackedWidget->setMaximumSize(QSize(2000, 2000));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        gridLayout = new QGridLayout(page1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonInverse = new QPushButton(page1);
        buttonInverse->setObjectName(QString::fromUtf8("buttonInverse"));
        sizePolicy.setHeightForWidth(buttonInverse->sizePolicy().hasHeightForWidth());
        buttonInverse->setSizePolicy(sizePolicy);
        buttonInverse->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonInverse, 1, 5, 1, 1);

        buttonMoveLeft = new QPushButton(page1);
        buttonMoveLeft->setObjectName(QString::fromUtf8("buttonMoveLeft"));
        sizePolicy.setHeightForWidth(buttonMoveLeft->sizePolicy().hasHeightForWidth());
        buttonMoveLeft->setSizePolicy(sizePolicy);
        buttonMoveLeft->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonMoveLeft, 2, 1, 1, 1);

        buttonMod = new QPushButton(page1);
        buttonMod->setObjectName(QString::fromUtf8("buttonMod"));
        sizePolicy.setHeightForWidth(buttonMod->sizePolicy().hasHeightForWidth());
        buttonMod->setSizePolicy(sizePolicy);
        buttonMod->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonMod, 2, 0, 1, 1);

        buttonDivide = new QPushButton(page1);
        buttonDivide->setObjectName(QString::fromUtf8("buttonDivide"));
        sizePolicy.setHeightForWidth(buttonDivide->sizePolicy().hasHeightForWidth());
        buttonDivide->setSizePolicy(sizePolicy);
        buttonDivide->setMaximumSize(QSize(200, 200));
        buttonDivide->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonDivide, 4, 7, 1, 1);

        buttonMatrix = new QPushButton(page1);
        buttonMatrix->setObjectName(QString::fromUtf8("buttonMatrix"));
        sizePolicy.setHeightForWidth(buttonMatrix->sizePolicy().hasHeightForWidth());
        buttonMatrix->setSizePolicy(sizePolicy);
        buttonMatrix->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonMatrix, 0, 0, 1, 1);

        buttonPI = new QPushButton(page1);
        buttonPI->setObjectName(QString::fromUtf8("buttonPI"));
        sizePolicy.setHeightForWidth(buttonPI->sizePolicy().hasHeightForWidth());
        buttonPI->setSizePolicy(sizePolicy);
        buttonPI->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonPI, 0, 1, 1, 1);

        button4 = new QPushButton(page1);
        button4->setObjectName(QString::fromUtf8("button4"));
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);
        button4->setMaximumSize(QSize(200, 200));
        button4->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button4, 4, 0, 1, 1);

        button6 = new QPushButton(page1);
        button6->setObjectName(QString::fromUtf8("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);
        button6->setMaximumSize(QSize(200, 200));
        button6->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button6, 4, 3, 1, 1);

        button5 = new QPushButton(page1);
        button5->setObjectName(QString::fromUtf8("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);
        button5->setMaximumSize(QSize(200, 200));
        button5->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button5, 4, 1, 1, 1);

        buttonANS = new QPushButton(page1);
        buttonANS->setObjectName(QString::fromUtf8("buttonANS"));
        sizePolicy.setHeightForWidth(buttonANS->sizePolicy().hasHeightForWidth());
        buttonANS->setSizePolicy(sizePolicy);
        buttonANS->setMaximumSize(QSize(200, 200));
        buttonANS->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonANS, 6, 5, 1, 1);

        buttonMoveRight = new QPushButton(page1);
        buttonMoveRight->setObjectName(QString::fromUtf8("buttonMoveRight"));
        sizePolicy.setHeightForWidth(buttonMoveRight->sizePolicy().hasHeightForWidth());
        buttonMoveRight->setSizePolicy(sizePolicy);
        buttonMoveRight->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonMoveRight, 2, 3, 1, 1);

        button9 = new QPushButton(page1);
        button9->setObjectName(QString::fromUtf8("button9"));
        sizePolicy.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy);
        button9->setMaximumSize(QSize(200, 200));
        button9->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button9, 3, 3, 1, 1);

        button8 = new QPushButton(page1);
        button8->setObjectName(QString::fromUtf8("button8"));
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);
        button8->setMaximumSize(QSize(200, 200));
        button8->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button8, 3, 1, 1, 1);

        buttonEqual = new QPushButton(page1);
        buttonEqual->setObjectName(QString::fromUtf8("buttonEqual"));
        sizePolicy.setHeightForWidth(buttonEqual->sizePolicy().hasHeightForWidth());
        buttonEqual->setSizePolicy(sizePolicy);
        buttonEqual->setMaximumSize(QSize(200, 200));
        buttonEqual->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonEqual, 6, 7, 1, 1);

        buttonPow = new QPushButton(page1);
        buttonPow->setObjectName(QString::fromUtf8("buttonPow"));
        sizePolicy.setHeightForWidth(buttonPow->sizePolicy().hasHeightForWidth());
        buttonPow->setSizePolicy(sizePolicy);
        buttonPow->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonPow, 1, 7, 1, 1);

        buttonLeft = new QPushButton(page1);
        buttonLeft->setObjectName(QString::fromUtf8("buttonLeft"));
        sizePolicy.setHeightForWidth(buttonLeft->sizePolicy().hasHeightForWidth());
        buttonLeft->setSizePolicy(sizePolicy);
        buttonLeft->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonLeft, 2, 5, 1, 1);

        buttonMultiply = new QPushButton(page1);
        buttonMultiply->setObjectName(QString::fromUtf8("buttonMultiply"));
        sizePolicy.setHeightForWidth(buttonMultiply->sizePolicy().hasHeightForWidth());
        buttonMultiply->setSizePolicy(sizePolicy);
        buttonMultiply->setMaximumSize(QSize(200, 200));
        buttonMultiply->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonMultiply, 4, 5, 1, 1);

        button7 = new QPushButton(page1);
        button7->setObjectName(QString::fromUtf8("button7"));
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);
        button7->setMaximumSize(QSize(200, 200));
        button7->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button7, 3, 0, 1, 1);

        buttonPlus = new QPushButton(page1);
        buttonPlus->setObjectName(QString::fromUtf8("buttonPlus"));
        sizePolicy.setHeightForWidth(buttonPlus->sizePolicy().hasHeightForWidth());
        buttonPlus->setSizePolicy(sizePolicy);
        buttonPlus->setMaximumSize(QSize(200, 200));
        buttonPlus->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonPlus, 5, 5, 1, 1);

        button2 = new QPushButton(page1);
        button2->setObjectName(QString::fromUtf8("button2"));
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);
        button2->setMaximumSize(QSize(200, 200));
        button2->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button2, 5, 1, 1, 1);

        buttonMinus = new QPushButton(page1);
        buttonMinus->setObjectName(QString::fromUtf8("buttonMinus"));
        sizePolicy.setHeightForWidth(buttonMinus->sizePolicy().hasHeightForWidth());
        buttonMinus->setSizePolicy(sizePolicy);
        buttonMinus->setMaximumSize(QSize(200, 200));
        buttonMinus->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonMinus, 5, 7, 1, 1);

        buttonDelete = new QPushButton(page1);
        buttonDelete->setObjectName(QString::fromUtf8("buttonDelete"));
        sizePolicy.setHeightForWidth(buttonDelete->sizePolicy().hasHeightForWidth());
        buttonDelete->setSizePolicy(sizePolicy);
        buttonDelete->setMaximumSize(QSize(200, 200));
        buttonDelete->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonDelete, 3, 5, 1, 1);

        button3 = new QPushButton(page1);
        button3->setObjectName(QString::fromUtf8("button3"));
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);
        button3->setMaximumSize(QSize(200, 200));
        button3->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button3, 5, 3, 1, 1);

        buttonClear = new QPushButton(page1);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        sizePolicy.setHeightForWidth(buttonClear->sizePolicy().hasHeightForWidth());
        buttonClear->setSizePolicy(sizePolicy);
        buttonClear->setMaximumSize(QSize(200, 200));
        buttonClear->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonClear, 3, 7, 1, 1);

        buttonRight = new QPushButton(page1);
        buttonRight->setObjectName(QString::fromUtf8("buttonRight"));
        sizePolicy.setHeightForWidth(buttonRight->sizePolicy().hasHeightForWidth());
        buttonRight->setSizePolicy(sizePolicy);
        buttonRight->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonRight, 2, 7, 1, 1);

        button1 = new QPushButton(page1);
        button1->setObjectName(QString::fromUtf8("button1"));
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);
        button1->setMaximumSize(QSize(200, 200));
        button1->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button1, 5, 0, 1, 1);

        button0 = new QPushButton(page1);
        button0->setObjectName(QString::fromUtf8("button0"));
        sizePolicy.setHeightForWidth(button0->sizePolicy().hasHeightForWidth());
        button0->setSizePolicy(sizePolicy);
        button0->setMaximumSize(QSize(200, 200));
        button0->setIconSize(QSize(80, 50));

        gridLayout->addWidget(button0, 6, 0, 1, 1);

        buttonExp10 = new QPushButton(page1);
        buttonExp10->setObjectName(QString::fromUtf8("buttonExp10"));
        sizePolicy.setHeightForWidth(buttonExp10->sizePolicy().hasHeightForWidth());
        buttonExp10->setSizePolicy(sizePolicy);
        buttonExp10->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonExp10, 6, 3, 1, 1);

        buttonDot = new QPushButton(page1);
        buttonDot->setObjectName(QString::fromUtf8("buttonDot"));
        sizePolicy.setHeightForWidth(buttonDot->sizePolicy().hasHeightForWidth());
        buttonDot->setSizePolicy(sizePolicy);
        buttonDot->setMaximumSize(QSize(200, 200));
        buttonDot->setIconSize(QSize(80, 50));

        gridLayout->addWidget(buttonDot, 6, 1, 1, 1);

        buttonSqrt = new QPushButton(page1);
        buttonSqrt->setObjectName(QString::fromUtf8("buttonSqrt"));
        sizePolicy.setHeightForWidth(buttonSqrt->sizePolicy().hasHeightForWidth());
        buttonSqrt->setSizePolicy(sizePolicy);
        buttonSqrt->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonSqrt, 1, 3, 1, 1);

        buttonSin = new QPushButton(page1);
        buttonSin->setObjectName(QString::fromUtf8("buttonSin"));
        sizePolicy.setHeightForWidth(buttonSin->sizePolicy().hasHeightForWidth());
        buttonSin->setSizePolicy(sizePolicy);
        buttonSin->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonSin, 0, 3, 1, 1);

        buttonLn = new QPushButton(page1);
        buttonLn->setObjectName(QString::fromUtf8("buttonLn"));
        sizePolicy.setHeightForWidth(buttonLn->sizePolicy().hasHeightForWidth());
        buttonLn->setSizePolicy(sizePolicy);
        buttonLn->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonLn, 1, 0, 1, 1);

        buttonCos = new QPushButton(page1);
        buttonCos->setObjectName(QString::fromUtf8("buttonCos"));
        sizePolicy.setHeightForWidth(buttonCos->sizePolicy().hasHeightForWidth());
        buttonCos->setSizePolicy(sizePolicy);
        buttonCos->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonCos, 0, 5, 1, 1);

        buttonLog = new QPushButton(page1);
        buttonLog->setObjectName(QString::fromUtf8("buttonLog"));
        sizePolicy.setHeightForWidth(buttonLog->sizePolicy().hasHeightForWidth());
        buttonLog->setSizePolicy(sizePolicy);
        buttonLog->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(buttonLog, 1, 1, 1, 1);

        buttonTan = new QPushButton(page1);
        buttonTan->setObjectName(QString::fromUtf8("buttonTan"));
        sizePolicy.setHeightForWidth(buttonTan->sizePolicy().hasHeightForWidth());
        buttonTan->setSizePolicy(sizePolicy);
        buttonTan->setMaximumSize(QSize(200, 200));
        buttonTan->setAutoDefault(false);
        buttonTan->setFlat(false);

        gridLayout->addWidget(buttonTan, 0, 7, 1, 1);

        stackedWidget->addWidget(page1);
        buttonDelete->raise();
        buttonClear->raise();
        buttonMultiply->raise();
        buttonDivide->raise();
        buttonPlus->raise();
        buttonMinus->raise();
        buttonANS->raise();
        buttonEqual->raise();
        button9->raise();
        button8->raise();
        button7->raise();
        button4->raise();
        button5->raise();
        button6->raise();
        button3->raise();
        button2->raise();
        button1->raise();
        button0->raise();
        buttonDot->raise();
        buttonExp10->raise();
        buttonLeft->raise();
        buttonMoveLeft->raise();
        buttonRight->raise();
        buttonMoveRight->raise();
        buttonMod->raise();
        buttonMatrix->raise();
        buttonPI->raise();
        buttonPow->raise();
        buttonInverse->raise();
        buttonSqrt->raise();
        buttonSin->raise();
        buttonLn->raise();
        buttonCos->raise();
        buttonLog->raise();
        buttonTan->raise();
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        gridLayout_4 = new QGridLayout(page2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        buttonLeft_ = new QPushButton(page2);
        buttonLeft_->setObjectName(QString::fromUtf8("buttonLeft_"));
        sizePolicy.setHeightForWidth(buttonLeft_->sizePolicy().hasHeightForWidth());
        buttonLeft_->setSizePolicy(sizePolicy);
        buttonLeft_->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonLeft_, 2, 6, 1, 1);

        buttonInverse_ = new QPushButton(page2);
        buttonInverse_->setObjectName(QString::fromUtf8("buttonInverse_"));
        sizePolicy.setHeightForWidth(buttonInverse_->sizePolicy().hasHeightForWidth());
        buttonInverse_->setSizePolicy(sizePolicy);
        buttonInverse_->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonInverse_, 1, 6, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(page2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        spinBoxRow = new QSpinBox(page2);
        spinBoxRow->setObjectName(QString::fromUtf8("spinBoxRow"));
        spinBoxRow->setMinimumSize(QSize(50, 30));

        horizontalLayout_6->addWidget(spinBoxRow);


        gridLayout_4->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        buttonStandard = new QPushButton(page2);
        buttonStandard->setObjectName(QString::fromUtf8("buttonStandard"));
        sizePolicy.setHeightForWidth(buttonStandard->sizePolicy().hasHeightForWidth());
        buttonStandard->setSizePolicy(sizePolicy);
        buttonStandard->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonStandard, 0, 0, 1, 1);

        buttonDelete_ = new QPushButton(page2);
        buttonDelete_->setObjectName(QString::fromUtf8("buttonDelete_"));
        sizePolicy.setHeightForWidth(buttonDelete_->sizePolicy().hasHeightForWidth());
        buttonDelete_->setSizePolicy(sizePolicy);
        buttonDelete_->setMaximumSize(QSize(200, 200));
        buttonDelete_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonDelete_, 3, 6, 1, 1);

        buttonMinus_ = new QPushButton(page2);
        buttonMinus_->setObjectName(QString::fromUtf8("buttonMinus_"));
        sizePolicy.setHeightForWidth(buttonMinus_->sizePolicy().hasHeightForWidth());
        buttonMinus_->setSizePolicy(sizePolicy);
        buttonMinus_->setMaximumSize(QSize(200, 200));
        buttonMinus_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonMinus_, 5, 7, 1, 1);

        buttonEqual_ = new QPushButton(page2);
        buttonEqual_->setObjectName(QString::fromUtf8("buttonEqual_"));
        sizePolicy.setHeightForWidth(buttonEqual_->sizePolicy().hasHeightForWidth());
        buttonEqual_->setSizePolicy(sizePolicy);
        buttonEqual_->setMaximumSize(QSize(200, 200));
        buttonEqual_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonEqual_, 6, 7, 1, 1);

        buttonPow_ = new QPushButton(page2);
        buttonPow_->setObjectName(QString::fromUtf8("buttonPow_"));
        sizePolicy.setHeightForWidth(buttonPow_->sizePolicy().hasHeightForWidth());
        buttonPow_->setSizePolicy(sizePolicy);
        buttonPow_->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonPow_, 1, 7, 1, 1);

        buttonANS_ = new QPushButton(page2);
        buttonANS_->setObjectName(QString::fromUtf8("buttonANS_"));
        sizePolicy.setHeightForWidth(buttonANS_->sizePolicy().hasHeightForWidth());
        buttonANS_->setSizePolicy(sizePolicy);
        buttonANS_->setMaximumSize(QSize(200, 200));
        buttonANS_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonANS_, 6, 6, 1, 1);

        buttonRight_ = new QPushButton(page2);
        buttonRight_->setObjectName(QString::fromUtf8("buttonRight_"));
        sizePolicy.setHeightForWidth(buttonRight_->sizePolicy().hasHeightForWidth());
        buttonRight_->setSizePolicy(sizePolicy);
        buttonRight_->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonRight_, 2, 7, 1, 1);

        buttonSet = new QPushButton(page2);
        buttonSet->setObjectName(QString::fromUtf8("buttonSet"));
        sizePolicy.setHeightForWidth(buttonSet->sizePolicy().hasHeightForWidth());
        buttonSet->setSizePolicy(sizePolicy);
        buttonSet->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonSet, 2, 4, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(page2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        spinBoxCol = new QSpinBox(page2);
        spinBoxCol->setObjectName(QString::fromUtf8("spinBoxCol"));
        spinBoxCol->setMinimumSize(QSize(50, 30));

        horizontalLayout_5->addWidget(spinBoxCol);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 2, 1, 1);

        buttonMultiply_ = new QPushButton(page2);
        buttonMultiply_->setObjectName(QString::fromUtf8("buttonMultiply_"));
        sizePolicy.setHeightForWidth(buttonMultiply_->sizePolicy().hasHeightForWidth());
        buttonMultiply_->setSizePolicy(sizePolicy);
        buttonMultiply_->setMaximumSize(QSize(200, 200));
        buttonMultiply_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonMultiply_, 4, 6, 1, 1);

        buttonDivide_ = new QPushButton(page2);
        buttonDivide_->setObjectName(QString::fromUtf8("buttonDivide_"));
        sizePolicy.setHeightForWidth(buttonDivide_->sizePolicy().hasHeightForWidth());
        buttonDivide_->setSizePolicy(sizePolicy);
        buttonDivide_->setMaximumSize(QSize(200, 200));
        buttonDivide_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonDivide_, 4, 7, 1, 1);

        buttonPlus_ = new QPushButton(page2);
        buttonPlus_->setObjectName(QString::fromUtf8("buttonPlus_"));
        sizePolicy.setHeightForWidth(buttonPlus_->sizePolicy().hasHeightForWidth());
        buttonPlus_->setSizePolicy(sizePolicy);
        buttonPlus_->setMaximumSize(QSize(200, 200));
        buttonPlus_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonPlus_, 5, 6, 1, 1);

        buttonClear_ = new QPushButton(page2);
        buttonClear_->setObjectName(QString::fromUtf8("buttonClear_"));
        sizePolicy.setHeightForWidth(buttonClear_->sizePolicy().hasHeightForWidth());
        buttonClear_->setSizePolicy(sizePolicy);
        buttonClear_->setMaximumSize(QSize(200, 200));
        buttonClear_->setIconSize(QSize(80, 50));

        gridLayout_4->addWidget(buttonClear_, 3, 7, 1, 1);

        tableWidget = new QTableWidget(page2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_4->addWidget(tableWidget, 3, 0, 4, 5);

        buttonEigValues = new QPushButton(page2);
        buttonEigValues->setObjectName(QString::fromUtf8("buttonEigValues"));
        sizePolicy.setHeightForWidth(buttonEigValues->sizePolicy().hasHeightForWidth());
        buttonEigValues->setSizePolicy(sizePolicy);
        buttonEigValues->setMaximumSize(QSize(200, 200));
        buttonEigValues->setAutoDefault(false);
        buttonEigValues->setFlat(false);

        gridLayout_4->addWidget(buttonEigValues, 1, 2, 1, 1);

        buttonAdjoint = new QPushButton(page2);
        buttonAdjoint->setObjectName(QString::fromUtf8("buttonAdjoint"));
        sizePolicy.setHeightForWidth(buttonAdjoint->sizePolicy().hasHeightForWidth());
        buttonAdjoint->setSizePolicy(sizePolicy);
        buttonAdjoint->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonAdjoint, 1, 0, 1, 1);

        buttonLog_5 = new QPushButton(page2);
        buttonLog_5->setObjectName(QString::fromUtf8("buttonLog_5"));
        sizePolicy.setHeightForWidth(buttonLog_5->sizePolicy().hasHeightForWidth());
        buttonLog_5->setSizePolicy(sizePolicy);
        buttonLog_5->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonLog_5, 0, 6, 1, 1);

        buttonTranspose = new QPushButton(page2);
        buttonTranspose->setObjectName(QString::fromUtf8("buttonTranspose"));
        sizePolicy.setHeightForWidth(buttonTranspose->sizePolicy().hasHeightForWidth());
        buttonTranspose->setSizePolicy(sizePolicy);
        buttonTranspose->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonTranspose, 0, 2, 1, 1);

        buttonSolveEquation = new QPushButton(page2);
        buttonSolveEquation->setObjectName(QString::fromUtf8("buttonSolveEquation"));
        sizePolicy.setHeightForWidth(buttonSolveEquation->sizePolicy().hasHeightForWidth());
        buttonSolveEquation->setSizePolicy(sizePolicy);
        buttonSolveEquation->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonSolveEquation, 0, 7, 1, 1);

        buttonDet = new QPushButton(page2);
        buttonDet->setObjectName(QString::fromUtf8("buttonDet"));
        sizePolicy.setHeightForWidth(buttonDet->sizePolicy().hasHeightForWidth());
        buttonDet->setSizePolicy(sizePolicy);
        buttonDet->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonDet, 1, 4, 1, 1);

        buttonTrace = new QPushButton(page2);
        buttonTrace->setObjectName(QString::fromUtf8("buttonTrace"));
        sizePolicy.setHeightForWidth(buttonTrace->sizePolicy().hasHeightForWidth());
        buttonTrace->setSizePolicy(sizePolicy);
        buttonTrace->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(buttonTrace, 0, 4, 1, 1);

        stackedWidget->addWidget(page2);
        buttonEqual_->raise();
        buttonClear_->raise();
        buttonANS_->raise();
        buttonDivide_->raise();
        buttonPlus_->raise();
        buttonMultiply_->raise();
        buttonDelete_->raise();
        buttonMinus_->raise();
        tableWidget->raise();
        buttonLeft_->raise();
        buttonRight_->raise();
        buttonStandard->raise();
        buttonSet->raise();
        buttonInverse_->raise();
        buttonPow_->raise();
        buttonEigValues->raise();
        buttonAdjoint->raise();
        buttonLog_5->raise();
        buttonTranspose->raise();
        buttonSolveEquation->raise();
        buttonDet->raise();
        buttonTrace->raise();

        gridLayout_5->addWidget(stackedWidget, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 520, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        buttonTan->setDefault(false);
        buttonEigValues->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonInverse->setText(QCoreApplication::translate("MainWindow", "  x\342\201\273\302\271", nullptr));
        buttonMoveLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        buttonMod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        buttonDivide->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        buttonMatrix->setText(QCoreApplication::translate("MainWindow", "MATRIX", nullptr));
        buttonPI->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
        button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        buttonANS->setText(QCoreApplication::translate("MainWindow", "Ans", nullptr));
        buttonMoveRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        buttonEqual->setText(QCoreApplication::translate("MainWindow", "\357\274\235", nullptr));
        buttonPow->setText(QCoreApplication::translate("MainWindow", "x\342\201\277", nullptr));
        buttonLeft->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        buttonMultiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        buttonPlus->setText(QCoreApplication::translate("MainWindow", "\357\274\213", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        buttonMinus->setText(QCoreApplication::translate("MainWindow", "\357\274\215", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        buttonClear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        buttonRight->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        buttonExp10->setText(QCoreApplication::translate("MainWindow", "\303\22710\342\201\277", nullptr));
        buttonDot->setText(QCoreApplication::translate("MainWindow", "\342\226\252", nullptr));
        buttonSqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232\357\277\243", nullptr));
        buttonSin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        buttonLn->setText(QCoreApplication::translate("MainWindow", "\343\217\221", nullptr));
        buttonCos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        buttonLog->setText(QCoreApplication::translate("MainWindow", "\343\217\222", nullptr));
        buttonTan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        buttonLeft_->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        buttonInverse_->setText(QCoreApplication::translate("MainWindow", "  x\342\201\273\302\271", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\241\214:", nullptr));
        buttonStandard->setText(QCoreApplication::translate("MainWindow", "Standard", nullptr));
        buttonDelete_->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        buttonMinus_->setText(QCoreApplication::translate("MainWindow", "\357\274\215", nullptr));
        buttonEqual_->setText(QCoreApplication::translate("MainWindow", "\357\274\235", nullptr));
        buttonPow_->setText(QCoreApplication::translate("MainWindow", "x\342\201\277", nullptr));
        buttonANS_->setText(QCoreApplication::translate("MainWindow", "Ans", nullptr));
        buttonRight_->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        buttonSet->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256/\344\277\235\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\210\227:", nullptr));
        buttonMultiply_->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        buttonDivide_->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        buttonPlus_->setText(QCoreApplication::translate("MainWindow", "\357\274\213", nullptr));
        buttonClear_->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        buttonEigValues->setText(QCoreApplication::translate("MainWindow", "eigen", nullptr));
        buttonAdjoint->setText(QCoreApplication::translate("MainWindow", "adj", nullptr));
        buttonLog_5->setText(QString());
        buttonTranspose->setText(QCoreApplication::translate("MainWindow", "trans", nullptr));
        buttonSolveEquation->setText(QString());
        buttonDet->setText(QCoreApplication::translate("MainWindow", "det", nullptr));
        buttonTrace->setText(QCoreApplication::translate("MainWindow", "tr", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
