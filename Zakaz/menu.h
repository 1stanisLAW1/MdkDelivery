#ifndef MENU_H
#define MENU_H

#include "qmessagebox.h"
#include "qtoolbox.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QScrollArea>
#include <QVBoxLayout>

namespace Ui {
class MenU;
}

class MenU : public QDialog
{
    Q_OBJECT

public:
    explicit MenU(QWidget *parent = nullptr);
    ~MenU();

private slots:
    void setName();
    void korzina();
    void deleteBtN(int idDel);

    void addKorzina();

    void AddBtN(int idAdd);

    void history();

    void on_pushButton_9_clicked();

    void compost();

    void on_pushButton_10_clicked();

    void setImage();
public slots:
    QString pathBD(const QString &name);

private:
    Ui::MenU *ui;
    QMessageBox* msgBox;
    QSqlDatabase db1;
    QSqlDatabase db2;
    QToolBox *toolBox;
    QScrollArea *scrollArea;
};

#endif // MENU_H
