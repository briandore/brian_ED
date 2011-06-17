#include <QtGui/QApplication>
#include "grafoview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GrafoView w;
    w.show();

    return a.exec();
}
