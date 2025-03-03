#include "menu.h"
#include <QSqlTableModel>
#include "mainwindow.h"
#include "qsqlerror.h"
#include "ui_menu.h"
#include "QFile"
#include "settingwindow.h"

MenU::MenU(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenU)
{
    ui->setupUi(this);

    MainWindow mw;

    msgBox = new QMessageBox(this);

    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath;
    scrollArea = new QScrollArea(ui->widget_2); // widget это виджет в ui. Если нет, то this.

    setName();
    setImage();
    compost();

    QString pathBd = pathBD(ui->label_2->text());
    qDebug()<<"pathBD - "<<pathBd;

    db2 = QSqlDatabase::addDatabase("QSQLITE","Ququ");
    db2.setDatabaseName(QCoreApplication::applicationDirPath()+"/../DB/Zak.db");
    if(!db2.open()){
        QMessageBox::warning(0,"error",db2.lastError().text());
    }

    db1 = QSqlDatabase::addDatabase("QSQLITE");
    //db1.setDatabaseName(QCoreApplication::applicationDirPath()+pathBd);
    db1.setDatabaseName(QCoreApplication::applicationDirPath()+pathBd);
    if (!db1.open()) {
        qDebug() << "Ошибка открытия базы данных:" << db1.lastError().text();
        return;
    }

    korzina();

    history();

    ui->tableView_2->setColumnHidden(0, true);
}

MenU::~MenU()
{
    db2.close();
    db1.close();
    delete ui;
}

void MenU::setName()
{

    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath = executablePath + "/../TxT/Log.txt";

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ui->label_2->setText(stream.readAll());
        file.close();
        msgBox->setWindowTitle("Error!!!");
        msgBox->setText("Не удалось открыть файл для записи");
        msgBox->exec();
    }
    QTextStream stream(&file);
    QString log = stream.readAll();
    if (log.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Файл с именем пуст: " + filePath);
        msgBox.exec();
        return;
    }
    qDebug()<<log;

    QSqlQuery queryAdd(db2);
    queryAdd.prepare("SELECT Name FROM Log where LogiN = :LogiN");
    queryAdd.bindValue(":LogiN",log);
    if (!queryAdd.exec()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Ошибка выполнения SQL-запроса: " + queryAdd.lastError().text());
        msgBox.exec();
        return;
    }

    if (queryAdd.next()) {
        QString name = queryAdd.value(0).toString();
        ui->label_2->setText(name);
        qDebug() << "name " << name;
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Не найдено изображение для логина: " + log);
        msgBox.exec();
    }


}

