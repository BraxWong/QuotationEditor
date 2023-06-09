#ifndef BUTTONACTIONS_H
#define BUTTONACTIONS_H
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include "quotationeditor.h"

//@exitProgram
//@Param: QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw
//@Descriptions: Delete all the resources and quitting the program
void exitProgram(QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw);

bool createNewFile();

#endif // BUTTONACTIONS_H
