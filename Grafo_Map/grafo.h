#ifndef GRAFO_H
#define GRAFO_H
#include <QString>
#include <QDebug>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <list>
#include<QHash>

using namespace std;




class nodo {
    public:

       int x,y;
       QString etiqueta; // Solo para efectos de nombrar con una letra un nodo
       nodo() {x=0; y=0; etiqueta=""; }
};

class nodoVecino
{
public:
    nodo n;    // el nodo vecino
    float peso;  // Y la distancia en peso hacia ese nodo

};

class Grafo
{
  private:
    float **matriz;
    nodo *nodos;
    int size;
    bool _dirigido;
    bool checkColision(int limite,int candidato_x,int candidato_y);
    bool *visitados;

    QHash<QString, int> posiciones;
    QHash<QString,QHash<QString, QHash<QString, QHash<int, float > > > > todo;
    QString DAY;
    int Hour;

    void updateData();
    void reloadData();
    void resetVisitados();
    string rp(int n);



 public:
  Grafo(int cant);
  void modificarArista(int n1, int n2, float p);
  void removeArista(int n1, int n2);
  void modificarArista(QString  n1, QString n2, float p);
  void removeArista(QString n1, QString n2);

  nodo getNodo(int i) ;
  float getPesoArista(int nodo1, int nodo2);
  void setPesoArista(int nodo1, int nodo2,float peso) ;
  float getPesoArista(QString n1, QString n2);
  void setPesoArista(QString  n1, QString n2, float p) ;

  void setEtiquetaNodo(int nodo1,string etiqueta);
  void setXYNodo(int nodo1, int x, int y);
  void generarPosicionesRandom(int ancho,int alto);
  void calcularDistancias() ; //Genera todas las distancias de acuerdo a pos x,y
  bool esDirigido() { return _dirigido ;}

  void setDay(QString d);
  void setHour(int h);


  string recorrer_profundidad(int n);
  /*Que internamente recorre el grafo en profundidad, recordar recorrer el resto si
    si el arreglo visitados todavia tiene false. PAG 217 */



  // TODO - implementar
  //bool hayArista(int nodo1, int nodo2);
  //int gradoDelNodo(int nodo);  // cuantas aristas salen de el
  //list<nodoVecino> getNodosVecinos(int nodo);
  //int getCantidadAristas(); // Regresa cuantas aristas tiene el grafo

  int getSize() { return size; } // Regresa cuantos Nodos

   ~Grafo();

  static const float INFINITO = 99999.00;
  static const float DELTACOLISION = 25.0;
  static const int INTENTOS_COLISION =2;
  static float distancia(nodo A, nodo B)
  {
    return (sqrt( (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y) ));
  }
  static float distancia(int x1,int y1, int x2,int y2)
  {
    return (sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ));
  }

};

#endif // GRAFO_H
