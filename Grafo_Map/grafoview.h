#ifndef GRAFOVIEW_H
#define GRAFOVIEW_H

#include <QMainWindow>
#include <QDebug>
#include "grafo.h"
#include "initialdialog.h"
#include "renderarea.h"
#include <QStringList>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include<QGraphicsLineItem>
#include<QGraphicsTextItem>
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
    int size;
    QList<QGraphicsEllipseItem*> nodos;
    QList<QGraphicsLineItem*> aristas;
    QHash<QString,QGraphicsTextItem*> pesos;
    QGraphicsScene *scene;
    void addArista(nodo n1, nodo n2, float p);
    void addNodo(QString ,int x, int y);
    void updateScene();
private slots:
    void on_UpdateEdit_clicked();
    void on_Dias_currentIndexChanged(QString );
    void on_Horas_currentIndexChanged(QString );
    void setSize(int s);
    void setListN(QStringList l);

};

#endif // GRAFOVIEW_H
