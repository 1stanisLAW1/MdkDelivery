/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *hideBtn;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *continueBtn;
    QPushButton *regBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(394, 243);
        QFont font;
        font.setPointSize(16);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:rgb(0, 0, 0);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 371, 171));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font1.setPointSize(16);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"}"));
        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 110, 371, 51));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 14pt \"Segoe UI\";\n"
"color:rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit_4 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_4->setObjectName("lineEdit_4");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(14);
        lineEdit_4->setFont(font2);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:250px;\n"
"min-height:30px;\n"
"min-width:80px;\n"
"}"));
        lineEdit_4->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_5->addWidget(lineEdit_4);

        hideBtn = new QPushButton(horizontalLayoutWidget_3);
        hideBtn->setObjectName("hideBtn");
        hideBtn->setMaximumSize(QSize(44, 34));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font3.setPointSize(23);
        hideBtn->setFont(font3);
        hideBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(255, 255, 255);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:40px;\n"
"min-height:30px;\n"
"min-width:40px;\n"
"}"));

        horizontalLayout_5->addWidget(hideBtn);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 30, 371, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 14pt \"Segoe UI\";\n"
"color:rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:300px;\n"
"min-height:30px;\n"
"min-width:80px;\n"
"}"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 190, 251, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        continueBtn = new QPushButton(horizontalLayoutWidget);
        continueBtn->setObjectName("continueBtn");
        QFont font4;
        font4.setPointSize(14);
        continueBtn->setFont(font4);
        continueBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        horizontalLayout->addWidget(continueBtn);

        regBtn = new QPushButton(horizontalLayoutWidget);
        regBtn->setObjectName("regBtn");
        regBtn->setFont(font4);
        regBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:110px;\n"
"min-height:30px;\n"
"min-width:80px;\n"
"}"));

        horizontalLayout->addWidget(regBtn);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "DeliveryForYou", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " Password", nullptr));
        hideBtn->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", " Login      ", nullptr));
        continueBtn->setText(QCoreApplication::translate("MainWindow", "continue", nullptr));
        regBtn->setText(QCoreApplication::translate("MainWindow", "registration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
