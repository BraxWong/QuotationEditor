#ifndef BUTTONACTIONS_H
#define BUTTONACTIONS_H
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include "quotationeditor.h"
#include "helpfunctions.h"

//@exitProgram
//@Param: QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw
//@Descriptions: Delete all the resources and quitting the program
void exitProgram(QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw);

//@createNewFile
//@Descriptions: Calls QUOTATIONEDITOR_H::quotationEditorSetup() to set an extra window.
//               Achieving one purpose class by letting quotationeditor do the window set up instead
//@Return: True if successful. False if unable to create the file.
bool createNewFile();

//@modifyDataBase
bool modifyDataBase();

#endif // BUTTONACTIONS_H
