#include "sizedialog.h"
#include "ui_sizedialog.h"

SizeDialog::SizeDialog(QString text, int minimo, int max, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SizeDialog)
{

    ui->setupUi(this);
    this->ui->label->setText(text);
    this->ui->spinBox->setMinimum(minimo);
    this->ui->spinBox->setMaximum(max);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));

}

SizeDialog::~SizeDialog()
{

    delete ui;
}

void SizeDialog::closeEvent(QCloseEvent *E){
    emit size(this->ui->spinBox->value());
    E->accept();
}


