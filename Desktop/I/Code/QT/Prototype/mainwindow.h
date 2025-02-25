#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "iniloader.h"
#include "moduls.h"
#include "qtextedit.h"
#include "telesystem.h"
#include <QTableWidget>
#include "graphicsscene.h"

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
    void getModules();
    void showModules();

public slots:
    void showMessage(QString);

private slots:
    void onBtnClicked();
    void upDateTable();

private:
    Ui::MainWindow *ui;
    GraphicsScene *scene;
    QTableWidget *table;
    QWidget* modulList;
    QTextEdit *textEdit;





    QList <Moduls> mModules;

    void clearTable();
    TeleSystem mTelesystem;
    IniLoader* mIniloader;
    // void fullLenMod();

};
#endif // MAINWINDOW_H
