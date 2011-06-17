/********************************************************************************
** Form generated from reading UI file 'plotter.ui'
**
** Created: Wed Jun 1 19:53:59 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTER_H
#define UI_PLOTTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plotter
{
public:
    QWidget *dockWidgetContents;
    QGraphicsView *graph;
    QDoubleSpinBox *xi;
    QDoubleSpinBox *xf;

    void setupUi(QDockWidget *Plotter)
    {
        if (Plotter->objectName().isEmpty())
            Plotter->setObjectName(QString::fromUtf8("Plotter"));
        Plotter->resize(708, 627);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        graph = new QGraphicsView(dockWidgetContents);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setGeometry(QRect(0, 0, 600, 600));
        xi = new QDoubleSpinBox(dockWidgetContents);
        xi->setObjectName(QString::fromUtf8("xi"));
        xi->setGeometry(QRect(600, 10, 71, 23));
        xf = new QDoubleSpinBox(dockWidgetContents);
        xf->setObjectName(QString::fromUtf8("xf"));
        xf->setGeometry(QRect(600, 40, 71, 23));
        Plotter->setWidget(dockWidgetContents);

        retranslateUi(Plotter);

        QMetaObject::connectSlotsByName(Plotter);
    } // setupUi

    void retranslateUi(QDockWidget *Plotter)
    {
        Plotter->setWindowTitle(QApplication::translate("Plotter", "Graph Area", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Plotter: public Ui_Plotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTER_H
