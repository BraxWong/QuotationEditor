#include "mainwindow.h"
#include <QApplication>
#include "mainmenu.h"
#include "buttonactions.h"
#include "customerDetails.h"
#include "entry.h"
int main(int argc, char *argv[])
{

//    QApplication a(argc, argv);
//    MainWindow *w = new MainWindow();
//    w->setAttribute(Qt::WA_DeleteOnClose);
//    MAINMENU_H::mainMenuSetUp(&w);
//    w->show();
//    return a.exec();
    customerDetails* detail = new customerDetails("Merivale","Sydney","Nicole","1","Brax","testing.csv",91001426,1);
    std::vector<entry*> entries;
    BUTTONACTIONS_H::appendToFile(detail,entries);
    return 1;
}
