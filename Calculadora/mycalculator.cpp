#include "mycalculator.h"
#include "ui_mycalculator.h"

MyCalculator::MyCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyCalculator)
{
    ui->setupUi(this);
   // f = new QTableWidget(this);

}

MyCalculator::~MyCalculator()
{
    delete ui;
}

QString MyCalculator::previewCheck(QString e){
    int i ,j;

    foreach(QChar a, this->variables.keys()){
        (e.replace(a,QString::number(variables[a])));
    }
return e;
    /*foreach(QChar a, this->variables.keys()){
        i= e.indexOf(a);
        if(i== -1) continue;

        if(i > 0){
           j =  e.at(i-1).toAscii();
           if(!(j > 64 && j < 91)){
               if(i < (e.length() -1)){
                   j =  e.at(i + 1).toAscii();
                   if(!(j > 64 && j < 91))

               }
           }
    }*/
}

void MyCalculator::escribe(QString e){
    QString a = this->ui->expresion->text();
    this->ui->expresion->setText(a.append(e));
}

void MyCalculator::on_bt1_clicked()
{
    this->escribe("1");
}

void MyCalculator::on_bt2_clicked()
{
     this->escribe("2");
}

void MyCalculator::on_bt3_clicked()
{
     this->escribe("3");
}

void MyCalculator::on_bt4_clicked()
{
     this->escribe("4");
}

void MyCalculator::on_bt5_clicked()
{
     this->escribe("5");
}

void MyCalculator::on_bt6_clicked()
{
     this->escribe("6");
}

void MyCalculator::on_bt7_clicked()
{
     this->escribe("7");
}

void MyCalculator::on_bt8_clicked()
{
     this->escribe("8");
}

void MyCalculator::on_bt9_clicked()
{
     this->escribe("9");
}

void MyCalculator::on_bt0_clicked()
{
     this->escribe("0");
}

void MyCalculator::on_btDot_clicked()
{
     this->escribe(".");
}

void MyCalculator::on_btPlus_clicked()
{
     this->escribe("+");
}

void MyCalculator::on_btMinus_clicked()
{
     this->escribe("-");
}

void MyCalculator::on_btBy_clicked()
{
     this->escribe("*");
}

void MyCalculator::on_btDivide_clicked()
{
     this->escribe("/");
}

void MyCalculator::on_btPar1_clicked()
{
     this->escribe("(");
}

void MyCalculator::on_btPar2_clicked()
{
     this->escribe(")");
}

void MyCalculator::on_btSin_clicked()
{
     this->escribe("sin(");
}

void MyCalculator::on_btCos_clicked()
{
     this->escribe("cos(");
}

void MyCalculator::on_btClean_clicked()
{
    this->ui->expresion->setText("");
}

void MyCalculator::on_btDelete_clicked()
{
    QString s = this->ui->expresion->text();
    s = s.left(s.length()-1);
    this->ui->expresion->setText(s);
}

void MyCalculator::on_btPower_clicked()
{
     this->escribe("^");
}

void MyCalculator::on_btFx_clicked()
{

}

void MyCalculator::on_btSolve1_clicked()
{
    calculator n;
    QString d = previewCheck(this->ui->expresion->text());
    this->ui->expresion->setText(QString::number(n.toPostFijo(d)));
}

void MyCalculator::on_updateVrs_clicked()
{
    QChar v = this->ui->var->text().toUpper().at(0);
    bool *good =new bool();
    double d = this->ui->value->text().toDouble(good);
    if(v != 'X' && good )
        this->variables[v] = d;
    this->updateVars();
}

void MyCalculator::updateVars(){
   QList<QChar> vas( this->variables.keys());
   QStringList  f;
   QList<double> d(this->variables.values());
   foreach(QChar c, vas){
       f.append(c);
   }
   for(int i = 0; i< f.length(); i++){
       f[i]+= "->" + QString::number(d.at(i));

   }
   this->ui->variables->clear();
   this->ui->variables->addItems(f);
}
