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
        MenU->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:rgb(0, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
"}"));
        tabWidget = new QTabWidget(MenU);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 561, 811));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget {\n"
"    background-color: black; /* \320\244\320\276\320\275 \320\262\321\201\320\265\320\263\320\276 QTabWidget */\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid gray; /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 \320\262\320\276\320\272\321\200\321\203\320\263 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\262\320\272\320\273\320\260\320\264\320\276\320\272 */\n"
"    background-color: black; /* \320\244\320\276\320\275 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\262\320\272\320\273\320\260\320\264\320\276\320\272 */\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    background-color: black; /* \320\244\320\276\320\275 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    border: 1px solid white; /* \320\223"
                        "\321\200\320\260\320\275\320\270\321\206\320\260 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    margin: 0px; /* \320\222\320\275\320\265\321\210\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: gray; /* \320\244\320\276\320\275 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    color: black; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background"
                        "-color: #333; /* \320\244\320\276\320\275 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 551, 781));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabWidget {\n"
"    background-color: black; /* \320\244\320\276\320\275 \320\262\321\201\320\265\320\263\320\276 QTabWidget */\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid gray; /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 \320\262\320\276\320\272\321\200\321\203\320\263 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\262\320\272\320\273\320\260\320\264\320\276\320\272 */\n"
"    background-color: black; /* \320\244\320\276\320\275 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\262\320\272\320\273\320\260\320\264\320\276\320\272 */\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    background-color: black; /* \320\244\320\276\320\275 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    border: 1px solid white; /* \320\223"
                        "\321\200\320\260\320\275\320\270\321\206\320\260 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    margin: 0px; /* \320\222\320\275\320\265\321\210\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: gray; /* \320\244\320\276\320\275 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"    color: black; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 */\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background"
                        "-color: #333; /* \320\244\320\276\320\275 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 551, 741));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font.setPointSize(18);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"}"));
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
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"}"));
        groupBox_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        groupBox_5 = new QGroupBox(tab_6);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(0, 0, 551, 741));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"}"));
        groupBox_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget_2->addTab(tab_6, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(9, 9, 531, 761));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"}"));
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
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"}"));
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 40, 261, 150));
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 40, 231, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 28pt \"Segoe UI\";\n"
"color:rgb(255, 255, 255);\n"
"}"));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 210, 491, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(24);
        font2.setBold(false);
        font2.setItalic(false);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 24pt \"Segoe UI\";\n"
"color:rgb(255, 255, 255);\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableView_2 = new QTableView(groupBox_3);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(0, 250, 531, 521));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font3.setPointSize(9);
        tableView_2->setFont(font3);
        tableView_2->setStyleSheet(QString::fromUtf8("  QTableView {\n"
"  color: rgb(255, 255, 255);\n"
"    background-color: rgb(0, 0, 0);\n"
"    gridline-color: rgb(128, 128, 128);\n"
"    alternate-background-color: rgb(30, 30, 30);\n"
"}\n"
"\n"
"QTableView::Header {\n"
"    color: rgb(255, 255, 255);\n"
"    background-color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"}"));
        pushButton_10 = new QPushButton(groupBox_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(290, 100, 204, 34));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(14);
        pushButton_10->setFont(font4);
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(0, 0, 0);\n"
"border: 2px solid rgb(124, 124, 124);\n"
"solid: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"max-height:30px;\n"
"max-width:200px;\n"
"min-height:30px;\n"
"min-width:200px;\n"
"}"));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(MenU);

        tabWidget->setCurrentIndex(0);
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
