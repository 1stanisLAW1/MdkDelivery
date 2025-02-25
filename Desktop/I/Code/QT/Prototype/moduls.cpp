#include "moduls.h"
#include "qdebug.h"


QString type2str(Moduls::TypeCoupling type)
{
    QString ret;
    switch (type) {
    case Moduls::TypeCoupling::None : ret = "None"; break;
    case Moduls::TypeCoupling::TOP: ret = "TOP"; break;
    case Moduls::TypeCoupling::KORVET_MRKm:ret = "KORVET_MRKm"; break;
    case Moduls::TypeCoupling::KORVET_MRKp:ret = "KORVET_MRKp"; break;
    case Moduls::TypeCoupling::KORVET_M:ret = "KORVET_M"; break;
    case Moduls::TypeCoupling::KORVET_P:ret = "KORVET_P"; break;
    case Moduls::TypeCoupling::BOTTOM:     ret = "BOTTOM"; break;
    default: ret = QString("PIPEC %1").arg(static_cast<int>(type));

    }

        return ret;
}
Moduls::Moduls(QString name, int length, int maxL, int minL)
{
    mName = name;
    mMinLength = minL;
    mCurrentLength = length;
    mMaxLength = maxL;


}

QString Moduls::name() const { return mName; }

void Moduls::addPoint(Point m)
{
    if(m.lent()>=len()){
        return;
    }
    mPoints.append(m);

}

QList<Point> Moduls::getPoints() const{return mPoints;}

bool Moduls::variableLength() const
{
    return mMinLength != mMaxLength;
}

void Moduls::setMinMax(int min, int max)
{
        mMaxLength=max;
        mMinLength=min;

}

bool Moduls::setCurrentLength(int l)
{
    if(!variableLength()){return false;}
    mCurrentLength = l;
    return true;
}

bool Moduls::setUpDown(TypeCoupling up, TypeCoupling down)
{
    bool ok = true;
    // if(down==TypeCoupling::TOP||down ==TypeCoupling::KORVET_MRKp||down==TypeCoupling::KORVET_P){
    //     ok = false;
    // }
    // else if(up==TypeCoupling::KORVET_MRKm||up==TypeCoupling::KORVET_M||up==TypeCoupling::BOTTOM){
    //     ok = false;
    // }
    if(ok){
        mUpCoupling = up;
        mDownCoupling = down;
    }
    return ok;
}

Moduls::TypeCoupling Moduls::upCoupling() const{return mUpCoupling;}

Moduls::TypeCoupling Moduls::downCoupling() const{return mDownCoupling;}

bool Moduls::exemCoupling(TypeCoupling type1, TypeCoupling type2)
{
    qDebug() << "Moduls::exemCoupling" << type2str(type1) << type2str(type2);
    switch (type1) {
    case Moduls::TypeCoupling::None:
        return type2 == Moduls::TypeCoupling::TOP;
        break;
    case Moduls::TypeCoupling::KORVET_MRKm:
        return type2 == Moduls::TypeCoupling::KORVET_MRKp;
        break;
    case Moduls::TypeCoupling::KORVET_M:
        return type2 == Moduls::TypeCoupling::KORVET_P;
        break;
    case Moduls::TypeCoupling::KORVET_MRKp:
        return type2 == Moduls::TypeCoupling::KORVET_MRKm;
        break;
    case Moduls::TypeCoupling::KORVET_P:
        return type2 == Moduls::TypeCoupling::KORVET_M;
        break;
    default:
        break;
    }
    return false;
}

QString Moduls::infoMod()
{
    QString str = QString("Modul-%1 /n length-%2 min-%3 max-%4")
            .arg(name())
            .arg(len())
            .arg(minL())
            .arg(maxL());
    return str;

}

// int Moduls::fullLenModul()
// {
//     QList<Moduls> modul;
//     double result = 0;
//     for(int i = 0;i<modul.size();i++)
//     {
//         result +=modul.at(i).len();
//     }
// }


