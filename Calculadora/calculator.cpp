#include "calculator.h"

calculator::calculator()
{
}

double calculator::toPostFijo(QString e){
   e.prepend("("); e.append(")");
   QStack<QString> s;
   QStack <QString> ops; QString temp ,tmop;
   QStringList final;
   QStringList ne(getTokens(e));
    bool b = false;
   foreach(QString d, ne){
       if(opt.getOperator(d)!= opt.NONE){

            while((!ops.isEmpty()) && (opt.getOperator(d))<= opt.getOperator(ops.top())){

                if(ops.top() == "(" && d == ")"){ ops.pop(); break;}
                if(ops.top() == "("){ break;}
                final.append(ops.pop());
             }

         if( opt.getOperator(d)!= operators::PARCIERRA)

               ops.push(d);

       }else {
                 final.append(d);
       }
   }

  // qDebug()<<final;
   return evaluar(final);

}

double calculator::evaluar(QStringList e){
//qDebug()<<e;
    QStack<double> pila;
double t;
    foreach(QString d, e){
//qDebug()<<pila;
      if(d == "+")
            pila.push(pila.pop() + pila.pop());
      else if(d == "~"){
          t = pila.pop();
            pila.push(  pila.pop()-t);
        }
      else if(d == "*")
            pila.push(pila.pop() * pila.pop());
      else if(d == "/")
            pila.push(pow(pila.pop(),-1) * pila.pop());
      else if(d == "COS")
            pila.push(cos(pila.pop()));
      else if(d == "SIN")
            pila.push(sin(pila.pop()));
      else if(d == "^"){
            t = pila.pop();
            pila.push(pow(pila.pop(),t));
      }else if(d == "E"){
           t = pila.pop();
             pila.push(pila.pop()*pow(10,t));
      }  else
            pila.push(d.toDouble());

    }
if(pila.count()> 0)
    return pila.pop();
return 0;
}


QStringList calculator::getTokens(QString e){
   e = e.toUpper();
   QStringList list;  QChar a ;
   QString operat ="", digit;


   while(e.length() > 0){
        a = e.at(0);
        if(a.isDigit() || a == '.'|| a == '-'){

            while( a.isDigit()|| a == '.' || a == '-'){
                if(digit.isEmpty() && a == '.')
                    digit= "0";
                digit += a;
                e = e.mid(1);
                if(e.length() < 1) break;

                a = e.at(0);
            }

           list.append(digit);
           digit ="";
        }else {
            operat += a;
          //  qDebug()<<operat;
            if(opt.getOperator(operat)!= opt.NONE){
               list.append(operat);
                operat ="";
            }
            e = e.mid(1);

        }


    }
   //qDebug()<<list;
   return list;
}
