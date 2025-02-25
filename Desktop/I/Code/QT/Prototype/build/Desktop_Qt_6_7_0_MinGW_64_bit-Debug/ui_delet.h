/********************************************************************************
** Form generated from reading UI file 'delet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELET_H
#define UI_DELET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_delet
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *delet)
    {
        if (delet->objectName().isEmpty())
            delet->setObjectName("delet");
        delet->resize(547, 409);
        delet->setStyleSheet(QString::fromUtf8("QDialog{background-color:black}\n"
""));
        pushButton = new QPushButton(delet);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 100, 161, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:black}\n"
"QPushButton{color:red}\n"
"QPushButton{border:2px solid red}\n"
"QPushButton{border-radius: 10px}"));

        retranslateUi(delet);

        QMetaObject::connectSlotsByName(delet);
    } // setupUi

    void retranslateUi(QDialog *delet)
    {
        delet->setWindowTitle(QCoreApplication::translate("delet", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("delet", "\320\232\320\276\320\266\321\203\321\205 \320\277\321\203\320\273\321\214\321\201\320\260\321\202\320\276\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delet: public Ui_delet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELET_H
