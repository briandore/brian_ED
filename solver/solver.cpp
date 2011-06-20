#include "solver.h"
#include "ui_solver.h"

solver::solver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::solver)
{
    ui->setupUi(this);
    this->lenX = 0 ;
    this->lenY = 0;
    this->init = false;
    this->min = 3;
    this->ui->dockWidget->setMinimumSize(100,500);
}

solver::~solver()
{
    delete ui;
}

void solver::on_actionLoad_words_triggered()
{    this->ui->listWidget->clear();
    this->list.clear();

    QString filename = QFileDialog::getOpenFileName(this,"Lista");
    QFile file;
    file.setFileName(filename);
    file.open(QFile::ReadOnly);

    if(file.isOpen()){
        while(!file.atEnd()){
            QString line = file.readLine().trimmed();
            if(!line.isEmpty())
                if(!line.contains(" "))
                    if(!list.contains(line)){
                       list.append(line.toUpper());
                        this->lista.addword3(line.toUpper());
                   }

         }
    }

    this->ui->listWidget->addItems(this->list);
    qDebug()<<this->list.count();

}

void solver::liberar(){
    for(int i = 0; i<this->lenY; i++) {
            free(this->sopa[i]);
            this->sopa[i] = NULL;
        }
    free(this->sopa);
    this->sopa  = NULL;
    this->lenX = this->lenY = 0;
    this->init = false;
}
#include<QLabel>
#include<QTableWidgetItem>
void solver::on_actionLoad_Soup_triggered()
{
    QString f =  QFileDialog::getOpenFileName(this," sopa","Cargar sopa de letras");
    if(f.isEmpty())
       return;
    QLabel *l ;
    QTableWidgetItem *item;
    QFile file(f);

;
    if(file.open(QIODevice::ReadOnly)){
         QTextStream a(&file);
       //  QString len = a.readLine();
      //   this->lenX = readLen(len.indexOf("x:"),len);
        // this->lenY = readLen(len.indexOf("y:"),len);

        // for(int y = 0; y < this->lenY; y++){
         int y = 0;
         while(!a.atEnd()){
            QString i = a.readLine().trimmed(); int at = 0;
             if(y== 0){
                 while(this->ui->soup->count() > 0)
                    this->ui->soup->removeItem(this->ui->soup->itemAt(0));

                  this->lenX = i.length();
                  this->lenY = lenX;this->crearArray();
             }
             if(y == lenY)
                 break;
             for(int x = 0; x < this->lenX; x++){
                l = new QLabel();
                this->ui->soup->addWidget(l,y,x);
                 l->setText(QString(i.at(x)));l->setMinimumSize(12,12);
                  sopa[y][x] =   i.at(x);
                    //at ++;
                   // item = new QTableWidgetItem(QString(i.at(x)));
                    //this->ui->lasoup->setItem(y,x,item);
             }
             y+=1;
         }

    }
    //imprimir();

}

void solver::lookUpwords(QString line,QString arcline){

    if(line.length()< this->min) {return;}

    for(int i = this->min; i<(line.count() +1); i++){

        int result = this->lista.lookup3(line.left(i));

            if(result == 0)break;
            if(result == 2){
                this->ans.append(line.left(i));
                cont++;
            }
        }
        for(int i = this->min; i<(arcline.count()+1); i++){
            int result = this->lista.lookup3(arcline.left(i));
            if(result == 0)break;
            if(result == 2){
                this->ans.append(arcline.left(i));
                cont++;
            }


    }
    lookUpwords(line.mid(1),arcline.mid(1));
}


void solver::lookUpInHV(dir d){
     QString wordU="", wordD="", wordL="",wordR="";
    for(int i = 0; i < this->lenX;i++){
        wordU=""; wordD=""; wordL=""; wordR="";
        for(int j = 0; j< this->lenY;j++ ){
            wordU += sopa[j][i];
            wordD.prepend(sopa[j][i]);
            wordR += sopa[i][j];
            wordL.prepend(sopa[i][j]);
        }
       // qDebug()<<wordD<<"WordU: "<<wordU<<"wordR: "<<wordR<<"wordL"<<wordL;
        this->lookUpwords(wordD,wordU);
        this->lookUpwords(wordR,wordL);

    }
}



void solver::lookVerticals(){
    this->lookUpInHV(Vertical);
}

void solver::lookHorizontals(){

    this->lookUpInHV(Horizontal);
}

