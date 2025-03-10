#include "log.h"
#include "ui_log.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

Log::Log(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Log)
{
    ui->setupUi(this);
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
    this->setWindowTitle("Registration");
}

Log::~Log()
{
    DB_Connect.close();
    delete ui;
}

void Log::on_continueBtn_clicked()
{
    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void Log::on_regBtn_clicked()
{
    if (ui->lineEdit_2->text().isEmpty() || ui->lineEdit->text().isEmpty() || ui->lineEdit_4->text().isEmpty()) {
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Ошибка");
        msgBox->setText("Поля не могут быть пустыми");
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();
        return;
    }

    DB_Connect.open();

    if (!DB_Connect.isOpen()) {
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Ошибка");
        msgBox->setText("Не удалось подключиться к базе данных!");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();
        return;
    }

    QSqlDatabase::database().transaction();

    QSqlQuery QID(DB_Connect);

    QID.prepare("SELECT 1 FROM Log WHERE LogiN = :LogiN");
    QID.bindValue(":LogiN", ui->lineEdit->text());

    if (!QID.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << QID.lastError().text();
        QSqlDatabase::database().rollback();
        DB_Connect.close();
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Ошибка");
        msgBox->setText("Ошибка проверки логина в базе данных.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();
        return;
    }

    if (QID.next()) {
        QSqlDatabase::database().rollback();
        DB_Connect.close();
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Внимание");
        msgBox->setText("Пользователь с таким логином уже зарегистрирован.");
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setStyleSheet(styleSheet);
        msgBox->exec();
        return;
    }else
    QID.prepare("INSERT INTO Log(LogiN,PassworD,NamE,image_path) VALUES(:LogiN,:PassworD,:NamE,:image_path)");
    QID.bindValue(":LogiN", ui->lineEdit->text());
    QID.bindValue(":PassworD", ui->lineEdit_4->text());
    QID.bindValue(":NamE", ui->lineEdit_2->text());
    QID.bindValue(":image_path", "/../Art/prof.jpg");

    if (!QID.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << QID.lastError().text();
        QSqlDatabase::database().rollback();
        DB_Connect.close();
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Ошибка");
        msgBox->setText("Не удалось зарегистрировать пользователя.");
        msgBox->setIcon(QMessageBox::Critical);
        return;
    }
    QSqlDatabase::database().commit();
    DB_Connect.close();

    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Успех");
    msgBox->setText("Пользователь успешно зарегистрирован!");
    msgBox->setIcon(QMessageBox::Information);

    MainWindow* mainWindow = new MainWindow();

    openDataBase(ui->lineEdit_2->text());

    mainWindow->show();

    this->close();
}

QString Log::getDatabasePath(const QString &username)
{
    QString basePath = "/../DB";
    QString dbPath = basePath + "/" + username + ".db";
    return dbPath;
}

bool Log::openDataBase(const QString &username)
{
    QString dbPath = getDatabasePath(username);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", username);
    db.setDatabaseName(QCoreApplication::applicationDirPath()+dbPath);
    QSqlQuery query(db);
    query.prepare("CREATE TABLE PIZZA ("
                  "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                  "Name TEXT NOT NULL, "
                  "price TEXT NOT NULL, "
                  "path TEXT NOT NULL);");


    if (!db.open()) {
        qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
        return false;
    }

    if (!createHistoryTable(db) || !createKorzinTable(db)) {
        return false;
    }

    return true;
}

bool Log::createHistoryTable(QSqlDatabase &db)
{
    QSqlQuery query(db);
    QString createQuery = "CREATE TABLE IF NOT EXISTS history ("
                          "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                          "Name TEXT NOT NULL, "
                          "price TEXT NOT NULL, "
                          "Data TEXT NOT NULL);";

    query.prepare(createQuery);

    if (!query.exec()) {
        qDebug() << "Ошибка создания таблицы history:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Log::createKorzinTable(QSqlDatabase &db)
{
    QSqlQuery query(db);
    QString createQuery = "CREATE TABLE IF NOT EXISTS korzin ("
                          "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                          "Name TEXT NOT NULL, "
                          "price TEXT NOT NULL, "
                          "path TEXT NOT NULL);";

    query.prepare(createQuery);

    if (!query.exec()) {
        qDebug() << "Ошибка создания таблицы korzin:" << query.lastError().text();
        return false;
    }

    return true;
}
