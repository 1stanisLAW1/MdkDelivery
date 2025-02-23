#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_menu.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <settingwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hide = true;
    executablePath = QCoreApplication::applicationDirPath();
    QString iconPath = executablePath + "/../Art/noeyes.png";
    ui->hideBtn->setIcon(QIcon(iconPath));

    DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName(QCoreApplication::applicationDirPath()+"/../DB/Zak.db");
    if(!DB_Connect.open()){
        QMessageBox::warning(0,"error",DB_Connect.lastError().text());
    }


    msgBox = new QMessageBox(this);
}

MainWindow::~MainWindow()
{
    DB_Connect.close();
    delete ui;
}

void MainWindow::on_regBtn_clicked()
{
    close();
    lg = new Log(this);
    lg->show();
    lg->exec();
}

void MainWindow::on_hideBtn_clicked()
{
    executablePath = QCoreApplication::applicationDirPath();
    if (hide == true) {
        ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
        QString iconPath = executablePath + "/../Art/eyes.png";
        if (!QFile::exists(iconPath)) {
            qWarning() << "Иконка не найдена:" << iconPath;
        } else {
            ui->hideBtn->setIcon(QIcon(iconPath));
        }
        hide = false;
    } else {
        ui->lineEdit_4->setEchoMode(QLineEdit::Password);
        QString iconPath = executablePath + "/../Art/noeyes.png";
        if (!QFile::exists(iconPath)) {
            qWarning() << "Иконка не найдена:" << iconPath;
        } else {
            ui->hideBtn->setIcon(QIcon(iconPath));
        }
        hide = true;
    }
}



void MainWindow::on_continueBtn_clicked()
{
    QString login = ui->lineEdit->text();
    QString password  = ui->lineEdit_4->text();

    QSqlQuery query(DB_Connect);
    query.prepare("SELECT NamE FROM Log WHERE LogiN = :login AND PassworD = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса.");
        qDebug() << query.lastError().text();
        return;
    }
    if (query.next()) {
        QString name = query.value(0).toString();
        QMessageBox::information(this, "Успех", "Добро пожаловать, " + name + "!");
        text(ui->lineEdit->text());
        close();
        mn = new MenU(this);
        mn->show();
        mn->exec();
        DB_Connect.close();
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль.");
    }
}

void MainWindow::text(QString str2)
{
    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath2 = executablePath + "/../TxT/Log.txt";
    QFile file2(filePath2);
    file2.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file2.close();

    if(file2.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file2);
        stream << str2;
        if(stream.status() != QTextStream::Ok){
            qDebug() << "Ошибка записи данных: " << filePath2 << stream.status();
            msgBox->setWindowTitle("Error!!!");
            msgBox->setText("Ошибка записи данных");
            msgBox->exec();
            file2.close();
        }
        if(file2.error() != QFile::NoError){
            msgBox->setWindowTitle("Error!!!");
            msgBox->setText("Ошибка закрытия файла");
            msgBox->exec();
        }

        else{
        }
    }
    else {
        msgBox->setWindowTitle("Error!!!");
        msgBox->setText("Не удалось открыть файл для записи");
        msgBox->exec();
    }
}

QString MainWindow::im()
{
    return ui->lineEdit->text();
}

