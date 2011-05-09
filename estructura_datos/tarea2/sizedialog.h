#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>
#include <QCloseEvent>
namespace Ui {
    class SizeDialog;
}

class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QString text, int minimo=1, int max=100,QWidget *parent = 0);
    ~SizeDialog();

private:
    Ui::SizeDialog *ui;
    void closeEvent(QCloseEvent *);
signals:
    void size(int);


};

#endif // SIZEDIALOG_H
