#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addstudent.h"
#include "seestudent.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_addStudent_triggered();

    void on_action_seeStudent_triggered();

private:
    Ui::MainWindow *ui;
    addstudent a;
    seeStudent s;
};

#endif // MAINWINDOW_H