void MenU::korzina()
{
    QString executablePath = QCoreApplication::applicationDirPath();
    scrollArea->setWidgetResizable(true);

    // Создаем контейнер для содержимого
    QWidget *contentWidget = new QWidget(scrollArea);

    QVBoxLayout *mainLayout = new QVBoxLayout(contentWidget);

    // Создаем QToolBox для организации содержимого
    QToolBox *toolBox = new QToolBox(contentWidget);

    // Виджет для всех пицц
    QWidget *allPizzaWidget = new QWidget();
    QVBoxLayout *allPizzaLayout = new QVBoxLayout(allPizzaWidget);

    QSqlQuery query(db1);
    if (!query.prepare("SELECT id, name, price, path FROM korzin")) {
        qDebug() << "Ошибка подготовки запроса:" << query.lastError().text();
        return;
    }

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString imagePath = executablePath + query.value(3).toString();
        QImage image(imagePath);
        if (image.isNull()) {
            qDebug() << "Ошибка загрузки изображения:" << imagePath;
            continue;
        }

        QPixmap pixmap = QPixmap::fromImage(image);

        // Виджет для одной пиццы
        QWidget *pizzaWidget = new QWidget(allPizzaWidget);
        QVBoxLayout *pizzaLayout = new QVBoxLayout(pizzaWidget);

        QLabel *imageLabel = new QLabel(pizzaWidget);
        imageLabel->setPixmap(pixmap);
        imageLabel->setScaledContents(true);
        imageLabel->setMinimumSize(430, 250);
        imageLabel->setMaximumSize(450, 250);

        QLabel *priceLabel = new QLabel(query.value(2).toString(), pizzaWidget);
        priceLabel->setMinimumSize(430, 40);
        priceLabel->setMaximumSize(430, 40);
        priceLabel->setAlignment(Qt::AlignCenter);

        QLabel *nameLabel = new QLabel(query.value(1).toString(), pizzaWidget);
        nameLabel->setFixedSize(430, 40);
        nameLabel->setAlignment(Qt::AlignCenter);

        QPushButton *addBtn = new QPushButton("Купить");
        QPushButton *deleteBtn = new QPushButton("Удалить");

        int id = query.value(0).toInt();
        connect(deleteBtn, &QPushButton::clicked, [this, id]() { deleteBtN(id); });
        connect(addBtn, &QPushButton::clicked, [this, id]() { AddBtN(id); });

        // Добавляем элементы в макет пиццы
        pizzaLayout->addWidget(imageLabel);
        pizzaLayout->addWidget(priceLabel);
        pizzaLayout->addWidget(nameLabel);
        pizzaLayout->addWidget(addBtn);
        pizzaLayout->addWidget(deleteBtn);

        // Добавляем виджет пиццы в общий макет
        allPizzaLayout->addWidget(pizzaWidget);

        addBtn->setStyleSheet("QPushButton { background-color: black; color:white; border: 2px solid rgb(255, 255, 255);solid: rgb(255, 255, 255);"
                              "border-radius:15px;"
                              "max-height:40px;"
                              "max-width:430px;"
                              "min-height:40px;"
                              "min-width:430px;}");
        deleteBtn->setStyleSheet("QPushButton { background-color: black; color:white; border: 2px solid rgb(255, 255, 255);solid: rgb(255, 255, 255);"
                                 "border-radius:15px;"
                                 "max-height:40px;"
                                 "max-width:430px;"
                                 "min-height:40px;"
                                 "min-width:430px;}");
    }

    // Устанавливаем макет для allPizzaWidget
    allPizzaWidget->setLayout(allPizzaLayout);

    // Добавляем allPizzaWidget в toolBox
    toolBox->addItem(allPizzaWidget, "Корзина");

    // Добавляем toolBox в основной макет
    mainLayout->addWidget(toolBox);

    // Устанавливаем макет для contentWidget
    contentWidget->setLayout(mainLayout);

    // Устанавливаем contentWidget в scrollArea
    scrollArea->setWidget(contentWidget);

    // Добавляем scrollArea в ui->widget_2
    QVBoxLayout *layout = new QVBoxLayout(ui->widget_2);
    layout->addWidget(scrollArea);
    ui->widget_2->setLayout(layout);

    scrollArea->setStyleSheet(
        "QScrollArea {"
        "    background-color: black;"
        "    color: white;"
        "}"
        "QScrollBar:vertical {"
        "    background-color: black;"
        "    width: 15px;"
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background-color: white;"
        "    min-height: 20px;"
        "    border-radius: 7px;"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    background-color: black;"
        "    height: 0px;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "    background-color: black;"
        "}"
        "QScrollBar:horizontal {"
        "    background-color: black;"
        "    height: 15px;"
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:horizontal {"
        "    background-color: white;"
        "    min-width: 20px;"
        "    border-radius: 7px;"
        "}"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
        "    background-color: black;"
        "    width: 0px;"
        "}"
        "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
        "    background-color: black;"
        "}"
        );

    toolBox->setStyleSheet(
        "QToolBox {"
        "    background-color: black;"
        "    color: white;"
        "}"
        "QToolBox::tab {"
        "    background-color: black;"
        "    color: white;"
        "    border: 1px solid white;"
        "}"
        "QToolBox::tab:selected {"
        "    background-color: white;"
        "    color: black;"
        "}"
        );

    contentWidget->setStyleSheet("QWidget{background-color: black;"
                                 "color: white;}");
    allPizzaWidget->setStyleSheet("QWidget{background-color: black;"
                                  "color: white;}");

}

void MenU::deleteBtN(int idDel)
{
    QSqlQuery query(db1);
    query.prepare("DELETE FROM korzin WHERE id = :id");
    query.bindValue(":id", idDel);

    if (!query.exec()) {
        QMessageBox::critical(this, "Не удалось удалить запись из базы данных: " + query.lastError().text(), 0);
        return;
    }


//не трогать
QMessageBox::information(this, "Успех", "Запись удалена.");
korzina();
}

