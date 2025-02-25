#ifndef POINT_H
#define POINT_H
#include <QString>
class Point
{
public:
    Point(const QString name,const QString nameM,const int len);

    QString name() const{return mName;}
    QString mname() const{return mMnName;}
    int lent() const{return mLength;}
    void setLen(int l);
    void setName(QString n);
    void setMName(QString mn);
    QString length();
    //int fullLenPoint();
private:
    int mLength = 0;
    QString mName;
    QString mMnName;

};

#endif // POINT_H
