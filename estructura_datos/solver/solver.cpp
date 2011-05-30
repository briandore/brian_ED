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
                    if(!list.count(line)){
                       list.append(line.toUpper());
                       this->lista.addword(line.toUpper());
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
                    l = new QLabel();
                 this->ui->soup->addWidget(l,y,x);
                 l->setText(QString(i.at(at)));
                  sopa[y][x] =   i.at(at);
                    at +=2;

             }
         }

    }

}
#include<QList>
void solver::lookUpwords(QString line,QString arcline){
    if(line.length()< 3) return;
    for(int i = 3; i<line.count(); i++){
       /* if(this->lista.lookup(line.left(3)))
          this->ui->FoundedList->addItem(line.left(3));
        else
            break;*/
        qDebug()<<line.left(i)<<this->list.count(line.left(i))<<"---"<<arcline.left(i)<<this->list.count(arcline.left(i));

       if(list.contains(line.left(i)))
         this->ui->FoundedList->addItem(line.left(i));
       if(list.contains(arcline.left(i)))
          this->ui->FoundedList->addItem(arcline.left(i));
    }
    lookUpwords(line.mid(1),arcline.mid(1));
}

/*void solver::lookVerticals(){
    QString wordU="", wordD="";
    for(int i = 0; i < this->lenX;i++){
        wordU=""; wordD="";
        for(int j = 0; j< this->lenY;j++ ){
            wordU += sopa[j][i];
            wordD.prepend(sopa[j][i]);
        }
        this->lookUpwords(wordD);
        this->lookUpwords(wordU);
    }
}
*/
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

    }
}

/*void solver::lookHorizontals(){
    QString wordU="", wordD="";
    for(int i = 0; i < this->lenX;i++){
        wordU=""; wordD="";
        for(int j = 0; j< this->lenY;j++ ){
            wordU += sopa[i][j];
            wordD.prepend(sopa[i][j]);
        }
        this->lookUpwords(wordD);
        this->lookUpwords(wordU);
    }
}
*/

void solver::lookVerticals(){
    this->lookUpInHV(Vertical);
}

void solver::lookHorizontals(){
    qDebug()<<"hos";
    this->lookUpInHV(Horizontal);
}

void solver::lookDiagonal1(){
   QString word, arcword, wordL,arcwordL;;
    for(int i = 3; i<=this->lenY; i++){
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
    QString word, arcword, wordL,arcwordL;
     for(int i = 2; i<this->lenY; i++){
         word="", arcword="",wordL="", arcwordL="";
         for(int j = 0;j<=i; j++ ){
             word+= this->sopa[j][i-j];
             arcword.prepend(this->sopa[j][i-j]);
             wordL+= this->sopa[lenY-1-j][lenX-i+j-1];
             arcwordL.prepend(this->sopa[lenY-1-j][lenX-i+j-1]);
         }
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


void solver::on_actionSolve_triggered()
{
    if(!this->lenX > 0)
        return ;
    this->lookHorizontals();
    this->lookVerticals();
    this->lookDiagonal2();
    this->lookDiagonal1();
}