void solver::lookDiagonal1(){
   QString word, arcword, wordL,arcwordL;;
    for(int i = (this->min-1); i<this->lenY; i++){
        word="", arcword="",wordL="", arcwordL="";;
        for(int j = 1;j<=i; j++ ){
            word+= this->sopa[lenY-j][i-j];
            arcword.prepend(this->sopa[lenY-j][i-j]);

            wordL+= this->sopa[i-j][lenX-j];
            arcwordL.prepend(this->sopa[i-j][lenX-j]);
        }


        this->lookUpwords(word,arcword);
        this->lookUpwords(wordL,arcwordL);

    }
}

void solver::lookDiagonal2(){
    QString word, arcword, wordL,arcwordL, word2, arcword2,wordL2, arcwordL2;
     for(int i = (this->min - 1); i < this->lenY; i++){
         word="", arcword="",wordL="", arcwordL="";
         word2="", arcword2="",wordL2="", arcwordL2="";;

         for(int j = 0;j<=i; j++ ){

             word+= this->sopa[j][i-j];
             arcword.prepend(this->sopa[j][i-j]);

             if(i < (this->lenY -1)){
                wordL+= this->sopa[lenY-1-j][lenX-i+j-1];
                arcwordL.prepend(this->sopa[lenY-1-j][lenX-i+j-1]);
              }


             word2+= this->sopa[lenY-j -1][i-j];
             arcword2.prepend(this->sopa[lenY-j-1][i-j]);

             if((i-j) != (lenX-j-1)){
                wordL2+= this->sopa[i-j][lenX-j-1];
                arcwordL2.prepend(this->sopa[i-j][lenX-j-1]);
            }
         }
        // qDebug()<<word<<"arcword: "<<arcword<<"word2: "<<word2<<"arc2"<<arcword2;
        // qDebug()<<wordL<<"arcwordL: "<<arcwordL<<"wordL2: "<<wordL2<<"arcL2"<<arcwordL2;
         this->lookUpwords(word,arcword);   this->lookUpwords(wordL,arcwordL);
         this->lookUpwords(word2,arcword2); this->lookUpwords(wordL2,arcwordL2);
     }
}

void solver::crearArray(){
    if(this->init)
         this->liberar();

     this->sopa = (QChar **) malloc(this->lenY * sizeof(QChar *));
     for(int i = 0; i < this->lenY; i++)
        this->sopa[i] = (QChar *) malloc(this->lenX * sizeof(QChar));

  //   this->ui->lasoup->clear();
  //   this->ui->lasoup->setRowCount(this->lenY);
   //  this->ui->lasoup->setColumnCount(this->lenX);
    this->init = true;
}

void solver::imprimir(){
   QString g="";
    for(int i = 0; i < lenY;i++){
        qDebug()<<"\n";
       for(int j = 0; j < this->lenX; j++)
          g +=this->sopa[i][j];
       qDebug()<<g;
    }
}

int solver::readLen(int where, QString num)
{
    QString go = num.mid(where+2,2); qDebug()<<go;
    return go.toInt();
}

#include <QTime>
void solver::on_actionSolve_triggered()
{
    if(!this->lenX > 0)
        return ;
    QTime time;

    this->ans.clear();
    this->ui->FoundedList->clear();
    this->cont = 0;
    this->min = this->ui->spinBox->value();


    time.start();
    this->lookHorizontals();
 //   this->lookVerticals();
    this->lookDiagonal2();
 //   this->lookDiagonal1();

    int tim =time.elapsed();

    ans.sort();
    this->ui->lcdTime->display(tim);
    this->ui->FoundedList->addItems(this->ans);
    this->ui->lcdFound->display(this->ans.count());
}

void solver::on_actionAbout_triggered()
{
    QString msg = "Proyecto E.D.";
    msg.append("\nCreado por Brian D, dore_bryan@unitec.edu para preguntas");
    msg.append("\nConsiste en un programa para resolver una sopa de letras de nxn");
    msg.append("\nLa eficiencia se debe a que utilize un arbol nario o por lo menos lo simule");
    msg.append("\n practicamente es lo que hace google con las busquedas instantaneas, las que no cumplen con las ");
    msg.append("\ncondicionan se eliminan y si no hay sugerencia se para la busqueda");
    msg.append("\n En promedio en mi computadora con KUBUNTU 11.04 se tarda 24 milisegundos con 50 x 50");
    msg.append("\nen otros SO puede variar ya que linux le da prioridad a procesamiento y no grafica, lo cual potencializa mi programa");
    msg.append("\n PEQUENHO detalle no sirve el limpiar por lo tanto hay cerrarlo y correr de nuevo para cargar otra sopa");
    QMessageBox::about(this,"About", msg);
}
