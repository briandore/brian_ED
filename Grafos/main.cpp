#include <QtGui/QApplication>
#include "grafos.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Grafos w;
    w.show();

    return a.exec();
}
