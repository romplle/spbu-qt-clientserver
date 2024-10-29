#include <QApplication>
#include <QList>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Запуск нескольких окон (3)
    QList<MainWindow*> windows;
    for (int i = 0; i < 3; ++i) {
        MainWindow *w = new MainWindow();
        w->show();
        windows.append(w);
    }

    return a.exec();
}
