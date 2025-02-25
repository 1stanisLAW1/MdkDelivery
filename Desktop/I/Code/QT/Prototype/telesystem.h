#ifndef TELESYSTEM_H
#define TELESYSTEM_H

#include <QObject>
#include "graphicmodul.h"
#include "graphicsscene.h"
#include "moduls.h"
#include "qgraphicsscene.h"
#include <QWidget>

class TeleSystem : public QObject
{
    Q_OBJECT
public:
    TeleSystem();
    bool appendModul(Moduls m);
    Moduls::TypeCoupling lastCoupling();
    void info();
    void graphicsInfo() const;
    void drawModul(Moduls*);
    double fullLen()const;
    double lenToModule(int) const;
    void setScene(GraphicsScene*s);
    QList <Moduls*> getModuls() const{return mModules;};
    void pointInfo();
signals:
    void updated();
    void txtEd(QString);
public slots:
    void acceptsItem(QList<QGraphicsItem*>);
    void dialog();
    void remove();
    void clearScene();
    void pointShow(QList<QGraphicsItem*>);

private:
    QList<GraphicModul*>gMod;
    QList<Moduls*> mModules;
    QMap<GraphicModul*, QList<QGraphicsItem*>> mAdditionalItems;
    QGraphicsLineItem* lineLeft = nullptr;
    QGraphicsLineItem* lineRight = nullptr;
    GraphicsScene *graphicsScene = nullptr;
    QSlider *slider;
    int modifiedIndex = -1;
};

#endif // TELESYSTEM_H
