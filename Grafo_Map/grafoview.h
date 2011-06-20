#ifndef GRAFOVIEW_H
#define GRAFOVIEW_H

#include <QMainWindow>
#include <QDebug>
#include "grafo.h"
#include "initialdialog.h"
#include "renderarea.h"
#include <QStringList>
#include <QMap>
#include <QVector>
#include <QMessageBox>
namespace Ui {
    class GrafoView;
}

class GrafoView : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrafoView(QWidget *parent = 0);
    ~GrafoView();

private:
    Ui::GrafoView *ui;
    Grafo *mygrafo;
    RenderArea * rArea;
    QStringList L;
    int **routes;
    int size;
    float **table;

    void floyd();
    void addArista(nodo n1, nodo n2, float p);
    void addNodo(QString ,int x, int y);
    void updateScene();
    QString camino(int i, int f);
     QStringList DAYS;
private slots:
    void on_actionHelp_triggered();
    void on_actionAbout_triggered();
    void on_addDay_clicked();
    void on_btRutaCortes_clicked();
    void on_floyd_clicked();
    void on_EditXY_clicked();
    void on_btBorrar_clicked();
    void on_UpdateEdit_clicked();
    void on_Dias_currentIndexChanged(QString );
    void on_Horas_currentIndexChanged(QString );
    void setSize(int s);
    void setListN(QStringList l);

};

#endif // GRAFOVIEW_H
