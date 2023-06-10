#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H
#include "QLineEdit"
#include "QLabel"

void widgetConfig(QWidget* wq, QLineEdit** input, QLabel** label, QString name, int x, int x1, int y, int y1, int width, int width1, int height, int height1);

//@modFontSize
//@Description: Creates a QFont object then setting the font size. Returning the QFont object afterwards
//@Return: QFont object
//TODO: the first parameter can be a string instead of a QFont object.
//TODO: This function should be placed in a helper function file instead.
QFont modFontSize(QFont f, int size);

void widgetConfigForPopUp(QLineEdit** input, QLabel** label, int x, int x1, int y, int y1, int width, int width1, int height, int height1);

#endif // HELPFUNCTIONS_H
