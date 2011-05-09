#include "cursores.h"
#include "ui_cursores.h"

cursores::cursores(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cursores)
{
    ui->setupUi(this);
    SizeDialog * s = new SizeDialog("Asigne el tamaño de la lista");
    s->show();
    connect(s,SIGNAL(size(int)),this,SLOT(inicializarLista(int)));
    this->ui->btTool->addAction(this->ui->actionSuprimirLibro);
    this->ui->btTool->addAction(this->ui->actionSuprimirCorregido);
    this->operadores.push_front('(');
    this->operadores.push_front('*');
    this->operadores.push_front('/');
    this->operadores.push_front('+');
    this->operadores.push_front('-');
    this->operadores.push_front('*');
}

cursores::~cursores()
{
    delete ui;
}
void cursores::inicializarLista(int i){
    this->myList = new lista(i);
    qDebug()<<i;
}


#include <QMessageBox>
void cursores::on_btAdd_clicked()
{
    QString data = this->ui->word->text().trimmed();
    if(!verificar()) return;

    char k = (char)data.at(0).toAscii();
qDebug()<<k;

    int pos =(this->ui->byPos->isChecked()?this->ui->spinBox->value():-1);
    this->myList->insertar(k,pos);

    updateData();
}

void cursores::on_actionDelete_triggered()
{
    if(this->ui->byPos->isChecked())
        this->myList->suprimir(this->ui->spinBox->value());

    updateData();
}

bool cursores::verificar(){
    if(this->ui->word->text().trimmed().isEmpty()){
        QMessageBox::warning(this,"Error","Ingrese un caracter");
        return false;
    }
    return true;
}

void cursores::on_actionLookup_triggered()
{
    if(!verificar()) return;
    QString data = this->ui->word->text().trimmed();
    QMessageBox::warning(this,"Buscar",QString::number(this->myList->buscar((char)data.at(0).toAscii())));


}

void cursores::on_byPos_stateChanged(int state)
{
    switch(state){
        case Qt::Checked :
            this->ui->spinBox->setEnabled(true);
            break;
        case Qt::Unchecked :
            this->ui->spinBox->setEnabled(false);
        break;
    }
}

void cursores::on_btSetNumber_clicked()
{
   QString number = this->ui->number->text().trimmed();
   if(number.isEmpty()){
       QMessageBox::warning(this,"Error","Ingrese un numero primero");
       return;
   }

   this->binarios.clear();
   qDebug()<<number;
   this->toBinary(number.toInt(),0);
      qDebug()<<binarios;
   this->ui->binaryNumber->setText(BinariosToString());

  /* QString binario = QString::number(numberToBinary(number.toInt(),0));


   foreach(QChar num, binario)
       this->binarios.append(num.digitValue());


   this->ui->binaryNumber->setText(binario);
   */



}

void cursores::on_btPlus_clicked()
{
    this->plusOne(this->binarios.count()-1);
    this->ui->binaryNumber->setText(BinariosToString());
    qDebug()<<binarios;
}

void cursores::plusOne(int len){
   if(len == -1)
       this->binarios.push_front(1);
   else if(!binarios.at(len))
           binarios[len] = 1;
   else{
        binarios[len] = 0;
        plusOne(len-1);
    }
}

void cursores::minusOne(int len){
   if(len == 0)
       this->binarios.pop_front();
   else if(!binarios.at(len)){
           binarios[len] = 1;
           minusOne(len-1);
    }else
        binarios[len] = 0;
}

void cursores::toBinary(int number, int power){

    if(number == 0)
        return;
 qDebug()<<number;
    if(number%2 == 0)
        this->binarios.push_front(0);
    else
        this->binarios.push_front(1);

    toBinary(number/2,power + 1);
}

QString cursores::BinariosToString(){
    QString temp ="";
    foreach(int num, binarios)
        temp +=QString::number(num);
    return temp;
}



//De lujo para saber que estaba buena la logica
int cursores::numberToBinary(int number, int power){
    if(number == 0)
        return 0;
    if(number%2 == 0)
        return numberToBinary(number/2,power + 1);
    else
        return pow(10,power) + numberToBinary(number/2,power + 1);
}



void cursores::on_pushButton_6_clicked()
{
    if(this->binarios.length() == 0) return;
    this->minusOne(this->binarios.length()-1);
    this->ui->binaryNumber->setText(BinariosToString());
    qDebug()<<binarios;
}

void cursores::on_actionSuprimirLibro_triggered()
{
    QString data = this->ui->word->text().trimmed();
    if(!verificar()) return;

    char k = (char)data.at(0).toAscii();
qDebug()<<k;
    this->myList->suprimirLibro(k);
    this->updateData();
}
void cursores::updateData(){
    this->ui->list->clear();
    QString s  = this->myList->getAll().c_str();
    this->ui->list->addItems(s.split(","));

    qDebug()<<s;
}

void cursores::on_actionSuprimirCorregido_triggered()
{
    QString data = this->ui->word->text().trimmed();
    if(!verificar()) return;

    char k = (char)data.at(0).toAscii();
qDebug()<<k;
    this->myList->borrarTodos(k);
    this->updateData();
}

int cursores::opMayor(QChar ti, QChar t2){
    int i = this->operadores.
}

void cursores::mathMethod(){
    QString exp = this->ui->expresion->text().trimmed();
    QList<int> num;
    QList<QChar> ops;
    if(exp.count("(")==exp.count(")")){
         QChar c = '';
         while(exp.length() != 0){
             c = exp.at(0);

        }
    }
}
