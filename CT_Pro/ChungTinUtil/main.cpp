#include "mainwindow.h"
#include <QApplication>
#include "mainmenu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    MAINMENU_H::mainMenuSetUp(&w);
    w->show();
    return a.exec();
}
