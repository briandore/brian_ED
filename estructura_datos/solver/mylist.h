#ifndef MYLIST_H
#define MYLIST_H
#include <QHash>
class MyList
{
public:
    MyList();
    void addword(QString w);
    int size(){return count;}
    bool lookup(QString w);
private:
    QHash <QChar,MyList> lista;
    bool word;
    int count;
};

#endif // MYLIST_H
