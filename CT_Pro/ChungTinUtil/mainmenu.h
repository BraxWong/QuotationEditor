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
#include <QRadioButton>
#include "mainwindow.h"


//@mainMenuSetUp
//@Param: MainWindow **mw
//@Description: This is used to set up the main menu
//@Return: True if nothing throw an error
bool mainMenuSetUp(MainWindow **mw);

//@widgetSetup
//@Param: MainWindow **mw
//@Description: Setting up the widget for the main menu
//@Return: True if nothing throws an error
bool widgetSetup(MainWindow **mw);
#endif // MAINMENU_H
