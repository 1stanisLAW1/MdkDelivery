#include "iniloader.h"
#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include <QDir>

Moduls::TypeCoupling IniLoader::convertStr2Type(const QString& str)
{


    Moduls::TypeCoupling ret;
    if (str == "TOP") {
        ret = Moduls::TypeCoupling::TOP;
    }
    else if (str =="KORVET_MRKp"){
        ret = Moduls::TypeCoupling::KORVET_MRKp;
    }
    else if (str =="KORVET_MRKm"){
        ret = Moduls::TypeCoupling::KORVET_MRKm;
    }
    else if(str=="KORVET_M"){
        ret = Moduls::TypeCoupling::KORVET_M;
    }
    else if (str=="KORVET_P"){
        ret = Moduls::TypeCoupling::KORVET_P;
    }
    else if (str=="BOTTOM"){
        ret = Moduls::TypeCoupling::BOTTOM;
    }
    else {

        ret = Moduls::TypeCoupling::None;
    }
   // qDebug() << "convert" << str << type2str(ret);
    return ret;
}
IniLoader::IniLoader(QObject *parent) : QObject(parent) {}

Moduls IniLoader::createModel(QString filepath)
{
   // QString str;
   // qDebug() << "createModel" << filepath;
    if(!QFileInfo::exists(filepath)){
       emit sendMessage("not exists"+filepath);
        //qDebug() << "not exists" << filepath;
        return Moduls();
    }

    QSettings setting(filepath,QSettings::IniFormat);
    QStringList groupList = setting.childGroups();

    if(!groupList.contains("modul")){
        emit sendMessage("empty groups"+filepath);
       // qDebug() << "empty groups" << filepath;
        return Moduls();
    }
    bool ok = true;
    QString name = setting.value("modul/name").toString();
    QString upCoupling = setting.value("modul/upCoupling").toString();
    QString downCoupling   = setting.value("modul/downCoupling").toString();
    QString len = setting.value("modul/length").toString();
    QString max = setting.value("modul/maxL").toString();
    QString min = setting.value("modul/minL").toString();
    int minL = min.toInt(&ok);
    int maxL = max.toInt(&ok);
    int lenght = len.toInt(&ok);
    Moduls m(name,lenght,maxL,minL);
    if(m.maxL()>=m.len()&&m.minL()<=m.len()){
        m.setUpDown(convertStr2Type(upCoupling),convertStr2Type(downCoupling));
    }else{
       // QString str(QString::number(__LINE__));
        //qDebug() << "emit" << str;
        emit sendMessage("Invalid length data entered:"+filepath);
    }
    for (int i = 0;i<groupList.size();i++){
        if (!groupList[i].startsWith("point")) { continue; }
        QString groupName = groupList[i];
        int lent = setting.value(groupName + "/len").toInt();
        QString nameM = setting.value(groupName + "/mpName").toString();
        QString name = setting.value(groupName + "/mName").toString();
        Point po = Point(name,nameM,lent);
        // qDebug()<<"mName"<<nameM;
        if(po.lent()>=0&&po.lent()<=m.maxL()){
   //     qDebug() << "pointName" << setting.value(groupName + "/mName");
        m.addPoint(po);
        }
        else{
                   // QString str(QString::number(__LINE__));
            emit sendMessage("Invalid point length data entered:"+filepath);
                   // qDebug() << "emit" << str;
        }
    }
    //emit sendMessage("Info"+m.infoMod());

    return m;
}

QList<Moduls> IniLoader::createModuls(QString dirpath)
{
    QList<Moduls> moduls;
    QFileInfo dirInfo(dirpath);
    qDebug() << dirInfo.absoluteFilePath();
    if(!dirInfo.exists()||!dirInfo.isDir()){return moduls;}
    QDir dir(dirpath);
    QStringList filter;
    filter << QString("*.ini");
    QStringList files = dir.entryList(filter,QDir::Files);
    // foreach (const QString &file, files) {
    //     qDebug() << dir.absoluteFilePath(file);
    // }
    for(int i=0;i<files.size();i++)
    {
        Moduls m = createModel(dir.absoluteFilePath(files[i]));
        if(m.isValid()){
            moduls.append(m);
        }
    }
    foreach(auto m, moduls) {
        qDebug() << m.name() << type2str(m.upCoupling()) << type2str( m.downCoupling());
    }
    qDebug() << "iniloaderCompleate";
    return moduls;
}



