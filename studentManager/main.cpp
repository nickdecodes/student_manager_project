#include "addstudent.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    addstudent w;
//    w.show();
    MainWindow m;
    m.show();
    return a.exec();
}
