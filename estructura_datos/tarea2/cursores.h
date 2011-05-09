#ifndef CURSORES_H
#define CURSORES_H

#include <QMainWindow>
#include "lista.h"
#include "sizedialog.h"
#include "QDebug"
#include "math.h"
#include <QList>
namespace Ui {
    class cursores;
}

class cursores : public QMainWindow
{
    Q_OBJECT

public:
    explicit cursores(QWidget *parent = 0);
    ~cursores();

private:
    Ui::cursores *ui;
    lista *myList;
    bool verificar();
    QList<int> binarios;
    QList<QChar>operadores;
    int numberToBinary(int number, int power);
    void toBinary(int number, int power);
    QString BinariosToString();
    void plusOne(int len);
    void minusOne(int len);
    void updateData();
    void mathMethod();
    void opMayor(QChar x1, QChar x2);
private slots:
    void on_actionSuprimirCorregido_triggered();
    void on_actionSuprimirLibro_triggered();
    void on_pushButton_6_clicked();
    void on_btPlus_clicked();
    void on_btSetNumber_clicked();
    void on_byPos_stateChanged(int );

    void on_actionLookup_triggered();
    void on_actionDelete_triggered();
    void on_btAdd_clicked();

    void inicializarLista(int);


};

#endif // CURSORES_H
