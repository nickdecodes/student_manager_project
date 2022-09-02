#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class addstudent; }
QT_END_NAMESPACE

class addstudent : public QDialog
{
    Q_OBJECT

public:
    addstudent(QWidget *parent = nullptr);
    ~addstudent();
    void clearUserInterface();
    void writeToFile(QString cnt);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancal_clicked();

private:
    Ui::addstudent *ui;
};
#endif // ADDSTUDENT_H
