#include "lista.h"

lista::lista(int len)
{
 list = new nodo[len];
    this->len = len;
    unique = false;
    clean();
}

void lista::insertar(char data, int ant){

    if(libre == -1) return;

    ant  = irA(ant);
    if(ant == inicio){
        this->list[libre].setData(data,-1,inicio);
        this->list[inicio].setAnterior(libre);
        this->inicio = libre;
        if(cont == 0)
            this->final = inicio;
    }else if(ant == -1){
        this->list[libre].setData(data,final);
        this->list[final].setSiguiente(libre);
        this->final = libre;
    }else{
        this->list[libre].setData(data,list[ant].ant(),ant);
        this->list[list[ant].ant()].setSiguiente(libre);
        this->list[ant].setAnterior(libre);
    }

    libre = this->list[libre].getDisponible();
    cont++;
}


int lista::buscar(char data){
    int pos = 1;
    int i = inicio;
    while(i != -1){
         if(list[i].getData() == data)
            return pos;
         i = list[i].sig();
         pos++;
    }
    return -1;
}
void lista::clean(){
    for(int i = 0; i <len-1; i++)
        this->list[i].setDisponible(i+1);
    this->list[len -1].setDisponible(-1);

      this->inicio = this->final = -1;
      this->cont = 0;
      this->libre = 0;

}

int lista::irA(int pos){
    int temp = inicio;
      for(int i = 1; i < pos; i++){
          temp = list[temp].sig();
      }
      qDebug()<<temp;
      if(temp >= len)
          return -1;
      return temp;

}

void lista::suprimir(int pos){

    if(pos<( this->len+1) && pos != -1){
        pos = irA(pos);

        if(pos == inicio)
        {
            this->inicio = this->list[pos].sig();
            this->list[inicio].setAnterior(-1);
        }else{
            this->list[this->list[pos].ant()].setSiguiente(this->list[pos].sig());
            if(pos == this->final)
                this->final = this->list[pos].ant();
            else
                this->list[this->list[pos].sig()].setAnterior(list[pos].ant());
        }
        this->list[pos].clean(this->libre);
        this->libre = pos;
        cont--;
    }
}

string lista::getAll(){
    string a ="";
    int i = inicio;
    while(i != -1){
        if(i!=inicio)
            a.append(",");
        a+=this->list[i].getData();
        i = this->list[i].sig();
    }
    return a;
}

void lista::suprimirLibro(char data){
    int pos = this->inicio;
    int cont = 1; // lo voy agregar por la forma de mi lista que trabaja con cursores
    while(pos != this->final){

     if(this->list[pos].getData() == data){
        pos = this->list[list[pos].sig()].sig();//esto es para que el apuntador y contador sea iguales
        this->suprimir(cont);
        qDebug()<<"suprimio";
     }cont+=1;      //simulando el p: = siguiente(p,lista) aqui esta el problema
                         //porque avanza siempre al siguiente pero si borra, se va
    }                   //a saltar el que estaba despues de borrar en algun caso de borrar el ultimo
                        //el programa moriria dependiendo como sea la lista
}

void lista::borrarTodos(char data){

    int pos = this->inicio;
    int cont = 1;
    while(pos != -1){

        if(this->list[pos].getData() == data){

              pos = this->list[pos].sig();
               this->suprimir(cont);


        }else{
          pos = this->list[pos].sig();
          cont+=1;}
    }

}


