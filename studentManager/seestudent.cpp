#include "seestudent.h"
#include "ui_seestudent.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>

seeStudent::seeStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seeStudent)
{
    ui->setupUi(this);
    if (readFromFile() == -1) {
        QMessageBox::critical(this, "严重错误", "文件打开失败，请重试");
        this->close();
    }
    this->model = new QStandardItemModel;
    initTableView();
}

seeStudent::~seeStudent()
{
    delete ui;
}

int seeStudent::readFromFile() {
    QFile file("student.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        stu_lines.append(line);
    }
    file.close();
    return 0;
}

void seeStudent::on_btn_search_clicked()
{
    this->model->clear();
    initTableView();
    int index = this->ui->cbb_method->currentIndex();
    QString cnt = this->ui->le_cnt->text();
    doSearch(index, cnt);
}

void seeStudent::doSearch(int index, QString cnt) {
    int i = 0;
    int row = 0;
    for (i = 0; i < stu_lines.length(); i++) {
        QString line = stu_lines.at(i);
        line = line.trimmed();
        QStringList subs = line.split(" ");
        switch (index) {
        case 1:
            if (cnt == subs.at(0)) {
                disPlay(row++, subs);
            }
            break;
        case 2:
            if (cnt == subs.at(1)) {
                disPlay(row++, subs);
            }
            break;
        case 3:
            if (cnt == subs.at(4)) {
                disPlay(row++, subs);
            }
            break;
        default:
            qDebug() << "error";
            break;
        }
    }
}

void seeStudent::disPlay(int row, QStringList subs) {
    int i = 0;
    for (i = 0; i < 5; i++) {
        this->model->setItem(row, i, new QStandardItem(subs.at(i)));
    }
    QString str;
    for ( i = 5; i < subs.length(); i++) {
        str += subs.at(i) + ",";
        this->model->setItem(row, 5, new QStandardItem(str));
    }
}

void seeStudent::initTableView() {

    //设置表头
    this->model->setHorizontalHeaderItem(0, new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3, new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4, new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5, new QStandardItem("兴趣"));

    this->ui->tableView->setModel(model);
    //设置列宽
    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,50);
    this->ui->tableView->setColumnWidth(3,50);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);
}
