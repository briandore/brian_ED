#include "mycalculator.h"
#include "ui_mycalculator.h"

MyCalculator::MyCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyCalculator)
{
    ui->setupUi(this);
    this->ui->tableFx->setRowCount(5);

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
     this->escribe("~");
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
    this->ui->expresion->clear();
    this->escribe("f(x) = ");
}

void MyCalculator::on_btSolve1_clicked()
{
    calculator n;
    QString d = previewCheck(this->ui->expresion->text());
    if(d.startsWith("f(x) = "))
    {
        d.remove("f(x) = ");
        QStringList L;
        L.append(d);
        this->graph(L);
    }
    double ans = n.solve(d);
    if(ans != INFINITY)
        this->ui->expresion->setText(QString::number(ans));
    else
        this->ui->expresion->setText("sintax error");
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

void MyCalculator::on_btGraph_clicked()
{
    QStringList l;
    for(int i = 0; i< this->ui->tableFx->rowCount();i ++){
         if(this->ui->tableFx->item(i,1) != 0 &&
            !this->ui->tableFx->item(i,1)->text().isEmpty())
            l.append(previewCheck(this->ui->tableFx->item(i,1)->text()));

   }

    this->graph(l);
}

void MyCalculator::graph(QStringList l){
    p= new Plotter(this);
      this->ui->lo->addWidget(p);
    p->graph(l,this->ui->xi->value(),this->ui->xf->value());
}

void MyCalculator::on_btNegative_clicked()
{
    this->escribe("-");
}

void MyCalculator::on_actionAbout_triggered()
{
    QString MSG ="Proyecto de E.D.\n";
   MSG.append( "creado por Bryan D\n").append( "dore_bryan@unitec.edu");
   MSG.append("\nBasicamente consiste en una calculadora, donde se puede realizar \nlas operaciones basicas");
   MSG.append("tambien se pueden asignar variables a exepcion de las X,\n Puede graficar multiples funciones como un plus");
   QMessageBox::about(this,"About",MSG);
}

void MyCalculator::on_actionHelp_triggered()
{
   QString MSG ="Para graficar basta con escribir las funciones en la tabla de funciones\n";
   MSG.append("pero no admite cocientes por lo tanto se debe escribir el operardor por ejemplo\n");
   MSG.append("2*x^3 lo siguiente daria un error 2x^3, tambien es importante recalcar que para los ");
   MSG.append("numeros negativos se usa el signo - y para el menos el signo ~ , tambien no se puede escribir espacios entre \n");
  MSG.append("las funciones en ciertas ocaciones pueden ocurrir errores por lo mismo, tambien esta el operador Exponencial representado por\n");
   MSG.append("e un ejemplo seria 2e3 el resultado es 2000");
          QMessageBox::about(this,"About",MSG);
}
