#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include "QMessageBox"
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QInputDialog>
#include <QtSql>

namespace Ui {
class settingWindow;
}

class settingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit settingWindow(QWidget *parent = nullptr);
    ~settingWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::settingWindow *ui;
    QMessageBox* msgBox;
    QSqlDatabase DB_Connect;
    QSqlDatabase db1;
};

#endif // SETTINGWINDOW_H
