#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <QDebug>
using namespace std;
class lista
{
    struct nodo{
    private:
        int siguiente, anterior, disponible;
        char data;
    public:
        void clean(int disponible){
            this->anterior =this->siguiente =  -1;
            this->data = ' ';
            this->disponible = disponible;
        }
        void setData(char data,int anterior = -1, int siguiente = -1){
            this->data = data;
            this->anterior = anterior;
            this->siguiente = siguiente;
        }

        nodo(char data,int anterior = -1, int siguiente = -1){
            this->setData(data,anterior,siguiente);
        }

        nodo(){
            clean(-1);
        }

        void setAnterior(int ant){
            this->anterior = ant;

        }
        void setSiguiente(int si){
            this->siguiente = si;
        }

        char getData(){return this->data;}


        void setDisponible(int dis){
            this->disponible = dis;
        }
        int getDisponible(){ return this->disponible;}
        int ant(){return this->anterior;}
        int sig(){return this->siguiente;}

    };
private:
     bool unique; //no implementado
     int len;
     int libre;
     int inicio;
     int final;
     int cont;
     int irA(int pos);
public:
    lista(int size);
    void clean();
    nodo *list;
    void insertar(char data, int ant = -1);
    void suprimir(int pos);
    void suprimir(char data);
    void suprimirLibro(char data);
    void borrarTodos(char data);
    int buscar(char data);
    int contar(char data);
    void setUnique(bool u){ this->unique = u;} //no implementado
    bool isUnique(){return this->unique;}
    int size(){return this->len;}
    int length(){
        return cont;
    }
    string getAll();//"d,f,d,d,d"
};

#endif // LISTA_H
