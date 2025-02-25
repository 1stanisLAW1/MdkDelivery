#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QCalendarWidget>
#include <QDate>
#include <QTextCharFormat>
#include <QInputDialog>
#include <QDir>
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
    void dateTime();

    void text();
    void textSave();

    void inf();
    void inizialization();
    void clearData();

    int countDays(  QString line);

    int currentCount( QString line);

    void on_calendarWidget_activated(const QDate &date);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    QMessageBox* msgBox;
};
#endif // MAINWINDOW_H
