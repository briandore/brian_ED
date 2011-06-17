#ifndef INITIALDIALOG_H
#define INITIALDIALOG_H

#include <QDialog>
#include <QStringList>
namespace Ui {
    class InitialDialog;
}

class InitialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InitialDialog(QWidget *parent = 0);
    ~InitialDialog();

private:
    Ui::InitialDialog *ui;
    void closeEvent(QCloseEvent *e);
private slots:
    void on_btOk_clicked();
    void on_size_valueChanged(int );
    void on_remove_clicked();
    void on_btAdd_clicked();
signals:
    void size(int size);
    void list(QStringList l);
};

#endif // INITIALDIALOG_H
