#include "buttonactions.h"

bool exitProgram(QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw)
{
    delete qw;
    delete window;
    delete quit;
    delete label;
    delete createNewFile;
    exit(0);
    return false;
}
