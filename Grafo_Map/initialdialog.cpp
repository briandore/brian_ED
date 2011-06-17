#include "initialdialog.h"
#include "ui_initialdialog.h"

InitialDialog::InitialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitialDialog)
{
    ui->setupUi(this);
}

InitialDialog::~InitialDialog()
{

    delete ui;
}

void InitialDialog::on_btAdd_clicked()
{
    if(this->ui->listNodos->count()< this->ui->size->value());
       this->ui->listNodos->addItem(this->ui->newNodo->text().trimmed().toUpper());
}

void InitialDialog::on_remove_clicked()
{
    if(this->ui->listNodos->count() > 0)
    this->ui->listNodos->removeItemWidget(this->ui->listNodos->currentItem());
}

void InitialDialog::on_size_valueChanged(int v )
{
    if(v < this->ui->listNodos->count())
        on_remove_clicked();
}

void InitialDialog::closeEvent(QCloseEvent *e){
    QStringList L;
   while(0 <this->ui->listNodos->count())
        L.append(this->ui->listNodos->takeItem(0)->text());
    emit list(L);
    emit size(this->ui->size->value());

}

void InitialDialog::on_btOk_clicked()
{this->close();

}
