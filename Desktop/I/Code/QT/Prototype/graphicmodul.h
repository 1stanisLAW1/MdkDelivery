#ifndef GRAPHICMODUL_H
#define GRAPHICMODUL_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include "moduls.h"
#include<QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QSlider>

class GraphicModul : public QGraphicsItem
{
public:
    QSlider *slider;

    GraphicModul(Moduls*);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QString info() const;
   // void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
private:
    Moduls *modul;
    bool selected =false;
};

#endif // GRAPHICMODUL_H
