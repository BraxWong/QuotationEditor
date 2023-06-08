#ifndef MAINMENU_H
#define MAINMENU_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QVBoxLayout>
#include <QPushButton>
#include "mainwindow.h"
#include "buttonactions.h"

//@mainMenuSetUp
//@Description: This is used to set up the main menu
bool mainMenuSetUp(MainWindow **mw);

//@modFontSize
//@Description: Creates a QFont object then setting the font size. Returning the QFont object afterwards
//@Return: QFont object
//TODO: the first parameter can be a string instead of a QFont object.
QFont modFontSize(QFont f, int size);

//@widgetSetup
//@Description: Setting up the widget for the main menu
//@Return: True if nothing throws an error
bool widgetSetup(MainWindow **mw);
#endif // MAINMENU_H
