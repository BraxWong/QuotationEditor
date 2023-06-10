#ifndef QUOTATIONEDITOR_H
#define QUOTATIONEDITOR_H
#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <ctime>
#include <QDialog>
#include <QRadioButton>
#include "qmenubar.h"
#include "mainwindow.h"
#include "helpfunctions.h"


bool quotationEditorSetup();

bool quotationWidgetSetup();

std::string getCurrentDate();

bool createNewItems();

#endif // QUOTATIONEDITOR_H
