#include "grafos.h"
#include "ui_grafos.h"

Grafos::Grafos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Grafos)
{
    ui->setupUi(this);
}

Grafos::~Grafos()
{
    delete ui;
}
