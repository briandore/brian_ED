/********************************************************************************
** Form generated from reading UI file 'plotter.ui'
**
** Created: Sun Jun 19 21:20:07 2011
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
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plotter
{
public:
    QWidget *dockWidgetContents;
    QGraphicsView *graph;

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
