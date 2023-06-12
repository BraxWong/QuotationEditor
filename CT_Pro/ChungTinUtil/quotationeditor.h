#ifndef QUOTATIONEDITOR_H
#define QUOTATIONEDITOR_H
#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <ctime>
#include <QDialog>
#include <QRadioButton>


//@quotationEditorSetup()
//@Descriptions: Set up the quotation editor screen.
bool quotationEditorSetup();

//@quotationWidgetSetup()
//@Descriptions: Set up all the widgets for the quotation editor screen
bool quotationWidgetSetup();

bool createNewItems();

#endif // QUOTATIONEDITOR_H
