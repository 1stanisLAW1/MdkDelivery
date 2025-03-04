#include "mainwindow.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString executablePath = QCoreApplication::applicationDirPath();
    QString iconPath = executablePath + "/../ico/block.ico";

    QSystemTrayIcon trayIcon;

    if (!QFile::exists(iconPath)) {
        qWarning() << "Иконка не найдена:" << iconPath;
        // Можно установить иконку по умолчанию или выйти
    } else {
        trayIcon.setIcon(QIcon(iconPath));
    }

    QMenu *menu = new QMenu();
    QAction *quitAction = new QAction("Выход", menu);
    QAction *openAction = new QAction("Открыть", menu);

    QObject::connect(quitAction, &QAction::triggered, QApplication::quit);
    QObject::connect(openAction, &QAction::triggered, [&w]() {
        w.show(); // Показываем главное окно
        w.raise(); // Поднимаем окно на передний план
        w.activateWindow();
    });

    QObject::connect(&trayIcon, &QSystemTrayIcon::activated, [&w](QSystemTrayIcon::ActivationReason reason) {
        if (reason == QSystemTrayIcon::DoubleClick) {
            if (w.isVisible()) {
                w.hide(); // Скрываем окно, если оно открыто
            } else {
                w.show(); // Показываем окно, если оно скрыто
                w.raise(); // Поднимаем окно на передний план
                w.activateWindow(); // Активируем окно
            }
        }
    });

    menu->addAction(openAction);
    menu->addAction(quitAction);

    trayIcon.setContextMenu(menu);
    trayIcon.show(); // Показываем иконку в трее

    return a.exec();
}
