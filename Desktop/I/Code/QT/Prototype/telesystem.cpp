#include "telesystem.h"
#include "moduls.h"
#include "qgraphicsview.h"
#include "qlabel.h"
#include "qmainwindow.h"
#include "qmenu.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidgetAction>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>
#include <QIntValidator>
#include <QFile>
#include <QGraphicsWidget>

TeleSystem::TeleSystem() {
}

bool TeleSystem::appendModul(Moduls m)
{
    bool b = Moduls::exemCoupling(lastCoupling(),m.upCoupling());
    if(b==true){
        Moduls *gM = new Moduls(m);
        mModules.append(gM);
        drawModul(gM);
        emit updated();
    }
    info();
    //graphicsInfo();
    //pointInfo();
    return b;

}

Moduls::TypeCoupling TeleSystem::lastCoupling()
{
    if(mModules.isEmpty()){
        return Moduls::TypeCoupling::None;
    }
    return mModules.last()->downCoupling();
}

void TeleSystem::info()
{
    int result = 0;
    qDebug() << "TELESYSTEM HAS " << mModules.size() << "Modules";
    for(int i = 0;i<mModules.size();i++)
    {
        qDebug()<< i + 1 << mModules.at(i)->name()<<mModules.at(i)->len();
        result +=mModules.at(i)->len();
    }
    qDebug() << "FUll length" <<result;
}

void TeleSystem::graphicsInfo() const
{
    foreach(auto mod, gMod) {
        qDebug() << mod->info();
    }
}

void TeleSystem::drawModul(Moduls*mod)
{
    GraphicModul* item=new GraphicModul(mod);
    gMod.append(item);
    graphicsScene->addItem(item);
    double y = 0;
    if (mModules.size() > 1) {
        y = lenToModule(mModules.size() - 2);
    }
        item->setY(y);
    qDebug() << "drawModul" << fullLen() << lenToModule(mModules.size() - 1);
    graphicsScene->update(graphicsScene->sceneRect());
}
double TeleSystem::fullLen() const
{
    double result = 0;
    for(int i = 0;i<mModules.size();i++)
    {
        //mModules.at(i)->len() == mModules.length();
        result +=mModules.at(i)->len();
    }
    return result;
}
double TeleSystem::lenToModule(int ind) const
{
    double result = 0;
    if (mModules.size() < ind) { return .0; }
    for (int i = 0; i <= ind; i++) {
        result +=mModules.at(i)->len()/10;
    }
    return result;
}

void TeleSystem::setScene(GraphicsScene *s)
{
    if (!s) { return; }
    graphicsScene = s;
    connect(graphicsScene,SIGNAL(itemSelect(QList<QGraphicsItem*>)),this,SLOT(acceptsItem(QList<QGraphicsItem*>)));
    connect(graphicsScene,SIGNAL(lkm(QList<QGraphicsItem*>)),this,SLOT(pointShow(QList<QGraphicsItem*>)));
}

void TeleSystem::acceptsItem(QList<QGraphicsItem*> graphItems)
{
    //QCursor *pos = new QCursor();
    if (graphItems.empty() || graphItems.size() > 1) { return; }
    int i = 0;
    while(i < gMod.size()){
        if (gMod[i] == graphItems.first()) {
            qDebug()<<"List Items "<<gMod.at(i)->info();
            break;
        }
        i++;
    }
    modifiedIndex = i;
    QCursor *pos = new QCursor();
    qDebug() << "modules" << mModules.size() << i;
    QMenu *contextMenu = new QMenu();
    if (mModules[modifiedIndex]->variableLength()) {
        QAction *act = contextMenu->addAction("Изменить");
        connect(act, SIGNAL(triggered()), this, SLOT(dialog()));
    }
    else{
        emit txtEd( "Item can't modify its length");
    }

    QAction *act2 = contextMenu->addAction("Удалить модуль");
    QAction *act3 = contextMenu->addAction("Очистить конструктор");

    connect(act2, SIGNAL(triggered()), this, SLOT(remove()));
    connect(act3, SIGNAL(triggered()), this, SLOT(clearScene()));
    contextMenu->exec(pos->pos());
    delete(pos);
}

void TeleSystem::dialog()
{
    if (modifiedIndex < 0) { return; }
    QDialog *dialog = new QDialog();
    QString lblStr = QString("Введите длину: от %1  до %2")
                         .arg(mModules.at(modifiedIndex)->minL())
                         .arg(mModules.at(modifiedIndex)->maxL());
    QString ed = QString("%1")
                          .arg(mModules.at(modifiedIndex)->len());
    QLabel* lbl = new QLabel(lblStr,dialog);
    QLineEdit* edt = new QLineEdit(ed,dialog);
    QIntValidator *valid = new QIntValidator(mModules.at(modifiedIndex)->minL(),mModules.at(modifiedIndex)->maxL(),this);
    edt->setValidator(valid);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel, dialog);
    connect(buttonBox, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, dialog, &QDialog::reject);
    dialog->setMinimumHeight(400);
    dialog->setMinimumWidth(400);
    QVBoxLayout *lt = new QVBoxLayout();
    lt->addWidget(lbl);
    lt->addWidget(edt);
    lt->addWidget(buttonBox);
    dialog->setLayout(lt);

    if (dialog->exec() != QDialog::Accepted) {
        return;
    }
    QString str = edt->text();
    int length = str.toInt();
    if(length>mModules.at(modifiedIndex)->maxL()||length<mModules.at(modifiedIndex)->minL()){
        emit txtEd("Проверьте введеную длину");
        return;
    }
    else {
        int curLen = mModules.at(modifiedIndex)->len();
        int result = curLen-length;
        length = mModules.at(modifiedIndex)->setCurrentLength(length);
        if(result<0){
        for(int i = modifiedIndex + 1;i<gMod.size();i++){
            auto pos = gMod[i]->pos();
            gMod.at(i)->setPos(0,pos.y() - result/10);
            emit updated();
        }
        }
        else if(result>0){
            for(int i = modifiedIndex + 1;i<gMod.size();i++){
                auto pos = gMod[i]->pos();
                gMod.at(i)->setPos(0,pos.y() - result/10);
                emit updated();
            }
        }
        else{
            return;
        }

    }
    QList<Point> points = mModules.at(modifiedIndex)->getPoints();
   // qDebug()<<"Good "<<length;
    for(int i =0;i<points.size();i++){
        if(length>points.at(i).lent()){
            length = mModules.at(modifiedIndex)->setCurrentLength(length);
        }
        else{
            emit txtEd("Длинна не может быть меньше позиции точки");
            break;
        }
    }
    modifiedIndex = -1;

}