void MenU::addKorzina()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    if (!btn) {
        qDebug() << "Error: sender is not a QPushButton";
        return;
    }

    // Проверяем открыты ли обе базы данных
    if (!db2.isOpen()) {
        qDebug() << "Основная база данных не открыта:" << db2.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Основная база данных не открыта.");
        return;
    }

    if (!db1.isOpen()) {
        qDebug() << "Вторичная база данных не открыта:" << db1.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Вторичная база данных не открыта.");
        return;
    }

    // Начинаем транзакцию для обеих баз данных
    if (db2.transaction() && db1.transaction()) {
        QSqlQuery query(db2);
        query.prepare("SELECT name, price, path FROM PIZZA WHERE name = :name");
        query.bindValue(":name", btn->text());

        if (!query.exec()) {
            db2.rollback();
            db1.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
            return;
        }

        if (!query.next()) {
            db2.rollback();
            db1.rollback();
            QMessageBox::critical(this, "Ошибка", "Пицца не найдена.");
            return;
        }

        QString price = query.value("price").toString();
        QString path = query.value("path").toString();

        QSqlQuery query2(db1);
        query2.prepare("INSERT INTO korzin(name, price,path) VALUES(:name, :price,:path)");
        query2.bindValue(":name", btn->text());
        query2.bindValue(":price", price);
        query2.bindValue(":path", path);

        if (!query2.exec()) {
            db2.rollback();
            db1.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить запись в базу данных: " + query2.lastError().text());
            return;
        }

        db2.commit();
        db1.commit(); // Коммитим изменения в обеих базах данных
        QMessageBox::information(this, "Успех", "Запись успешно добавлена в корзину.");
        korzina();
    } else {
        qDebug() << "Transaction error: " << db2.lastError().text() << " | " << db1.lastError().text();
    }

    btn->setStyleSheet("QPushButton { background-color: black; color:white; border: 2px solid rgb(255, 255, 255);solid: rgb(255, 255, 255);"
                       "border-radius:15px;"
                       "max-height:40px;"
                       "max-width:430px;"
                       "min-height:40px;"
                       "min-width:430px;}");
}

void MenU::AddBtN(int idAdd)
{
    // add

//    QSqlDatabase db = QSqlDatabase::database();

    QSqlQuery queryAdd(db1);
    queryAdd.prepare("SELECT name,price FROM korzin where id = :id");
    queryAdd.bindValue(":id",idAdd);
    qDebug()<<":|"<<idAdd;

    if (!queryAdd.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + queryAdd.lastError().text());
        return;
    }

    if (!queryAdd.next()) {
        QMessageBox::warning(this, "Предупреждение", "Запись с указанным ID не найдена.");
        return;
    }

    QString name = queryAdd.value(0).toString();
    QString price = queryAdd.value(1).toString();
    QString currentTime = QTime::currentTime().toString("HH:mm:ss");
    QString currentDate = QDate::currentDate().toString("d'.'MM.yyyy");
    QString dt = currentDate+"-"+currentTime;

    QSqlQuery query(db1);
    query.prepare("INSERT INTO history(name, price,Data) VALUES(:name, :price,:dt)");
    query.bindValue(":name", name);
    query.bindValue(":price", price);
    query.bindValue(":dt", dt);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить запись из базы данных: " + query.lastError().text());
        qDebug()<<"Не удалось добавить запись из базы данных: " << query.lastError().text();
        return;
    }
    db1.commit();


//не трогать
QMessageBox::information(this, "Успех", "Запись добавлена.");
history();
}

void MenU::history()
{
    QSqlTableModel *model1 = new QSqlTableModel(nullptr, db1);
    model1->setTable("history");
    model1->select();

    if (model1->lastError().isValid()) {
        QMessageBox::warning(nullptr, "Ошибка", model1->lastError().text());
        return;
    }
    ui->tableView_2->setModel(model1);
    ui->tableView_2->setColumnWidth(1,200);
    ui->tableView_2->setColumnWidth(2,100);
    ui->tableView_2->setColumnWidth(3,200);
    ui->tableView_2->setMaximumWidth(550);
}


void MenU::on_pushButton_9_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setQuery("DELETE FROM korzin WHERE id");
    korzina();
}

