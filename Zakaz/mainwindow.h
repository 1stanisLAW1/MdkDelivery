#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "log.h"
#include "menu.h"
#include <QMainWindow>
#include <QFile>
#include <QtSql>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_regBtn_clicked();

    void on_hideBtn_clicked();

    void on_continueBtn_clicked();

    void text(QString str2);
public slots:
        QString im();

private:
    Ui::MainWindow *ui;
    bool hide;
    QString executablePath;
    Log *lg;
    MenU * mn;
    QSqlDatabase DB_Connect;
    QMessageBox* msgBox;
    QString styleSheet;

};
#endif // MAINWINDOW_H
