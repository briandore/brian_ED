#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <QMainWindow>
#include "calculator.h"
#include <QDebug>
#include <QHash>
#include <QTableWidget>
#include <QList>
namespace Ui {
    class MyCalculator;
}

class MyCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyCalculator(QWidget *parent = 0);
    ~MyCalculator();

private:
    Ui::MyCalculator *ui;
    void escribe(QString e);
    QHash<QChar,double> variables;
    QTableWidget *f;
    void updateVars();
    QString previewCheck(QString e);
private slots:
    void on_updateVrs_clicked();
    void on_btSolve1_clicked();
    void on_btFx_clicked();
    void on_btPower_clicked();
    void on_btDelete_clicked();
    void on_btClean_clicked();
    void on_btCos_clicked();
    void on_btSin_clicked();
    void on_btPar2_clicked();
    void on_btPar1_clicked();
    void on_btDivide_clicked();
    void on_btBy_clicked();
    void on_btMinus_clicked();
    void on_btPlus_clicked();
    void on_btDot_clicked();
    void on_bt0_clicked();
    void on_bt9_clicked();
    void on_bt8_clicked();
    void on_bt7_clicked();
    void on_bt6_clicked();
    void on_bt5_clicked();
    void on_bt4_clicked();
    void on_bt3_clicked();
    void on_bt2_clicked();
    void on_bt1_clicked();
};

#endif // MYCALCULATOR_H
