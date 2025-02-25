#include "point.h"
#include <QDebug>
const int MAX_LEN = 5000;
const int MIN_LEN = 0;

Point::Point(QString name, QString nameM, int lent)
{
    mName = name;
    mMnName = nameM;
    mLength = lent;
}

void Point::setLen(int l)
{
    if(MAX_LEN<5000||MIN_LEN>0){
        qDebug()<<__LINE__ << __FILE__ << "wrong len";
    }
    mLength = l;
}

void Point::setName(QString n)
{
    if(n.isEmpty()){
        return;
    }
    mName = n;
}

void Point::setMName(QString mn)
{
    if(mn.isEmpty()){
        return;
    }
    mMnName = mn;
}

// int Point::fullLenPoint()
// {
//     QList<Point>point;
//     double result = 0;
//     for(int i = 0;i<point.size();i++)
//     {
//         result +=point.at(i).lent();
//     }
// }

