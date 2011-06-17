#include "grafo.h"



Grafo::Grafo(int cantidad_nodos){
    int fila;
    size = cantidad_nodos;

   matriz = new float*[cantidad_nodos]; // Esto crea todas las filas
    for (fila=0; fila<cantidad_nodos; fila++)
    {
        matriz[fila] = new float[cantidad_nodos]; // Esto crea todas las columnas
    }

    for(int i=0; i<cantidad_nodos; i++) // Inicializar el la matriz con ceros en diagonal e infinito el resto
      for(int j=0; j<cantidad_nodos; j++)
        if(i==j)
          matriz[i][j]=0.0;
        else
            matriz[i][j]=Grafo::INFINITO;

    // Inicializar el indice de nodos
    nodos = new nodo[cantidad_nodos];
    for(int i=0; i<cantidad_nodos; i++)
        nodos[i].etiqueta.setNum(i);

    for(int i=0; i< this->size; i++)
        this->todo[QString::number(i)];

    for(int i = 0; i< this->size; i++){
        this->posiciones.insert(QString::number(i),i);
    }

    this->visitados =  new bool[cantidad_nodos];
    this->resetVisitados();

      srand(time(0));

}
void Grafo::resetVisitados(){
     for(int i = 0; i< this->getSize() ;i++)
       visitados[i] = false;
}

Grafo::~Grafo(){

    for (int i=0; i<size; i++)
    {
        delete [] matriz[i] ;
    }
    delete [] matriz;
    delete [] nodos;
    delete [] visitados;
}
void Grafo::modificarArista(int n1, int n2, float p){
    if(n1!=n2)
    {
       this->matriz[n1][n2] = p;
       if(!this->_dirigido)
           this->matriz[n2][n1] = p;

    }
}

void Grafo::modificarArista(QString n1, QString n2, float p)
{

  if(!this->posiciones.contains(n1) || !this->posiciones.contains(n2)) return;
    int nodo1 = posiciones[n1];
    int nodo2 = posiciones[n2];
     this->modificarArista(nodo1,nodo2,p);

}

void Grafo::removeArista(int n1, int n2){
    if(n1!=n2 )
    {
        this->matriz[n1][n2] = Grafo::INFINITO;
        if(!this->_dirigido)
            this->matriz[n2][n1] = Grafo::INFINITO;


    }
}

void Grafo::removeArista(QString n1, QString n2)
{
    if(!this->posiciones.contains(n1) || !this->posiciones.contains(n2)) return;
    int nodo1 = posiciones[n1];
    int nodo2 = posiciones[n2];
    this->removeArista(nodo1,nodo2);


}

nodo Grafo::getNodo(int i)
{
   nodo n;
   n=this->nodos[i];
   return n;
}

float Grafo::getPesoArista(int nodo1, int nodo2)
{
   return this->matriz[nodo1][nodo2];
}

void Grafo::setPesoArista(int nodo1, int nodo2,float peso)
{
    if(nodo1!=nodo2 && this->matriz[nodo1][nodo2]!=Grafo::INFINITO)
    {
       this->matriz[nodo1][nodo2] = peso;
       if(!this->_dirigido)
           this->matriz[nodo2][nodo1] = peso;

    }
}

void Grafo::setEtiquetaNodo(int nodo1,string etiqueta)
{


}

void Grafo::setXYNodo(int nodo1, int x, int y)
{

}

bool Grafo::checkColision(int limite,int candidato_x,int candidato_y)
{
    float dist;
    for(int i=0; i<limite; i++)
    {
        dist = Grafo::distancia(nodos[i].x,nodos[i].y,
                                candidato_x,candidato_y);
        qDebug() << "nodo:" << i <<"<->" << limite << "candidatos:" << candidato_x << ":"
                 << candidato_y << " Distancia:" << dist ;
        if(dist<=Grafo::DELTACOLISION)
        {   qDebug() << "Colision Detected: " << dist;
            return true;
        }
    }
    return false;
}

void Grafo::generarPosicionesRandom(int ancho,int alto)
{
     for (int i=0;i<this->size;i++)
     {
       bool colision=true;
       int cont=0;
       int candidato_x, candidato_y;
       while(colision&&cont<=Grafo::INTENTOS_COLISION) // intentos
       {
           candidato_x = rand() % ancho;
           candidato_y = rand() % alto;
           // Este metodo chequea contra el resto sino colisiona
           // Hasta el nodo i
           if (!checkColision(i,candidato_x,candidato_y))
                colision=false;
           else
               cont++;
       }
       this->nodos[i].x = candidato_x  ;
       this->nodos[i].y = candidato_y;

     }

}
// PRE-CONDICION : ya se tuve que haber generado Posiciones Random del grafo
void Grafo::calcularDistancias()
{
    for (int i = 0 ; i< this->size; i++)
    {
        for (int j=0; j< this->size; j++ )
        {
          if (i!=j) // Si no es el mismo
             this->modificarArista(i,j, Grafo::distancia( this->getNodo(i),this->getNodo(j)
                                                     )
                                 );

        }
    }

}


string Grafo::recorrer_profundidad(int n){
   this->resetVisitados();
    string d = "";
    if(n < this->getSize()){
       d += this->rp(n);
    }

    for(int i = 0; i<this->getSize(); i++){
        if(!visitados[i])
            d+= ";" + rp(i);
    }

    return d;
}
string Grafo::rp(int n){
    string d ;
    d = this->nodos[n].etiqueta.toStdString();
    this->visitados[n] = true;
    for(int i = 0; i< this->getSize(); i++){
        if( i == n || visitados[i]) continue;
        if(matriz[n][i] != INFINITO )
            d+="," + rp(i);

    }

    return d;
}

void Grafo::reloadData(){
    for(int i = 0; i < this->size; i++){
        for(int j = (i +1); j<this->size; j++){
            matriz[i][j]= this->todo[this->nodos[i].etiqueta][this->nodos[j].etiqueta][DAY][Hour];
            matriz[j][i]= this->todo[this->nodos[j].etiqueta][this->nodos[i].etiqueta][DAY][Hour];
        }
    }
}

void Grafo::updateData(){

    for(int i = 0; i < this->size; i++){
        for(int j = (i +1); j<this->size; j++){
            this->todo[this->nodos[i].etiqueta][this->nodos[j].etiqueta][DAY][Hour] = matriz[i][j];
            this->todo[this->nodos[j].etiqueta][this->nodos[i].etiqueta][DAY][Hour] = matriz[j][i];
        }
    }
}


void Grafo::setDay(QString d){
    this->updateData();
    this->DAY = d;
    this->reloadData();

}

void Grafo::setHour(int h){
    this->updateData();
    this->Hour = h;
    this->reloadData();
}
