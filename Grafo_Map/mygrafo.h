#ifndef MYGRAFO_H
#define MYGRAFO_H
#include<QHash>
#include<QString>

class MyGrafo
{
public:
    MyGrafo(int cant);
private:

    QHash<QString,QHash<QString, QHash<QString, QHash<int, float > > > > todo;
};

#endif // MYGRAFO_H
