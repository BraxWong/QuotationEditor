#include "buttonactions.h"

void exitProgram(QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw)
{
    qw = nullptr;
    delete qw;
    window = nullptr;
    delete window;
    quit = nullptr;
    delete quit;
    label = nullptr;
    delete label;
    createNewFile = nullptr;
    delete createNewFile;
    exit(0);
}

bool createNewFile()
{
    QUOTATIONEDITOR_H::quotationEditorSetup();
    return true;
}

bool modifyDataBase()
{
    return true;
}


