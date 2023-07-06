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
//@Return: True if nothing throws an error
bool quotationEditorSetup();

//@quotationWidgetSetup()
//@Descriptions: Set up all the widgets for the quotation editor screen
//@Return: True if nothing throws an error
bool quotationWidgetSetup();

//@createNewItems()
//@Descriptions: Allows users to input a product and relevant information about the product.
//				 After submitting, the item will be pushed into a std::vector<entry> vector.
//				 Please check the entry class for more information.
//@Return: True if nothing throws an error
bool createNewItems();

#endif // QUOTATIONEDITOR_H