void TeleSystem::remove()
{
    if (modifiedIndex < 0||modifiedIndex>=mModules.size()) { return; }
    qDebug()<<modifiedIndex;
    if(gMod.size()>=2&&modifiedIndex==0){
        emit txtEd("Удаление невозможно");
        qDebug()<<"rot_Togo_shatal";
    }
    else if (modifiedIndex==mModules.size()-1){
        qDebug()<<"Можно удалить";
        graphicsScene->removeItem(gMod.at(modifiedIndex));
        QList<QGraphicsItem*> items = mAdditionalItems.take(gMod[modifiedIndex]);
        if(items.empty()){return;}
        for(int i = items.size() - 1; i >= 0; i--) {
            graphicsScene->removeItem(items[i]);
            delete(items[i]);
        }
        gMod.remove(modifiedIndex);
        mModules.remove(modifiedIndex);
        qDebug()<<"delet";
        emit updated();
    }
    else {
        qDebug()<<"Можно удалить";
        int firstItem = modifiedIndex-1;
        int nextItem = modifiedIndex+1;
        if(Moduls::exemCoupling(mModules.at(firstItem)->downCoupling(), mModules.at(nextItem)->upCoupling())){
            double minusHeight = mModules[modifiedIndex]->len();
            graphicsScene->removeItem(gMod.at(modifiedIndex));
            for(int i = modifiedIndex + 1;i<gMod.size();i++){
                auto pos = gMod[i]->pos();
                gMod.at(i)->setPos(0,pos.y() - (minusHeight/10));
            }
            mModules.remove(modifiedIndex);
            qDebug()<<"delet";
            emit updated();
            // qDebug() << "remove Item" << gMod[modifiedIndex] << mAdditionalItems;
            for(int a=-1;a<gMod.size()-1;a++){
            QList<QGraphicsItem*> items = mAdditionalItems.take(gMod[modifiedIndex+a]);
            if(items.empty()){return;}
            for(int i = items.size() - 1; i >= 0; i--) {
                // qDebug()<<"Delete";
                graphicsScene->removeItem(items[i]);
                delete(items[i]);
            }
            }
            gMod.remove(modifiedIndex);
        }
        else {
            emit txtEd("Удаление невозможно");
            return;
        }
    modifiedIndex = -1;
    }
}
void TeleSystem::clearScene()
{
    if (modifiedIndex < 0) { return; }
    graphicsScene->clear();
    gMod.clear();
    mModules.clear();
    emit updated();
    modifiedIndex = -1;
}

void TeleSystem::pointShow(QList<QGraphicsItem*>graphicsItem)
{
    if (graphicsItem.empty() || graphicsItem.size() > 1) { return; }
    int i = 0;
    while(i < gMod.size()){
        if (gMod[i] == graphicsItem.first()) {
            break;
        }
        i++;
    }
    modifiedIndex = i;
    if (modifiedIndex < 0) { return; }
    if (!mAdditionalItems.contains(gMod[modifiedIndex])) { //рисуем точки
        QList<Point>points = mModules.at(modifiedIndex)->getPoints();
        QList<QGraphicsItem*> items;
        for(int a = 0;a<points.size();a++){
            double y = 0;
            if (mModules.size() > 1) {
                y = lenToModule(modifiedIndex -1);
            }
            QGraphicsLineItem *line = new QGraphicsLineItem(0,y + points.at(a).lent()/10,60,y + points.at(a).lent()/10);
            mAdditionalItems[gMod[modifiedIndex]].append(line);
            items.append(line);
            QGraphicsTextItem *text = new QGraphicsTextItem(points.at(a).mname());
            mAdditionalItems[gMod[modifiedIndex]].append(text);
            items.append(text);

            text->setY(y + points.at(a).lent()/10-13);
            text->setX(60+((a*35)+20));
            graphicsScene->addItem(line);
            graphicsScene->addItem(text);
        }
        mAdditionalItems[gMod[modifiedIndex]] = items;
        qDebug()<<mAdditionalItems<<gMod[modifiedIndex];
    } else {
        QList<QGraphicsItem*> items = mAdditionalItems.take(gMod[modifiedIndex]);
        for(int i = items.size() - 1; i >= 0; i--) {
            graphicsScene->removeItem(items[i]);
            delete(items[i]);
        }
    }
        modifiedIndex = -1;
}
// void TeleSystem::pointInfo()
// {
//     Point*point;
//     qDebug()<<"длинна точки"<<point->lent();

// }

