#ifndef ERROR_H
#define ERROR_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QDialog>
#include <QLabel>
class error
{
public:
	//@showError()
	//@Param: std::string errorMessage, int x, int y, int width, int height
	//@Descriptions: It will show a popUp window with the error message on it
	void showError(std::string errorMessage, int x, int y, int width, int height);
	//@closedError()
	//@Descriptiosn: It will be called when popUp is closed. It will destroy both popUp and errorMessageLabel
	void closedError();

private:
	QDialog* popUp;
	QLabel* errorMessageLabel;
};
#endif
