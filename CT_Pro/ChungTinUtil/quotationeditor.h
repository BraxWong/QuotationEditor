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
#include "customerDetails.h"
#include "entry.h"

//@quotationEditorSetup()
//@Descriptions: Set up the quotation editor screen.
bool quotationEditorSetup();

//@quotationWidgetSetup()
//@Descriptions: Set up all the widgets for the quotation editor screen
bool quotationWidgetSetup();

//@getCurrentDate()
//@Descriptions: Uses localtime_s() to get the current date (DD-MM-YYYY)
//@Return: The date in type string
std::string getCurrentDate();

bool createNewItems();

#endif // QUOTATIONEDITOR_H
