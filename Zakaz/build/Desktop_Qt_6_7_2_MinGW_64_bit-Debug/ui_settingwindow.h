/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_settingWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *settingWindow)
    {
        if (settingWindow->objectName().isEmpty())
            settingWindow->setObjectName("settingWindow");
        settingWindow->resize(351, 278);
        pushButton = new QPushButton(settingWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 230, 111, 31));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(settingWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 20, 261, 31));
        QFont font1;
        font1.setPointSize(12);
        pushButton_2->setFont(font1);

        retranslateUi(settingWindow);

        QMetaObject::connectSlotsByName(settingWindow);
    } // setupUi

    void retranslateUi(QDialog *settingWindow)
    {
        settingWindow->setWindowTitle(QCoreApplication::translate("settingWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("settingWindow", "Save", nullptr));
        pushButton_2->setText(QCoreApplication::translate("settingWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\262\320\276\320\271 \320\260\320\262\320\260\321\202\320\260\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingWindow: public Ui_settingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
