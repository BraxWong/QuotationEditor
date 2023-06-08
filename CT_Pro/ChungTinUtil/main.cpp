#include "mainwindow.h"
#include <QApplication>
#include "mainmenu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    MAINMENU_H::mainMenuSetUp(&w);
    w->show();
    return a.exec();
}
