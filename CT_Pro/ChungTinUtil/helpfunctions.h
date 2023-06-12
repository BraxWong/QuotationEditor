#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H
#include <filesystem>
#include <string>
#include <locale>
#include <windows.h>
#include <shlobj.h>
#include <objbase.h>

#pragma comment(lib,"Shell32")
#pragma comment(lib,"Ole32")
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

std::string get_desktop_path();

std::string centerText(const std::string& text, int width);

//@getCurrentDate()
//@Descriptions: Uses localtime_s() to get the current date (DD-MM-YYYY)
//@Return: The date in type string
std::string getCurrentDate();

#endif // HELPFUNCTIONS_H
