/********************************************************************************
** Form generated from reading UI file 'mycalculator.ui'
**
** Created: Sun May 29 20:56:30 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCALCULATOR_H
#define UI_MYCALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCalculator
{
public:
    QWidget *centralWidget;
    QPushButton *bt1;
    QPushButton *bt2;
    QPushButton *bt3;
    QPushButton *bt5;
    QPushButton *bt4;
    QPushButton *bt6;
    QPushButton *bt8;
    QPushButton *bt7;
    QPushButton *bt9;
    QPushButton *bt0;
    QPushButton *btDot;
    QLineEdit *expresion;
    QPushButton *btBy;
    QPushButton *btPlus;
    QPushButton *btDivide;
    QPushButton *btMinus;
    QPushButton *btPar1;
    QPushButton *btSin;
    QPushButton *btPar2;
    QPushButton *btCos;
    QPushButton *btClean;
    QPushButton *btFx;
    QPushButton *btDelete;
    QPushButton *btPower;
    QPushButton *btSolve2;
    QPushButton *btSolve1;
    QToolBox *toolBox;
    QWidget *page;
    QLabel *label;
    QLabel *label_2;
    QListWidget *variables;
    QLineEdit *var;
    QLineEdit *value;
    QLabel *label_3;
    QPushButton *updateVrs;
    QWidget *page_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyCalculator)
    {
        if (MyCalculator->objectName().isEmpty())
            MyCalculator->setObjectName(QString::fromUtf8("MyCalculator"));
        MyCalculator->resize(460, 337);
        centralWidget = new QWidget(MyCalculator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bt1 = new QPushButton(centralWidget);
        bt1->setObjectName(QString::fromUtf8("bt1"));
        bt1->setGeometry(QRect(20, 60, 41, 41));
        bt2 = new QPushButton(centralWidget);
        bt2->setObjectName(QString::fromUtf8("bt2"));
        bt2->setGeometry(QRect(70, 60, 41, 41));
        bt3 = new QPushButton(centralWidget);
        bt3->setObjectName(QString::fromUtf8("bt3"));
        bt3->setGeometry(QRect(120, 60, 41, 41));
        bt5 = new QPushButton(centralWidget);
        bt5->setObjectName(QString::fromUtf8("bt5"));
        bt5->setGeometry(QRect(70, 100, 41, 41));
        bt4 = new QPushButton(centralWidget);
        bt4->setObjectName(QString::fromUtf8("bt4"));
        bt4->setGeometry(QRect(20, 100, 41, 41));
        bt6 = new QPushButton(centralWidget);
        bt6->setObjectName(QString::fromUtf8("bt6"));
        bt6->setGeometry(QRect(120, 100, 41, 41));
        bt8 = new QPushButton(centralWidget);
        bt8->setObjectName(QString::fromUtf8("bt8"));
        bt8->setGeometry(QRect(70, 140, 41, 41));
        bt7 = new QPushButton(centralWidget);
        bt7->setObjectName(QString::fromUtf8("bt7"));
        bt7->setGeometry(QRect(20, 140, 41, 41));
        bt9 = new QPushButton(centralWidget);
        bt9->setObjectName(QString::fromUtf8("bt9"));
        bt9->setGeometry(QRect(120, 140, 41, 41));
        bt0 = new QPushButton(centralWidget);
        bt0->setObjectName(QString::fromUtf8("bt0"));
        bt0->setGeometry(QRect(20, 180, 91, 41));
        btDot = new QPushButton(centralWidget);
        btDot->setObjectName(QString::fromUtf8("btDot"));
        btDot->setGeometry(QRect(120, 180, 41, 41));
        expresion = new QLineEdit(centralWidget);
        expresion->setObjectName(QString::fromUtf8("expresion"));
        expresion->setGeometry(QRect(20, 12, 241, 41));
        btBy = new QPushButton(centralWidget);
        btBy->setObjectName(QString::fromUtf8("btBy"));
        btBy->setGeometry(QRect(170, 140, 41, 41));
        btPlus = new QPushButton(centralWidget);
        btPlus->setObjectName(QString::fromUtf8("btPlus"));
        btPlus->setGeometry(QRect(170, 60, 41, 41));
        btDivide = new QPushButton(centralWidget);
        btDivide->setObjectName(QString::fromUtf8("btDivide"));
        btDivide->setGeometry(QRect(170, 180, 41, 41));
        btMinus = new QPushButton(centralWidget);
        btMinus->setObjectName(QString::fromUtf8("btMinus"));
        btMinus->setGeometry(QRect(170, 100, 41, 41));
        btPar1 = new QPushButton(centralWidget);
        btPar1->setObjectName(QString::fromUtf8("btPar1"));
        btPar1->setGeometry(QRect(220, 60, 41, 41));
        btSin = new QPushButton(centralWidget);
        btSin->setObjectName(QString::fromUtf8("btSin"));
        btSin->setGeometry(QRect(220, 140, 41, 41));
        btPar2 = new QPushButton(centralWidget);
        btPar2->setObjectName(QString::fromUtf8("btPar2"));
        btPar2->setGeometry(QRect(220, 100, 41, 41));
        btCos = new QPushButton(centralWidget);
        btCos->setObjectName(QString::fromUtf8("btCos"));
        btCos->setGeometry(QRect(220, 180, 41, 41));
        btClean = new QPushButton(centralWidget);
        btClean->setObjectName(QString::fromUtf8("btClean"));
        btClean->setGeometry(QRect(270, 60, 41, 41));
        btFx = new QPushButton(centralWidget);
        btFx->setObjectName(QString::fromUtf8("btFx"));
        btFx->setGeometry(QRect(270, 180, 41, 41));
        btDelete = new QPushButton(centralWidget);
        btDelete->setObjectName(QString::fromUtf8("btDelete"));
        btDelete->setGeometry(QRect(270, 100, 41, 41));
        btPower = new QPushButton(centralWidget);
        btPower->setObjectName(QString::fromUtf8("btPower"));
        btPower->setGeometry(QRect(270, 140, 41, 41));
        btSolve2 = new QPushButton(centralWidget);
        btSolve2->setObjectName(QString::fromUtf8("btSolve2"));
        btSolve2->setGeometry(QRect(20, 220, 291, 31));
        btSolve1 = new QPushButton(centralWidget);
        btSolve1->setObjectName(QString::fromUtf8("btSolve1"));
        btSolve1->setGeometry(QRect(270, 10, 41, 41));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(320, 0, 131, 261));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 121, 197));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 0, 61, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 140, 51, 16));
        label_2->setFont(font);
        variables = new QListWidget(page);
        variables->setObjectName(QString::fromUtf8("variables"));
        variables->setGeometry(QRect(0, 20, 121, 121));
        var = new QLineEdit(page);
        var->setObjectName(QString::fromUtf8("var"));
        var->setGeometry(QRect(0, 160, 41, 31));
        var->setMaxLength(1);
        value = new QLineEdit(page);
        value->setObjectName(QString::fromUtf8("value"));
        value->setGeometry(QRect(50, 160, 41, 31));
        value->setMaxLength(20);
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 140, 41, 16));
        label_3->setFont(font);
        updateVrs = new QPushButton(page);
        updateVrs->setObjectName(QString::fromUtf8("updateVrs"));
        updateVrs->setGeometry(QRect(90, 160, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICONS/REFRESH.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateVrs->setIcon(icon);
        updateVrs->setIconSize(QSize(20, 20));
        toolBox->addItem(page, QString::fromUtf8("Variables"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 121, 197));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        MyCalculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyCalculator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 460, 21));
        MyCalculator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyCalculator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyCalculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyCalculator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyCalculator->setStatusBar(statusBar);

        retranslateUi(MyCalculator);
        QObject::connect(btSolve2, SIGNAL(clicked()), btSolve1, SLOT(click()));

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyCalculator);
    } // setupUi

    void retranslateUi(QMainWindow *MyCalculator)
    {
        MyCalculator->setWindowTitle(QApplication::translate("MyCalculator", "MyCalculator", 0, QApplication::UnicodeUTF8));
        bt1->setText(QApplication::translate("MyCalculator", "1", 0, QApplication::UnicodeUTF8));
        bt2->setText(QApplication::translate("MyCalculator", "2", 0, QApplication::UnicodeUTF8));
        bt3->setText(QApplication::translate("MyCalculator", "3", 0, QApplication::UnicodeUTF8));
        bt5->setText(QApplication::translate("MyCalculator", "5", 0, QApplication::UnicodeUTF8));
        bt4->setText(QApplication::translate("MyCalculator", "4", 0, QApplication::UnicodeUTF8));
        bt6->setText(QApplication::translate("MyCalculator", "6", 0, QApplication::UnicodeUTF8));
        bt8->setText(QApplication::translate("MyCalculator", "8", 0, QApplication::UnicodeUTF8));
        bt7->setText(QApplication::translate("MyCalculator", "7", 0, QApplication::UnicodeUTF8));
        bt9->setText(QApplication::translate("MyCalculator", "9", 0, QApplication::UnicodeUTF8));
        bt0->setText(QApplication::translate("MyCalculator", "0", 0, QApplication::UnicodeUTF8));
        btDot->setText(QApplication::translate("MyCalculator", ".", 0, QApplication::UnicodeUTF8));
        btBy->setText(QApplication::translate("MyCalculator", "*", 0, QApplication::UnicodeUTF8));
        btPlus->setText(QApplication::translate("MyCalculator", "+", 0, QApplication::UnicodeUTF8));
        btDivide->setText(QApplication::translate("MyCalculator", "/", 0, QApplication::UnicodeUTF8));
        btMinus->setText(QApplication::translate("MyCalculator", "-", 0, QApplication::UnicodeUTF8));
        btPar1->setText(QApplication::translate("MyCalculator", "(", 0, QApplication::UnicodeUTF8));
        btSin->setText(QApplication::translate("MyCalculator", "sin", 0, QApplication::UnicodeUTF8));
        btPar2->setText(QApplication::translate("MyCalculator", ")", 0, QApplication::UnicodeUTF8));
        btCos->setText(QApplication::translate("MyCalculator", "cos", 0, QApplication::UnicodeUTF8));
        btClean->setText(QApplication::translate("MyCalculator", "C", 0, QApplication::UnicodeUTF8));
        btFx->setText(QApplication::translate("MyCalculator", "f(x)", 0, QApplication::UnicodeUTF8));
        btDelete->setText(QApplication::translate("MyCalculator", "DEL", 0, QApplication::UnicodeUTF8));
        btPower->setText(QApplication::translate("MyCalculator", "^", 0, QApplication::UnicodeUTF8));
        btSolve2->setText(QApplication::translate("MyCalculator", "=", 0, QApplication::UnicodeUTF8));
        btSolve1->setText(QApplication::translate("MyCalculator", "SOLVE", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MyCalculator", "Variables", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MyCalculator", "Variable", 0, QApplication::UnicodeUTF8));
        var->setInputMask(QApplication::translate("MyCalculator", "A; ", 0, QApplication::UnicodeUTF8));
        value->setInputMask(QString());
        label_3->setText(QApplication::translate("MyCalculator", "Valor", 0, QApplication::UnicodeUTF8));
        updateVrs->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MyCalculator", "Variables", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MyCalculator", "Page 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyCalculator: public Ui_MyCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCALCULATOR_H
