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

     size = 5;
       InitialDialog *d = new InitialDialog(this);
       d->show();
       connect(d,SIGNAL(size(int)),this,SLOT(setSize(int)));
       connect(d,SIGNAL(list(QStringList)),this,SLOT(setListN(QStringList)));


 this->DAYS = QString("DOMINGO,LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO").split(",");
 this->rArea = new RenderArea();
 this->ui->views->addWidget(this->rArea,0,0,1,1);

}

GrafoView::~GrafoView()
{
    delete ui;
}

void GrafoView::on_Horas_currentIndexChanged(QString e)
{
    if(mygrafo == 0) return;
   e.remove("hrs");
   qDebug()<<"hora"<<e;

     mygrafo->setHour(e.toInt());
    this->rArea->update();
}

void GrafoView::on_Dias_currentIndexChanged(QString d)
{
   if(this->mygrafo == 0) return;
    this->mygrafo->setDay(d.toUpper());
    this->rArea->update();
}

void GrafoView::on_UpdateEdit_clicked()
{

   QString i = this->ui->nodoI->text().trimmed().toUpper();
   QString f = this->ui->nodoF->text().trimmed().toUpper();
   if(i.isEmpty() || f.isEmpty()) return;
   float p = (float) this->ui->peso->value();
   this->mygrafo->modificarArista(i,f,p);
   this->rArea->update();

}

void GrafoView::setListN(QStringList l){
    this->L = l;
}


void GrafoView::setSize(int s){
    this->size = s;
    int d = L.count();
    for(int i = 0; i<(s - d); i++)
        L.append(QString::number(i+1));

    QList<int> horas;
    for(int i = 0; i < 24;i++)
        horas.append(i);

    this->ui->tabla->setRowCount(s);
    this->ui->tabla->setColumnCount(s);

    this->mygrafo = new Grafo(size,L,DAYS,horas);
    this->mygrafo->generarPosicionesRandom(400,400);
    this->rArea->setGrafo(mygrafo);
    this->rArea->update();
}

void GrafoView::floyd(){
    table = new float*[size];
    routes = new int *[size];
    for (int i = 0; i < size;i++){
        table[i] = new float[size];
        routes[i]= new int[size];
   }

    for (int i=0;i < this->size;i++)
    {
        for (int j= 0; j < size;j++){
            table[i][j] = this->mygrafo->getPesoArista(i,j);
            routes[i][j] = 0;
        }
    }


    for (int k = 0; k < size; k++)
        for (int i =0; i < size;i++)
            for (int j =0; j < size;j++)
            {
               float peso = table[i][k] + table[k][j];
               if(peso < Grafo::INFINITO)
                   if (peso < table[i][j]){
                       table[i][j] = peso ;
                       routes[i][j]= k;
                   }

             }
    for(int i = 0; i< size;i++)
        for(int j = 0; j < size; j++)
        {
            QString dato; dato.setNum(table[i][j]);
            QTableWidgetItem *item = new QTableWidgetItem(dato);
            this->ui->tabla->setItem(i,j,item);
        }
}





void GrafoView::on_btBorrar_clicked()
{
    QString i = this->ui->nodoI->text().trimmed().toUpper();
    QString f = this->ui->nodoF->text().trimmed().toUpper();
    if(i.isEmpty() || f.isEmpty()) return;
    this->mygrafo->removeArista(i,f);
    this->rArea->update();
}

void GrafoView::on_EditXY_clicked()
{
    QString n = this->ui->Nodo->text().trimmed().toUpper();
    if(!n.isEmpty()){
        int x = this->ui->X->value();
        int y = this->ui->Y->value();
        this->mygrafo->editPos(n,x,y);
        this->rArea->update();
    }
}

void GrafoView::on_floyd_clicked()
{
    this->floyd();
}

void GrafoView::on_btRutaCortes_clicked()
{

   floyd();
   this->ui->route->clear();
   int i = this->mygrafo->getPos(this->ui->nodoI->text().trimmed());
   int f = this->mygrafo->getPos(this->ui->nodoF->text().trimmed());
   if(i == -1 || f == -1)
       return;

   if(this->ui->tabla->item(i,f)->text().toFloat() != Grafo::INFINITO){
       this->ui->timeCorto->setText(this->ui->tabla->item(i,f)->text());

       QStringList m = this->camino(i,f).split(",",QString::SkipEmptyParts);
       m.push_back(this->mygrafo->getNodo(f).etiqueta);
       m.push_front(this->mygrafo->getNodo(i).etiqueta);

       this->ui->route->addItems(m);
       this->mygrafo->setSeleccionados(m);
       this->rArea->update();
   }else
       this->ui->timeCorto->setText("DESTINO IMPOSIBLE");

}



QString GrafoView::camino(int i, int f){
  QString c = "";
   int k = routes[i][f];
   if( k == 0)return c;
   c = camino(i,k) + ",";
   c += this->mygrafo->getNodo(k).etiqueta + ",";
   c += camino(k,f);
   return c;

}

void GrafoView::on_addDay_clicked()
{
        QString k = this->ui->newDay->text().toUpper().trimmed();
        if(!k.isEmpty()&& !this->DAYS.contains(k)){
            this->mygrafo->addNewDay(k);
            this->ui->Dias->addItem(k);
            this->DAYS.append(k);
        }
}

void GrafoView::on_actionAbout_triggered()
{
    QString MSG ="Proyecto de E.D.\n";
   MSG.append( "creado por Bryan D\n").append( "dore_bryan@unitec.edu");
   MSG.append("\nBasicamente consiste en un multigrafos en el cual las horas y dias son las\nvariables para mostrar las aristas");
    QMessageBox::about(this,"About",MSG);
}

void GrafoView::on_actionHelp_triggered()
{
    QString MSG ="Para agreger arista escribir Nodo1 y Nodo2, el origen y destino respectivamente";
      MSG.append("\nLuego en editar seleccione el peso este se agregara o actualizara segun sea el caso");
      MSG.append("\nPara borrar arista es basicamente lo mismo con la excepcion que hay que darle clic en borrar");
      MSG.append("\nEl recorrido mas corto pinta de rojo los nodos por los cuales hace el camino");
      MSG.append("\nEn el tab FLOYD se muestra la tabla generada por el algoritmo de FLOYD");
      MSG.append("\nExiste la opcion de agregar nuevos dias, como dias festivos o evento especiales en cierto dia\n");
      MSG.append("esto es por ejemplo para 15 de sept cualquiera que sea el dia que caiga no va haber el mismo trafico");
      MSG.append("\n esto es un plus y flexibilidad al programa");
    QMessageBox::about(this,"About",MSG);
}
