#include "delet.h"
#include "mainwindow.h"
#include "ui_delet.h"

delet::delet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delet)
{
    ui->setupUi(this);
}

delet::~delet()
{
    delete ui;
}

void delet::on_pushButton_clicked()
{
}

