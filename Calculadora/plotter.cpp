#include "plotter.h"
#include "ui_plotter.h"

Plotter::Plotter(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Plotter)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,600,600);
    this->ui->graph->setScene(scene);
  srand(0);
  //  scene->addEllipse(0,0,10,10);
}

Plotter::~Plotter()
{
    this->scene->clear();
    delete ui;
}

void Plotter::graph(QStringList e, int xi, int xf){
    i = xi; f = xf;
    punto coord;
    calculator c;
    this->ui->graph->scene()->clear();
    QList< QList<punto> > points;
    QList<punto> temp;
    mayor = -1000000000, menor = 1000000000;

    foreach(QString f, e)
    {
        temp.clear();
        for(long double i = xi; i<= xf;i += ((xf-xi)/(this->scene->width()+0.0))){
            coord.x = (i);
            coord.y =(c.solve(fx(f,i)));

           if(coord.y != INFINITY)
                temp.append(coord);
        }

        foreach(punto p, temp){
            if(p.y < menor)
                menor = p.y;
            else if( p.y > mayor)
                mayor = p.y;

        }
      points.append(temp);

    }

    QColor color;

    for(int i = 0; i< points.count();i++){
    //foreach(QList<punto> pts, points){
        //pts = relative(pts);
        int r = rand()%255;
        int g = rand()%255;
        int b = rand()%255;
        color = QColor::fromRgb(r,g,b);
       // color = Qt::blue;

        foreach(punto po, points[i]){
         //   po.setX((po.x()- this->i)/this->scene->height());
       //     po.setY((po.y()- this->menor)/this->scene->width());
            qDebug()<<((po.x- this->i)*this->scene->width()*0.5/xf)<<"x";
          //  qDebug()<<po.x<<"y:"<<po.y<<"mayor"<<mayor<<"min:"<<menor;
            qDebug()<<(this->scene->height() - (po.y - this->menor)*300/mayor)<<"y";
            this->scene->addEllipse(((po.x- this->i)*this->scene->width()*.5/xf),(this->scene->height() - (po.y - this->menor)*this->scene->height()*.5/mayor),1,1,QPen( color),QBrush(color));
        }
    }
    double o = -this->i*this->scene->width()*.5/xf;
    this->scene->addLine(o,0,o,this->scene->height());
    o = this->scene->height() + this->menor*this->height()*.5/mayor;
    this->scene->addLine(0,o,this->scene->width(),o);


}

QList<QPoint> Plotter::relative(QList<QPoint> pts){
    foreach(QPoint p, pts){
        p.setX((p.x()- this->i)/this->scene->height());
        p.setY((p.y()- this->menor)/this->scene->width());
    }

    return pts;
}

QString Plotter::fx(QString e, double value){
   // qDebug()<<value;
    e.replace("x",QString::number(value),Qt::CaseInsensitive);
  //  qDebug()<<e;
    return e;
}
