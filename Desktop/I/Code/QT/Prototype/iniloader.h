#ifndef INILOADER_H
#define INILOADER_H

#include <QObject>
#include "moduls.h"

class IniLoader:public QObject
{
    Q_OBJECT
public:
    IniLoader(QObject *parent = nullptr);
    void extracted();
    Moduls createModel(QString filepath);
    QList<Moduls> createModuls(QString dirpath);
    Moduls::TypeCoupling convertStr2Type(const QString& str);
signals:
    void sendMessage(QString);
};

#endif // INILOADER_H
