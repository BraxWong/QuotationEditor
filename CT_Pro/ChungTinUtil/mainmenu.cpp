#include "mainmenu.h"
#include "buttonactions.h"
#include "helpfunctions.h"
#include "error.h"

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
    bool actionRan = false;
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
    createNewFile->setGeometry(80,160,60,30);
    createNewFile->setText("新報價單");
    createNewFile->setFont(HELPFUNCTIONS_H::modFontSize(createNewFile->font(),10));
    QObject::connect(createNewFile, &QPushButton::clicked, [&]
    {
        if (actionRan)
        {
           BUTTONACTIONS_H::createNewFile();
           actionRan = false;
        }
        else
        {
            error* ErrorMessage = new error();
            ErrorMessage->showError("Error: Not able to create a new window",110, 0, 182, 182);
        }
        
    });

    QPushButton *quit = new QPushButton();
    quit->setGeometry(230,160,60,30);
    quit->setParent(qw);
    quit->setText("關閉程序");
    quit->setFont(modFontSize(quit->font(),10));
    QObject::connect(quit, &QPushButton::clicked,[&]
    {
        BUTTONACTIONS_H::exitProgram(label,quit,createNewFile,window,qw);
    });

    QPushButton *modifyDataBase = new QPushButton();
    modifyDataBase->setParent(qw);
    modifyDataBase->setGeometry(380,160,60,30);
    modifyDataBase->setText("改數據庫");
    modifyDataBase->setFont(HELPFUNCTIONS_H::modFontSize(quit->font(),10));
    QObject::connect(modifyDataBase, &QPushButton::clicked, [&]
    {
        BUTTONACTIONS_H::modifyDataBase();
        error* errorMessage = new error();
        errorMessage->showError("Pay up and I will think about it.", 110, 0, 182, 182);
    });
    window->setCentralWidget(qw);
    return true;
}
