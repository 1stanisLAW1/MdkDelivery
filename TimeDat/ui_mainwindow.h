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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *TD;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPlainTextEdit *pte;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(529, 316);
        MainWindow->setMaximumSize(QSize(529, 316));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-top-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TD = new QTabWidget(centralwidget);
        TD->setObjectName("TD");
        TD->setGeometry(QRect(0, 0, 541, 321));
        TD->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar {\n"
"        left: 3px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    border-top-left-radius: 1 px;\n"
"    border-top-right-radius: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QTabBar::tab:hover \n"
"{\n"
"	background-color: rgb(42, 42, 42);\n"
"	color: white;\n"
"}\n"
"QTabBar::tab:!selected\n"
"{\n"
"	background-color: black;\n"
"	color: white;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        tab->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-10, 0, 541, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiBold Condensed")});
        font.setPointSize(39);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:black;\n"
"color:green;\n"
"}"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:black;\n"
"color:green;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        calendarWidget = new QCalendarWidget(tab);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(0, 80, 531, 211));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        calendarWidget->setStyleSheet(QString::fromUtf8("QCalendarWidget {\n"
"    background-color: black;\n"
"    color: white;\n"
"    font-family: Arial;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QCalendarWidget QHeaderView::section {\n"
"    background-color: black;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView {\n"
"    background-color: black;\n"
"    color: white;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView::item {\n"
"    background-color: transparent;\n"
"    color: lightgray;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView::item:selected {\n"
"    background-color: gray;\n"
"    color: black;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    background-color: black;\n"
"    border: none;\n"
"    padding: 5px;\n"
"    color: white;\n"
"height: 20px; \n"
"width: 130px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: darkgray;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:pressed {\n"
"    background-color: gray;\n"
"}\n"
"\n"
"\n"
""));
        TD->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 250, 251, 51));
        QFont font1;
        font1.setPointSize(16);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(28, 34, 167);\n"
"}"));
        horizontalLayoutWidget_2 = new QWidget(tab_2);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(250, 250, 281, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(86, 32));
        QFont font2;
        font2.setPointSize(11);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: black;\n"
"	color: rgb(209, 114, 70);\n"
"border: 3px solid rgb(255, 128, 0);\n"
"solid: rgb(209, 114, 70);\n"
"border-radius:15px\n"
"}"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMaximumSize(QSize(86, 32));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: black;\n"
"	color: rgb(209, 114, 70);\n"
"border: 3px solid rgb(255, 128, 0);\n"
"solid: rgb(209, 114, 70);\n"
"border-radius:15px\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(86, 32));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: black;\n"
"	color: rgb(209, 114, 70);\n"
"border: 3px solid rgb(255, 128, 0);\n"
"solid: rgb(209, 114, 70);\n"
"border-radius:15px\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_2);

        pte = new QPlainTextEdit(tab_2);
        pte->setObjectName("pte");
        pte->setGeometry(QRect(-1, -1, 541, 251));
        QFont font3;
        font3.setPointSize(14);
        pte->setFont(font3);
        pte->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        pte->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"	background-color: rgb(0, 0, 0);\n"
"color:green;\n"
"}"));
        pte->setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByKeyboard|Qt::TextInteractionFlag::TextSelectableByMouse);
        TD->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        TD->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        TD->setTabText(TD->indexOf(tab), QCoreApplication::translate("MainWindow", "Time&Data", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pte->setPlainText(QString());
        TD->setTabText(TD->indexOf(tab_2), QCoreApplication::translate("MainWindow", " Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
