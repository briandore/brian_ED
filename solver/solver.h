#ifndef SOLVER_H
#define SOLVER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include<QList>
#include <mylist.h>
namespace Ui {
    class solver;
}

class solver : public QMainWindow
{
    Q_OBJECT

public:
    explicit solver(QWidget *parent = 0);
    ~solver();
enum dir{Vertical,Horizontal};

private:
    Ui::solver *ui;
    QStringList list;
    QChar **sopa;
    MyList lista;
    void lookVerticals();
    void lookHorizontals();
    void lookDiagonal1();
    void lookDiagonal2();
    void lookUpwords(QString line,QString inverseline);

    void lookUpInHV(dir d);

    bool init;
    void liberar();
    int lenX, lenY;
    int cont;
    int readLen(int where, QString word);
    void crearArray();
    void imprimir();
private slots:
    void on_actionSolve_triggered();
    void on_actionLoad_Soup_triggered();
    void on_actionLoad_words_triggered();
};

#endif // SOLVER_H
