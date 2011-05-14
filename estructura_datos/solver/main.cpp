#include <QtGui/QApplication>
#include "solver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    solver w;
    w.show();

    return a.exec();
}
