#include "tableinfo.h"
#include <QTableWidget>

TableInfo::TableInfo(Moduls *)
{
    QTableWidget *table = new QTableWidget;
    table->setRowCount(5);
    table->setColumnCount(2);
}
