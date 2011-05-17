#include "mylist.h"

MyList::MyList()
{
    this->word = false;
    count = 0;
}
#include<QDebug>
void MyList::addword(QString w)
{
    if(w.isNull()){this->word = true; return;}
qDebug()<<w;
if(w.length() > 1){
        this->lista[w.at(0)].addword(w.mid(1));
    qDebug()<<this->word;
}else{
        this->lista[w.at(0)];
        this->word= true;
        qDebug()<<this->word;
    }
    this->count++;
}

int MyList::lookup(QString w)
{ if(w.length() == 0 || !(lista.contains(w.at(0))) )
       return 0;

   if(w.length() > 1){

          return lista[w.at(0)].lookup(w.mid(1));     
  }
    if(!this->word) return 1;

    return 2;

}

void MyList::addword2(QString W){
    if(W.length() < 3)return;

    if(!lista2[W.left(3)].contains(W.mid(3))){
        lista2[W.left(3)].append(W.mid(3));
    }
}

int MyList::lookup2(QString w){
    if(!this->lista2.contains(w)) return 0;
    if(this->lista2[w.left(3)].contains(w.mid(3)))
        return 2;
    return 1;
}


void MyList::addword3(QString W){
    if(W.length() < 3) return;

    this->lista3[W.left(3)].addword31(W.mid(3));

}


int MyList::lookup3(QString w){
    if(!this->lista3.contains(w.left(3)))
        return 0;
    return this->lista3[w.left(3)].lookup31(w.mid(3));
}

int MyList::lookup31(QString w){
    if(w.isEmpty() && this->word) return 2;

    if(w.isEmpty()) return 1;

    if( !(lista.contains(w.at(0))) )
         return 0;

     return lista[w.at(0)].lookup(w.mid(1));

}

void MyList::addword31(QString w){
    if(w.isEmpty()){ this->word = true; return;}
 //   qDebug()<<w;

    this->lista[w.at(0)].addword31(w.mid(1));
    this->count++;
}
