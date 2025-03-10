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
    styleSheet =
        "QMessageBox {"
        "   background-color:rgb(0, 0, 0);"
        "}"

        "QMessageBox QLabel {"
        "   color:rgb(255, 255, 255);"
        "   font: bold 12pt;"
        "}";
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
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Ошибка");
        msgBox->setText("Ошибка выполнения запроса.");
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();

        qDebug() << query.lastError().text();
        return;
    }
    if (query.next()) {
        QString name = query.value(0).toString();
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Успех");
        msgBox->setText("Добро пожаловать, " + name + "!");
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();

        text(ui->lineEdit->text());
        close();
        mn = new MenU(this);
        mn->show();
        mn->exec();
        DB_Connect.close();
    } else {
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Ошибка");
        msgBox->setText("Неверный логин или пароль.");
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();
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
             msgBox = new QMessageBox();
            msgBox->setWindowTitle("Error!!!");
            msgBox->setText("Ошибка записи данных");
            msgBox->setStyleSheet(styleSheet);
            msgBox->exec();
            file2.close();
        }
        if(file2.error() != QFile::NoError){
             msgBox = new QMessageBox();
            msgBox->setWindowTitle("Error!!!");
            msgBox->setText("Ошибка закрытия файла");
            msgBox->setStyleSheet(styleSheet);
            msgBox->exec();
        }

        else{
        }
    }
    else {
         msgBox = new QMessageBox();
        msgBox->setWindowTitle("Error!!!");
        msgBox->setText("Не удалось открыть файл для записи");
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();
    }
}

QString MainWindow::im()
{
    return ui->lineEdit->text();
}

