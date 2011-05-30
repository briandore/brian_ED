#ifndef GRAFOS_H
#define GRAFOS_H

#include <QMainWindow>

namespace Ui {
    class Grafos;
}

class Grafos : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grafos(QWidget *parent = 0);
    ~Grafos();

private:
    Ui::Grafos *ui;
};

#endif // GRAFOS_H
