#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstudent.h"
#include "seestudent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_addStudent_triggered()
{
    this->a.show();
}

void MainWindow::on_action_seeStudent_triggered()
{
    this->s.show();
}
