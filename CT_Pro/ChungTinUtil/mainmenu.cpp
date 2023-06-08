#include "mainmenu.h"

QFont modFontSize(QFont f, int size)
{
    QFont font = f;
    font.setPointSize(size);
    return font;
}

bool mainMenuSetUp(MainWindow **mw)
{
    MainWindow *window = *mw;
    if(!window->isEnabled())
    {
        return false;
    }
    window->setWindowTitle("中天廚房設備有限公司報價單編輯器");
    window->setFixedSize(500,250);
    widgetSetup(&window);
    return true;
}

bool widgetSetup(MainWindow **mw)
{
    MainWindow *window = *mw;
    if(!window->isEnabled())
    {
        return false;
    }
    QWidget *qw = new QWidget();

    QLabel *label = new QLabel("中天廚房設備有限公司報價單編輯器");
    label->setFont(modFontSize(label->font(),20));
    label->setGeometry(35,10,800,150);
    label->setParent(qw);

    QPushButton *createNewFile = new QPushButton();
    createNewFile->setParent(qw);
    createNewFile->setGeometry(220,130,60,30);
    createNewFile->setText("新報價單");
    createNewFile->setFont(modFontSize(createNewFile->font(),10));

    QPushButton *quit = new QPushButton();
    quit->setGeometry(220,190,60,30);
    quit->setParent(qw);
    quit->setText("關閉程序");
    quit->setFont(modFontSize(quit->font(),10));
    QObject::connect(quit, &QPushButton::clicked,[&]
    {
        BUTTONACTIONS_H::exitProgram(label,quit,createNewFile,window,qw);
    });
    window->setCentralWidget(qw);
    return true;
}
