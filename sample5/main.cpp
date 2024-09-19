#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // メニュー画面を表示
    MainWindow w;
    w.show();

    return a.exec();
}
