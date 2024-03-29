#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H
#include <filesystem>
#include <string>
#include <locale>
#include <windows.h>
#include <shlobj.h>
#include <objbase.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#pragma comment(lib,"Shell32")
#pragma comment(lib,"Ole32")
#include "QLineEdit"
#include "QLabel"
#include "libxl.h"


void widgetConfig(QWidget* wq, QLineEdit** input, QLabel** label, QString name, int x, int x1, int y, int y1, int width, int width1, int height, int height1);

//@modFontSize
//@Description: Creates a QFont object then setting the font size. Returning the QFont object afterwards
//@Return: QFont object
//TODO: the first parameter can be a string instead of a QFont object.
//TODO: This function should be placed in a helper function file instead.
QFont modFontSize(QFont f, int size);

void widgetConfigForPopUp(QLineEdit** input, QLabel** label, int x, int x1, int y, int y1, int width, int width1, int height, int height1);

//@get_desktop_path()
//@Description: It returns the directory path to the user's desktop
//@Return: The directory path to the user's desktop
std::string get_desktop_path();

std::string centerText(const std::string& text, int width);

//@getCurrentDate()
//@Descriptions: Uses localtime_s() to get the current date (DD-MM-YYYY)
//@Return: The date in type string
std::string getCurrentDate();

//@insertPicture()
//@Param: libxl::Book** book, std::string pictureFile, int row, int column
//@Descriptions: It will attempt to insert a picture into the excel sheet.
//@Return: It will return the libxl::Sheet* with the picture in it
libxl::Sheet* insertPicture(libxl::Book** book, std::string pictureFile, int row, int column);

//@directoryExists()
//@Param: const char* dirPath
//@Descriptions: Checks if the dirPath exists or not.
//@Return: True -> The directory exists
//		 : False -> The directory does not exist
bool directoryExists(const char* dirPath);

//@wstringToFile()
//@Param: wstring str, std::fstream* item
//@Descriptions: Basically allows fstream item to take in a wstring variable and write it into a file
void wstringToFile(std::wstring str, std::fstream* item);
#endif // HELPFUNCTIONS_H
