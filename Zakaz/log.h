#ifndef LOG_H
#define LOG_H

#include <QDialog>
#include <QtSql>


namespace Ui {
class Log;
}

class Log : public QDialog
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = nullptr);
    ~Log();

private slots:
    void on_continueBtn_clicked();

    void on_regBtn_clicked();
    bool createKorzinTable(QSqlDatabase &db);
    bool createHistoryTable(QSqlDatabase &db);
public slots:
    QString getDatabasePath(const QString &username);
    bool openDataBase(const QString &username);

private:
    Ui::Log *ui;
    QSqlDatabase DB_Connect;
};

#endif // LOG_H