void MenU::compost()
{

    QString executablePath = QCoreApplication::applicationDirPath();
    QScrollArea *scrollArea = new QScrollArea(ui->widget); // widget это виджет в ui. Если нет, то this.

    scrollArea->setWidgetResizable(true);
    QWidget *contentWidget = new QWidget(scrollArea); //  Родитель - scrollArea
    QVBoxLayout *mainLayout = new QVBoxLayout(contentWidget);
    QToolBox *toolBox = new QToolBox(contentWidget);

    QWidget *allPizzaWidget = new QWidget();
    QVBoxLayout *allPizzaLayout = new QVBoxLayout(allPizzaWidget);
    //while
    QSqlQuery query(db2);
    query.prepare("SELECT id,name, price,path FROM PIZZA");
    if(!query.exec()){
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }else{
        while (query.next()) {
            QString imagePath;
            imagePath = executablePath + query.value(3).toString();
            QImage image(imagePath);
            if (image.isNull()){
                qDebug()<<"Error loading image: "<<imagePath;
                continue;
            }
            QPixmap pixmap = QPixmap::fromImage(image);

            // Создаем виджет для каждой пиццы
            QWidget *pizzaWidget = new QWidget(allPizzaWidget); // Теперь pizzaWidget - потомок allPizzaWidget
            QVBoxLayout *pizzaLayout = new QVBoxLayout(pizzaWidget);

            QLabel *label1 = new QLabel(pizzaWidget); //  Родитель - pizzaWidget
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
            label1->setMinimumSize(450, 250);
            label1->setMaximumSize(450, 250);

            QLabel *label2 = new QLabel(query.value(2).toString(), pizzaWidget); //  Родитель - pizzaWidget
            label2->setMinimumSize(450, 40);
            label2->setMaximumSize(450, 40);
            label2->setAlignment(Qt::AlignCenter);

            QPushButton *button = new QPushButton(query.value(1).toString(), pizzaWidget); //  Родитель - pizzaWidget


            connect(button, &QPushButton::clicked, this, &MenU::addKorzina); // Используйте &MenU::addKorzina

            pizzaLayout->addWidget(label1);
            pizzaLayout->addWidget(label2);
            pizzaLayout->addWidget(button);
            pizzaWidget->setLayout(pizzaLayout);

            allPizzaLayout->addWidget(pizzaWidget); // Добавляем виджет пиццы во весь виджет
            button->setStyleSheet("QPushButton { background-color: black; color:white; border: 2px solid rgb(255, 255, 255);solid: rgb(255, 255, 255);"
                                  "border-radius:15px;"
                                  "max-height:40px;"
                                  "max-width:430px;"
                                  "min-height:40px;"
                                  "min-width:430px;}");
        }
        allPizzaWidget->setLayout(allPizzaLayout); // Set the layout for the allPizzaWidget

        toolBox->addItem(allPizzaWidget, "Пиццы");

        mainLayout->addWidget(toolBox);
        contentWidget->setLayout(mainLayout);

        // 4. Устанавливаем contentWidget в QScrollArea
        scrollArea->setWidget(contentWidget);

        // 5. Добавляем QScrollArea в ui->widget
        QVBoxLayout *layout = new QVBoxLayout(ui->widget);
        layout->addWidget(scrollArea);
        ui->widget->setLayout(layout);
    }

    scrollArea->setStyleSheet(
        "QScrollArea {"
        "    background-color: black;"
        "    color: white;"
        "}"
        "QScrollBar:vertical {"
        "    background-color: black;"
        "    width: 15px;"
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background-color: white;"
        "    min-height: 20px;"
        "    border-radius: 7px;"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    background-color: black;"
        "    height: 0px;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "    background-color: black;"
        "}"
        "QScrollBar:horizontal {"
        "    background-color: black;"
        "    height: 15px;"
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:horizontal {"
        "    background-color: white;"
        "    min-width: 20px;"
        "    border-radius: 7px;"
        "}"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
        "    background-color: black;"
        "    width: 0px;"
        "}"
        "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
        "    background-color: black;"
        "}"
        );
    toolBox->setStyleSheet(
        "QToolBox {"
        "    background-color: black;"
        "    color: white;"
        "}"
        "QToolBox::tab {"
        "    background-color: black;"
        "    color: white;"
        "    border: 1px solid white;"
        "}"
        "QToolBox::tab:selected {"
        "    background-color: white;"
        "    color: black;"
        "}"
        );
    allPizzaWidget->setStyleSheet("QWidget{background-color: black;"
                                  "color: white;}");
    contentWidget->setStyleSheet("QWidget{background-color: black;"
                                 "color: white;}");
}


void MenU::on_pushButton_10_clicked()
{
    settingWindow sw;
    this->hide();
    sw.show();
    sw.exec();
}

void MenU::setImage()
{
    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath = executablePath + "/../TxT/Log.txt";

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ui->label_2->setText(stream.readAll());
        file.close();
        msgBox->setWindowTitle("Error!!!");
        msgBox->setText("Не удалось открыть файл для записи");
        msgBox->exec();
    }
    QTextStream stream(&file);
    QString log = stream.readAll();
    if (log.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox { background-color: black; color:white;}");
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Файл с именем пуст: " + filePath);
        msgBox.exec();
        return;
    }
    qDebug()<<log;

    QSqlQuery queryAdd(db2);
    queryAdd.prepare("SELECT image_path FROM Log where LogiN = :LogiN");
    queryAdd.bindValue(":LogiN",log);
    if (!queryAdd.exec()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Ошибка выполнения SQL-запроса: " + queryAdd.lastError().text());
        msgBox.exec();
        return;
    }

    if (queryAdd.next()) {
        QString imagePath = queryAdd.value(0).toString();
        QImage image(imagePath);
        QPixmap pixmap = QPixmap::fromImage(image);
        ui->label_4->setPixmap(pixmap);
        ui->label_4->setScaledContents(true);
        qDebug() << "path " << imagePath;
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Не найдено изображение для логина: " + log);
        msgBox.exec();
    }

}

QString MenU::pathBD(const QString &name)
{
    QString basePath = "/../DB";
    QString path = basePath + "/" + name + ".db";
    return path;
}

