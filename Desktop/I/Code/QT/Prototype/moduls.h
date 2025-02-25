#ifndef MODULS_H
#define MODULS_H

#include <QObject>
#include "point.h"


class Moduls
{
public:
    Moduls(){};
    Moduls(const QString name, const int length,const int maxL,const int minL);
    QString name() const;
    int len() const{return mCurrentLength;}
    int minL() const {return mMinLength;}
    int maxL() const {return mMaxLength;}
    void addPoint(Point);
    QList <Point> getPoints() const;
    int pointsCount() const{return mPoints.size();};
    bool variableLength() const;
    void setMinMax(int min,int max);
    bool setCurrentLength(int l);
    enum class TypeCoupling{None,TOP,KORVET_MRKm,KORVET_MRKp,KORVET_M,KORVET_P,BOTTOM};
    bool setUpDown(TypeCoupling up,TypeCoupling down);
    TypeCoupling upCoupling() const;
    TypeCoupling downCoupling() const;
    static bool exemCoupling(TypeCoupling type1, TypeCoupling type2);
    bool isValid() const{return !mName.isEmpty();}
    QString infoMod();
    //int fullLenModul();
private:
    int mMaxLength = 0;
    int mMinLength = 0;
    int mCurrentLength = 0;
    // int fullLenght = 0;
    QString mName;
    QList <Point> mPoints;
    TypeCoupling mUpCoupling;
    TypeCoupling mDownCoupling;
    QString length();
};
QString type2str(Moduls::TypeCoupling type);

#endif // MODULS_H
