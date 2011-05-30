#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QString>
#include <QMap>
#include <QStringList>
#include <QDebug>
#include<QStack>
#include <math.h>
class operators{
  public:
    enum ops{
        MAS = 2, MENOS =2 , POR = 3, ENTRE = 3, POTENCIA = 4, SEN = 5,COS = 5,
        PARABRE = 10, PARCIERRA = 0, NONE =-1
    };

    QMap<QString , ops> opse;

 operators()
 {
     this->opse.insert("+",MAS);
     this->opse.insert("-",MENOS);
     this->opse.insert("*",POR);
     this->opse.insert("/",ENTRE);
     this->opse.insert("^",POTENCIA);
     this->opse.insert("SIN",SEN);
     this->opse.insert("COS",COS);
     this->opse.insert("(",PARABRE);
     this->opse.insert(")",PARCIERRA);
 }

public:
    ops getOperator(QString op){
        if(this->opse.contains(op))
            return opse[op];
        return NONE;
    }


};

class calculator
{
public:

    calculator();

    double solve(QString e);
    bool valid(QString e);
    double toPostFijo(QString e);
    double evaluar(QStringList e);
    QStringList getTokens(QString e);
    operators opt;

};

#endif // CALCULATOR_H
