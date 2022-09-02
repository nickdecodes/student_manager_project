#ifndef SEESTUDENT_H
#define SEESTUDENT_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class seeStudent;
}

class seeStudent : public QDialog
{
    Q_OBJECT

public:
    explicit seeStudent(QWidget *parent = nullptr);
    ~seeStudent();
    int readFromFile();
    void doSearch(int index, QString cnt);
    void disPlay(int row, QStringList subs);
    void initTableView();

private slots:
    void on_btn_search_clicked();

private:
    Ui::seeStudent *ui;
    QList<QString> stu_lines;
    QStandardItemModel *model;
};

#endif // SEESTUDENT_H
