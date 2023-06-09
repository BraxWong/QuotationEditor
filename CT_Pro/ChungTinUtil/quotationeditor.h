#ifndef QUOTATIONEDITOR_H
#define QUOTATIONEDITOR_H
#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <ctime>
#include "mainwindow.h"


bool quotationEditorSetup();

bool quotationWidgetSetup();

//@modFontSize
//@Description: Creates a QFont object then setting the font size. Returning the QFont object afterwards
//@Return: QFont object
//TODO: the first parameter can be a string instead of a QFont object.
//TODO: This function should be placed in a helper function file instead.
QFont modFontSize(QFont f, int size);

std::string getCurrentDate();

void widgetConfig(QLineEdit** input, QLabel** label, QString, int x, int x1, int y, int y1, int width, int width1, int height, int height1);
#endif // QUOTATIONEDITOR_H
