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
/*    lista.addword("word");
    qDebug()<<lista.lookup("w");
    qDebug()<<lista.lookup("wo");
    qDebug()<<lista.lookup("wor");
    qDebug()<<lista.lookup("word");*/
    this->min = 3;
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
    for(int i=0; i<this->lenY; i++) {
            free(this->sopa[i]);
            this->sopa[i] = NULL;
        }
    free(this->sopa);
    this->sopa  = NULL;
    this->lenX = this->lenY = 0;
    this->init = false;
}
#include<QLabel>
void solver::on_actionLoad_Soup_triggered()
{
    QString f =  QFileDialog::getOpenFileName(this," sopa","Cargar sopa de letras");
    if(f.isEmpty())
       return;
    QLabel *l ;

    QFile file(f);
    if(file.open(QIODevice::ReadOnly)){
         QTextStream a(&file);
         QString len = a.readLine();
         this->lenX = readLen(len.indexOf("x:"),len);
         this->lenY = readLen(len.indexOf("y:"),len);
         this->crearArray();

         for(int i = 0; i<this->ui->soup->count(); i++)
             this->ui->soup->removeItem(this->ui->soup->itemAt(i));

         for(int y = 0; y < this->lenY; y++){
             QString i = a.readLine(); int at = 0;qDebug()<<i;
             for(int x = 0; x < this->lenX; x++){
                    l = new QLabel(); l->setMinimumSize(12,12);
                 this->ui->soup->addWidget(l,y,x);
                 l->setText(QString(i.at(at)));
                  sopa[y][x] =   i.at(at);
                    at ++;

             }
         }

    }

}

void solver::lookUpwords(QString line,QString arcline){
    if(line.length()< this->min) {return;}

    for(int i = this->min; i<line.count(); i++){
            int result = this->lista.lookup3(line.left(i));
            if(result == 0)break;
            if(result == 2){
                this->ans.append(line.left(i));
                cont++;
            }
        }
        for(int i = this->min; i<arcline.count(); i++){
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
     QString wordU="", wordD="";
    for(int i = 0; i < this->lenX;i++){
        wordU=""; wordD="";
        for(int j = 0; j< this->lenY;j++ ){
            wordU += sopa[(d ==Vertical?j:i)][(d ==Vertical?i:j)];
            wordD.prepend(sopa[(d ==Vertical?j:i)][(d ==Vertical?i:j)]);
        }
    //    qDebug()<<wordD;
    //    qDebug()<<wordU;
        this->lookUpwords(wordD,wordU);
        qDebug()<<wordD<<"#"<<wordU;

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
        qDebug()<<word<<"dia1"<<arcword<<"#"<<i;
        qDebug()<<wordL<<"arc"<<arcwordL;

        this->lookUpwords(word,arcword);
        this->lookUpwords(wordL,arcwordL);

    }
}

void solver::lookDiagonal2(){
    QString word, arcword, wordL,arcwordL;
     for(int i = (this->min - 1); i<this->lenY; i++){
         word="", arcword="",wordL="", arcwordL="";
         for(int j = 0;j<=i; j++ ){
             word+= this->sopa[j][i-j];
             arcword.prepend(this->sopa[j][i-j]);

             wordL+= this->sopa[lenY-1-j][lenX-i+j-1];
             arcwordL.prepend(this->sopa[lenY-1-j][lenX-i+j-1]);
         }
         qDebug()<<word<<"dia2"<<arcword<<"#"<<i;
          qDebug()<<wordL<<"arc"<<arcwordL;
         this->lookUpwords(word,arcword);
         this->lookUpwords(wordL,arcwordL);

     }
}

void solver::crearArray(){
    if(this->init)
         this->liberar();

     this->sopa = (QChar **) malloc(this->lenY * sizeof(QChar *));
     for(int i = 0; i < this->lenY; i++)
        this->sopa[i] = (QChar *) malloc(this->lenX * sizeof(QChar));

    this->init = true;
}

void solver::imprimir(){
    for(int i = 0; i < lenY;i++){
        qDebug()<<"\n";
        for(int j = 0; j < this->lenX; j++)
            qDebug()<<this->sopa[i][j];
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
    qDebug()<<this->lenY<<"#"<<lenX;

    time.start();
    this->lookHorizontals();
    this->lookVerticals();
    this->lookDiagonal2();
    this->lookDiagonal1();

    int tim =time.elapsed();

    this->ui->lcdTime->display(tim);
    this->ui->FoundedList->addItems(this->ans);
    this->ui->lcdFound->display(this->ans.count());
}
