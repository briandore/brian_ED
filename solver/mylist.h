#ifndef MYLIST_H
#define MYLIST_H
#include <QHash>
#include<QStringList>
class MyList
{
public:
    MyList();
    void addword(QString w);
    void addword2(QString W);
    void addword3(QString W);

    int size(){return count;}
    int lookup(QString w);
    int lookup2(QString w);
    int lookup3(QString w);

    int lookup31(QString w);
    void addword31(QString w);
private:
    QHash <QChar,MyList> lista;
    QHash<QString,QStringList> lista2;
    QHash<QString,MyList>lista3;
    bool word;
    int count;
};

#endif // MYLIST_H
