#ifndef BUTTONACTIONS_H
#define BUTTONACTIONS_H
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <fstream>
#include "customerDetails.h"
#include "entry.h"
#include "libxl.h"

using namespace libxl;

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

//@appendToFile
//@Param: customerDetails* details, std::vector<entry*> entries
//@Descriptions: Will write customerDetials and products info into an excel file
//@Return: Always return true
bool appendToFile(customerDetails* details, std::vector<entry*> entries);

//@endOfFile
//@Param: int total, int totalDiscount, float totalMR, Book** newBook, Sheet** newSheet, int rowNum, customerDetails* details
//@Descriptions: Will write the ending of the file
//@Return: Always return true
bool endOfFile(int total, int totalDiscount, float totalMR, Book** newBook, Sheet** newSheet, int rowNum, customerDetails* details);

#endif // BUTTONACTIONS_H
