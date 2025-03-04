#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    msgBox = new QMessageBox(this);
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::dateTime);
    connect(timer2,&QTimer::timeout,this,&MainWindow::inf);
    timer->start(1000);
    timer2->start(3600000);
    inizialization();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::dateTime()
{
    QString currentTime = QTime::currentTime().toString("HH:mm:ss");
    ui->label->setText(currentTime);
    QString currentDate = QDate::currentDate().toString("d'.'MM.yyyy");
    ui->label_2->setText(currentDate);
}

void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    bool ok;
    QString st = QInputDialog::getText(this, "Заметка", "Введите текст:", QLineEdit::Normal,"", &ok);
    QString str = date.toString("d'.'MM.yyyy - ");
    str+=st;
    QStringList line = ui->pte->toPlainText().split("\n");
    if(ok){
        line.removeAll("");
        ui->pte->appendPlainText(str);
        textSave();
    }
}
void MainWindow::text()
{
    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath = executablePath + "/../Text/save.txt";

    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ui->pte->appendPlainText(stream.readAll());
        file.close();
    } else {
        msgBox->setWindowTitle("Error!!!");
        msgBox->setText("Не удалось открыть файл для записи");
        msgBox->exec();
    }
}

void MainWindow::textSave()
{
    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath = executablePath + "/../Text/save.txt";
    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << ui->pte->toPlainText();
        if(stream.status() != QTextStream::Ok){
            qDebug() << "Ошибка записи данных: " << filePath << stream.status();
            msgBox->setWindowTitle("Error!!!");
            msgBox->setText("Ошибка записи данных");
            msgBox->exec();
            file.close();
        }
        if(file.error() != QFile::NoError){
            msgBox->setWindowTitle("Error!!!");
            msgBox->setText("Ошибка закрытия файла");
            msgBox->exec();
        }

        else{
            //qDebug() << "Файл успешно сохранен: " << filePath;
        }
    }
    else {
        msgBox->setWindowTitle("Error!!!");
        msgBox->setText("Не удалось открыть файл для записи");
        msgBox->exec();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    QStringList lines = ui->pte->toPlainText().split("\n", Qt::SkipEmptyParts);
    QString st = QInputDialog::getText(this, "Заметка", "Введите текст:", QLineEdit::Normal,"", &ok);
    if(!ok)
        return;
    QString textToReplace = ui->lineEdit->text(); // Получаем текст, который нужно заменить

    if(textToReplace.isEmpty()){
        QMessageBox::critical(this, "Ошибка", "Введите строку которую нужно заменить");
        return;
    }
    else{
        QString newL = "";
        for(QString &line:lines){
            if(line!=textToReplace){
                newL+=line+"\n";
            }
            else{
                line =st;
                newL+=line+"\n";
            }
        }
        if(newL.isEmpty()){
            ui->pte->clear();
        }
        else{
            ui->pte->clear();
            ui->pte->appendPlainText(newL.trimmed());
        }
    }
    textSave();
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_clicked()
{
    QStringList lines = ui->pte->toPlainText().split("\n", Qt::SkipEmptyParts);
    QString textLineEdit = ui->lineEdit->text();
    QString newL = "";
    for(QString &line:lines){
        if(line!=textLineEdit){
            newL+=line+"\n";
        }
    }
    if(newL.isEmpty()){
        ui->pte->clear();
    }
    else{
        ui->pte->clear();
        ui->pte->appendPlainText(newL.trimmed());
    }
    textSave();
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pte->clear();
    textSave();
}

void MainWindow::inf(){
    //проверка на то есть ли сегодня какая то запланированная дата
    QString currentDate = QDate::currentDate().toString("d'.'MM.yyyy");
    QStringList lines = ui->pte->toPlainText().split("\n", Qt::SkipEmptyParts);
    for(QString &line:lines){
        QString newL = "";
        QString note = "";
        for(int k = 0;k<10;k++){
            newL +=line[k];
        }
        for(int i = 11;i<line.size();i++){
            note+=line[i];
        }
        if(newL == currentDate ){
            //Уведомление
            QMessageBox::information(this, "Информация", "Внимание у вас на сегодня запланирована задача"+note);// описать что за задача
        }
    }
    clearData();

}

void MainWindow::inizialization()
{
    dateTime();
    text();
    inf();
}

void MainWindow::clearData()
{
    QStringList lines = ui->pte->toPlainText().split("\n", Qt::SkipEmptyParts);
    QString newL ="";
    int a;
    int b;
    for(QString &line:lines){
        a = countDays(line);
        b = currentCount(QDate::currentDate().toString("d'.'MM.yyyy"));
        if(a<b){
            qDebug()<<"curr "<<b<<" day "<<a;
        }
        else{
            newL+=line+"\n";
        }
    }
    if(newL.isEmpty()){
        ui->pte->clear();
    }
    else{
        ui->pte->clear();
        ui->pte->appendPlainText(newL.trimmed());
    }
    textSave();
    ui->lineEdit->clear();
}

int MainWindow::countDays(QString line)
{
    int d;
    int m;
    int y;
    QString dd = "";
    QString mm = "";
    QString yy = "";
    dd+=line[0];
    dd+=line[1];
    mm+=line[3];
    mm+=line[4];
    yy += line[6];
    yy += line[7];
    yy += line[8];
    yy += line[9];
    d = dd.toInt();
    m = mm.toInt();
    y = yy.toInt();

    return d+m+y;
}

int MainWindow::currentCount(QString line)
{
    int d;
    int m;
    int y;
    QString dd = "";
    QString mm = "";
    QString yy = "";
    dd+=line[0];
    dd+=line[1];
    mm+=line[3];
    mm+=line[4];
    yy += line[6];
    yy += line[7];
    yy += line[8];
    yy += line[9];
    d = dd.toInt();
    m = mm.toInt();
    y = yy.toInt();

    return d+m+y;
}

