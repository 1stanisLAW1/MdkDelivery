/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenU
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QWidget *widget;
    QWidget *tab_5;
    QGroupBox *groupBox_4;
    QWidget *tab_6;
    QGroupBox *groupBox_5;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QWidget *widget_2;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label;
    QTableView *tableView_2;
    QPushButton *pushButton_10;

    void setupUi(QDialog *MenU)
    {
        if (MenU->objectName().isEmpty())
            MenU->setObjectName("MenU");
        MenU->resize(557, 806);
        MenU->setMaximumSize(QSize(1920, 1080));
        tabWidget = new QTabWidget(MenU);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 561, 811));
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 551, 781));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 551, 741));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font.setPointSize(18);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 40, 541, 701));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 0, 551, 741));
        groupBox_4->setFont(font);
        groupBox_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        groupBox_5 = new QGroupBox(tab_6);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(0, 0, 551, 741));
        groupBox_5->setFont(font);
        groupBox_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget_2->addTab(tab_6, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(9, 9, 531, 761));
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 40, 531, 721));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 0, 531, 771));
        groupBox_3->setFont(font);
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 40, 261, 150));
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 40, 231, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font1.setPointSize(30);
        label_2->setFont(font1);
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 210, 491, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableView_2 = new QTableView(groupBox_3);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(0, 250, 531, 521));
        pushButton_10 = new QPushButton(groupBox_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(350, 100, 151, 41));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(MenU);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenU);
    } // setupUi

    void retranslateUi(QDialog *MenU)
    {
        MenU->setWindowTitle(QCoreApplication::translate("MenU", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MenU", "Menu", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MenU", "\320\224\320\276\320\264\320\276 \320\237\320\270\321\206\321\206\320\260", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MenU", "Menu", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MenU", "\320\242\320\265\321\200\320\265\320\274\320\276\320\272", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MenU", "Menu", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("MenU", "Coffee Like", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MenU", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MenU", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MenU", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MenU", "Profile", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("MenU", "A", nullptr));
        label->setText(QCoreApplication::translate("MenU", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MenU", "Setting", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MenU", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\232\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenU: public Ui_MenU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
