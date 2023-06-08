#include "mainmenu.h"

QFont modFontSize(QFont f, int size)
{
    QFont font = f;
    font.setPointSize(20);
    return font;
}

bool mainMenuSetUp(MainWindow **mw)
{
    MainWindow *window = *mw;
    if(!window->isEnabled())
    {
        return false;
    }
    window->setWindowTitle("中天廚房設備有限公司報價編輯器");
    QLabel *label = new QLabel("中天廚房設備有限公司報價編輯器");
    QWidget *qw = new QWidget();
    label->setFont(modFontSize(label->font(),20));
    label->setGeometry(180,10,800,150);
    label->setParent(qw);
    window->setCentralWidget(qw);
    return true;
}
