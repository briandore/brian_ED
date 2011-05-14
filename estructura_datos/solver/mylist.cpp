#include "mylist.h"

MyList::MyList()
{
    this->word = false;
    count = 0;
}
#include<QDebug>
void MyList::addword(QString w)
{

    if(w.length() > 1)
        this->lista[w.at(0)].addword(w.mid(1));
    else{
        this->lista[w.at(0)];
        this->word= true;
        qDebug()<<"sed";
    }
    this->count++;
}

bool MyList::lookup(QString w)
{
    if(w.length() > 1){
      if(lista.contains(w.at(0)))
          return lista[w.at(0)].lookup(w.mid(1));
        return false;
  }
    if(this->word && this->lista.contains(w.at(0)))
        return true;
    return false;

}
