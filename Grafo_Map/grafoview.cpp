#include "grafoview.h"
#include "ui_grafoview.h"

GrafoView::GrafoView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GrafoView)
{

    mygrafo = 0;

    ui->setupUi(this);

    for(int i = 0; i < 24; i++){
        this->ui->Horas->addItem(QString::number(i).append("hrs"));
    }

    int size = 5;
       InitialDialog *d = new InitialDialog(this);
       d->show();
       connect(d,SIGNAL(size(int)),this,SLOT(setSize(int)));
       connect(d,SIGNAL(list(QStringList)),this,SLOT(setListN(QStringList)));
       scene = new QGraphicsScene(0,0,400,400);
this->ui->view->setScene(scene);
QGraphicsLineItem * arista = new QGraphicsLineItem(30,30,200,200);
this->scene->addItem(arista);
this->aristas.append(arista);

}

GrafoView::~GrafoView()
{
    delete ui;
}

void GrafoView::on_Horas_currentIndexChanged(QString e)
{
   e.remove("hrs");
  if(mygrafo != 0)
     mygrafo->setHour(e.toInt());
  updateScene();
}

void GrafoView::on_Dias_currentIndexChanged(QString d)
{
   if(this->mygrafo != 0)
    this->mygrafo->setDay(d);
}

void GrafoView::on_UpdateEdit_clicked()
{
    this->scene->removeItem(this->aristas.at(0));
   QString i = this->ui->nodoI->text().trimmed().toUpper();
   QString f = this->ui->nodoF->text().trimmed().toUpper();
   float p = (float) this->ui->peso->value();
   this->mygrafo->modificarArista(i,f,p);
   this->rArea->update();
}

void GrafoView::setListN(QStringList l){
    this->L = l;
}
void GrafoView::setSize(int s){
    this->size = s;
    this->mygrafo = new Grafo(size);
    qDebug()<<size;
     rArea = new RenderArea(this);
     //this->ui->view->setDragMode(Qt::DragMoveCursor);
   mygrafo->generarPosicionesRandom(200,200);
   //this->ui->griD->addWidget(this->rArea);
   this->rArea->setGrafo(mygrafo);

}
void GrafoView::addArista(nodo n1, nodo n2, float p){
   QGraphicsLineItem * a = new QGraphicsLineItem(n1.x,n1.y,n1.x,n2.y);

   int midX, midY;
   midX = (n1.x+n2.x)/2;
   midY =  (n1.y+n2.y) / 2;
   QGraphicsTextItem *temp = new  QGraphicsTextItem(QString::number(p),a);
   this->scene->addItem(temp);


   this->pesos[(n1.etiqueta +"--"+ n2.etiqueta)] = temp;
   this->pesos[(n2.etiqueta +"--"+ n1.etiqueta)] = temp;
   this->aristas.append(a);
   this->scene->addItem(a);

}

void GrafoView::addNodo(QString n,int x, int y){
    QGraphicsEllipseItem * item = new QGraphicsEllipseItem(x,y,15,15);
    QGraphicsTextItem *temp = new  QGraphicsTextItem(n,item);
    this->nodos.append(item);
    this->scene->addItem(temp);
}

void GrafoView::updateScene(){
if(mygrafo == 0) return;
this->pesos.clear();
this->nodos.clear();
this->aristas.clear();
this->scene->clear();
    for(int i = 0; i < size; i++){
        nodo n = this->mygrafo->getNodo(i);
        for(int j = (i+1); j < size; j++){
            nodo n2 = this->mygrafo->getNodo(j);
            if (mygrafo->getPesoArista(i,j)!=Grafo::INFINITO)
                this->addArista(n,n2,mygrafo->getPesoArista(i,j));

        }
        this->addNodo(n.etiqueta,n.x,n.y);
    }

}
