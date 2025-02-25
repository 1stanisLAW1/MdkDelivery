#include "graphicmodul.h"
#include "qmenu.h"
#include "qmessagebox.h"
#include "telesystem.h"
const int ModulHeight = 20;
GraphicModul::GraphicModul(Moduls *m) {
    modul = m;
}

QRectF GraphicModul::boundingRect() const
{
    QRectF rect(0, 0, 60,modul->len()/10);
    return rect;
}

void GraphicModul::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (modul->name()=="модуль KOR-BAT"){
        painter->setBrush(Qt::green);
    }
    else if(modul->name()=="модуль стыковочный"){
        painter->setBrush(Qt::red);
    }
    else if(modul->name()=="модуль Генератора"){
        painter->setBrush(Qt::yellow);
    }
    else if(modul->name()=="Модуль KOR-MIG2"){
        painter->setBrush(Qt::blue);
    }
    else if(modul->name()=="Модулятор"){
        painter->setBrush(Qt::darkCyan);
    }
    else if(modul->name()=="модуль МРК"){
        painter->setBrush(Qt::darkRed);
    }
    else if(modul->name()=="модуль Резистивиметра"){
        painter->setBrush(Qt::darkMagenta);
    }
    else if(modul->name()=="модуль телескопический"){
        painter->setBrush(Qt::gray);
    }
    else if(modul->name()=="Модуль KOR-TM3"){
        painter->setBrush(Qt::red);
    }
    else if(modul->name()=="Удлинитель резистивиметра"){
        painter->setBrush(Qt::darkRed);
    }
    QRectF rect(0,0,20,modul->len()/10);
        painter->drawRect(rect);
    QList<Point>listPoint = modul->getPoints();
    for (int i = 0;i<listPoint.size();i++){
        painter->drawLine(0,listPoint.at(i).lent()/10,ModulHeight,listPoint.at(i).lent()/10);
    }
}

QString GraphicModul::info() const
{
    return QString("Modul %1 pos %2").arg(modul->name()).arg(scenePos().x());

}

// void GraphicModul::mousePressEvent(QGraphicsSceneMouseEvent *event)
// {
//     if (event->button() == Qt::RightButton) {
//         qDebug() << "Нажата правая кнопка мыши";
//         // QMenu contextMenu;
//         // QAction *action1 = contextMenu.addAction("140");
//         // //connect(action1,SIGNAL(triggered()))
//         // QAction *action2 = contextMenu.addAction("150");
//         // QAction *selectedAction = contextMenu.exec(event->screenPos());
//     }
//     else if(event->button() == Qt::LeftButton)
//     {
//         qDebug() << "Нажата левая кнопка мыши";

//     }
//     QGraphicsItem::mousePressEvent(event);

// }







