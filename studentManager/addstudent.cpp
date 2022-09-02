#include "addstudent.h"
#include "ui_addstudent.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QList>
#include <QAbstractButton>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

addstudent::addstudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addstudent)
{
    ui->setupUi(this);
}

addstudent::~addstudent()
{
    delete ui;
}


void addstudent::on_btn_ok_clicked()
{
    QString name = this->ui->le_name->text();
    QString id = this->ui->le_id->text();
    QString sex = this->ui->sexGroup->checkedButton()->text();

    QList<QAbstractButton *> ins_list = this->ui->insGroup->buttons();
    QString ins;
    int i = 0;
    for (i = 0; i < ins_list.length(); i++) {
        QAbstractButton *che = ins_list.at(i);
        if (che->isChecked()) {
            ins += che->text() + " ";
        }
    }

    QString age = this->ui->cbb_age->currentText();
    QString dev = this->ui->cbb_y->currentText();



    QString content = name + '\n' + id + '\n' + sex + '\n' + age + '\n' + dev + '\n' + ins;
    QString cnt = name + " " + id + " " + sex + " " + age + " " + dev + " " + ins + "\n";
    if (name.length() < 1 || id.length() < 1 || ins.length() < 1) {
        QMessageBox::critical(this, "错误", "信息填写不完整， 请重新填写", "确定");
    } else {
        int ret = QMessageBox::question(this, "请确认信息", content, "确认", "取消", "不知道");
        if (ret == 0) {
            clearUserInterface();
            writeToFile(cnt);
        }
    }
}

void addstudent::clearUserInterface() {
    this->ui->le_name->clear();
    this->ui->le_id->clear();
    this->ui->rbtn_male->setChecked(true);
    this->ui->cbb_age->setCurrentIndex(0);
    this->ui->cbb_y->setCurrentIndex(0);
    QList<QAbstractButton *> ins_list = this->ui->insGroup->buttons();
    int i = 0;
    for (i = 0; i < ins_list.length(); i++) {
        QAbstractButton *box = ins_list.at(i);
        box->setChecked(false);
    }
    this->ui->le_name->setFocus();
}

void addstudent::writeToFile(QString cnt) {
    QFile file("student.txt");
    if (! file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "文件打开失败，信息没有保存", "确定");
        return ;
    }
    QTextStream out(&file);
    out << cnt;
}


void addstudent::on_btn_cancal_clicked()
{
    this->close();
}
