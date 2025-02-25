#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include "iniloader.h"
#include "graphicmodul.h"
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsView>
#include <QTableWidget>
#include <QFont>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* mainLt = new QHBoxLayout;
    centralWidget->setLayout(mainLt);
    setCentralWidget(centralWidget);
    ////centralWidget->setStyleSheet("background-color: black;");


    scene = new GraphicsScene(this);
    modulList = new QWidget(this);
    QVBoxLayout* lt = new QVBoxLayout();
    modulList->setLayout(lt);
    table=new QTableWidget(this);
    table->setColumnCount(2);
    table->setColumnWidth(0,180);
    table->setColumnWidth(1,120);
    ////table->setStyleSheet("background-color: black;color:red;");
    table->setHorizontalHeaderLabels(QStringList()<<"Name"<<"Length");
    QVBoxLayout* leftLt = new QVBoxLayout();
    leftLt->addWidget(modulList);
    leftLt->addWidget(table);
    mainLt->addLayout(leftLt);

    mIniloader = new IniLoader(this);
    connect(mIniloader,SIGNAL(sendMessage(QString)),this,SLOT(showMessage(QString)));
    connect(&mTelesystem,SIGNAL(txtEd(QString)),this,SLOT(showMessage(QString)));


    scene->setSceneRect(QRectF(0, -25, 200, 10000));
    QGraphicsView* view = new QGraphicsView(scene);
    //ui->centralwidget->layout()->addWidget(view);
    QVBoxLayout *rightLt = new QVBoxLayout;
    textEdit =new QTextEdit(this);
    textEdit->setStyleSheet("background-color: black;");
    rightLt->addWidget(view);
    rightLt->addWidget(textEdit);

    mainLt->addLayout(rightLt);
   // centralWidget->layout()->addWidget(view);
   // centralWidget->layout()->addWidget(textEdit);


    mTelesystem.setScene(scene);
    connect(&mTelesystem, SIGNAL(updated()), this, SLOT(upDateTable()));
    getModules();
    showModules();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessage(QString str)
{
    //qDebug() << "showMessage" << str;
    textEdit->setTextColor(Qt::red);
    textEdit->append("Error:"+str);
}
void MainWindow::onBtnClicked()
{

    QObject* ob = sender();
    QPushButton* btn = qobject_cast<QPushButton*>(ob);
    if (!btn) { return; }
    QVariant v=btn->property("index");
    int indx = v.toInt();
    if (indx >= mModules.size()) { return; }
    Moduls m = mModules[indx];
    mTelesystem.appendModul(m);
    return;

}

void MainWindow::upDateTable()
{
    clearTable();
    int rowCount = 0;
    QList<Moduls*> telesystemModuls = mTelesystem.getModuls();
    for(int a =0;a<telesystemModuls.size();a++){
        rowCount++;
        rowCount += telesystemModuls.at(a)->pointsCount();

    }
    table->setRowCount(rowCount);
    int row = 0;
    int fullLen = 0;
    for(int a =0;a<telesystemModuls.size();a++){
        QTableWidgetItem *item = new QTableWidgetItem(telesystemModuls.at(a)->name());
        item->setFont(QFont("Times", 10, QFont::Bold | QFont::Black));
        table->setItem(row,0,item);
        item = new QTableWidgetItem(QString::number(fullLen));
        table->setItem(row,1,item);
        row++;
        QList<Point> points = telesystemModuls.at(a)->getPoints();
        for(int i = 0;i<points.size();i++){
            QString pointName = points.at(i).name();
            item = new QTableWidgetItem(pointName);
            table->setItem(row,0,item);
            int l = points.at(i).lent()+fullLen;
            item = new QTableWidgetItem(QString::number(l));
            table->setItem(row,1,item);
            qDebug()<<item->data(Qt::DisplayRole)<<l << pointName;
            row++;
        }
        fullLen+=telesystemModuls.at(a)->len();
    }
}
void MainWindow::getModules()
{

 //   IniLoader loader;
    QString path("./ini_files");
    QList<Moduls> moduls = mIniloader->createModuls(path);
    // for (int i = 0; i < moduls.size(); i++) {
    //     qDebug() << moduls[i].name();
    // }
    mModules.append(moduls);
    // foreach(auto m, mModules) {
    //     qDebug() << m.name() << type2str(m.upCoupling()) << type2str( m.downCoupling());
    // }
}

void MainWindow::showModules()
{
    QList<Moduls>modul;

 //   table=new QTableWidget(this);
    for(int i{0};i<mModules.size();i++)
    {
        QPushButton* btn = new QPushButton(mModules.at(i).name(),this);
        btn->setProperty("index",QVariant(i));
        connect(btn,&QPushButton::clicked,this,&MainWindow::onBtnClicked);
        modulList->layout()->addWidget(btn);
       //// btn->setStyleSheet("background-color: black;color:red;border:1px solid red;");
        //qDebug() << "addBtn";
    }

}

void MainWindow::clearTable()
{
    while (table->rowCount() > 0)
    {
        table->removeRow(0);
    }
}




