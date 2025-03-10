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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingWindow
{
public:
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *settingWindow)
    {
        if (settingWindow->objectName().isEmpty())
            settingWindow->setObjectName("settingWindow");
        settingWindow->resize(351, 105);
        settingWindow->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:rgb(0, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
"}"));
        groupBox = new QGroupBox(settingWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 10, 351, 91));
        QFont font;
        font.setPointSize(14);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"}"));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 40, 341, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:80px;\n"
"min-height:30px;\n"
"min-width:80px;\n"
"}"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:350px;\n"
"min-height:30px;\n"
"min-width:80px;\n"
"}"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(settingWindow);

        QMetaObject::connectSlotsByName(settingWindow);
    } // setupUi

    void retranslateUi(QDialog *settingWindow)
    {
        settingWindow->setWindowTitle(QCoreApplication::translate("settingWindow", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("settingWindow", "Settings", nullptr));
        pushButton->setText(QCoreApplication::translate("settingWindow", "Save", nullptr));
        pushButton_2->setText(QCoreApplication::translate("settingWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\262\320\276\320\271 \320\260\320\262\320\260\321\202\320\260\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingWindow: public Ui_settingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
