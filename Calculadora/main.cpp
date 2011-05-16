#include <QtGui/QApplication>
#include "mycalculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCalculator w;
    w.show();

    return a.exec();
}
