#ifndef PLOTTER_H
#define PLOTTER_H

#include <QDockWidget>
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QList>
#include <QPoint>
#include "calculator.h"
#include <ctime>
#include <QDebug>
namespace Ui {
    class Plotter;
}
struct punto{
    double x, y;
};


class Plotter : public QDockWidget
{
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = 0);
    ~Plotter();
    void graph(QStringList es, int xi = -50, int xf = 50);
    QList<QPoint> relative(QList<QPoint> p);
private:
    Ui::Plotter *ui;
    QGraphicsScene *scene ;
    double i,f;
    double mayor, menor;
    QString fx(QString e, double value);


};

#endif // PLOTTER_H
