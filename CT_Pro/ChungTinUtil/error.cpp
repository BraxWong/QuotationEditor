#include "error.h"
void error::showError(std::string errorMessage, int x, int y, int width, int height)
{
    popUp = new QDialog();
    errorMessageLabel = new QLabel(popUp);
    popUp->setWindowTitle("Error!");
    popUp->setAttribute(Qt::WA_DeleteOnClose);
    popUp->setFixedSize(400, 200);
    popUp->show();
    errorMessageLabel->setText(QString::fromStdString(errorMessage));
    errorMessageLabel->setGeometry(x,y,width,height);
    errorMessageLabel->show();

    QObject::connect(popUp, &QDialog::rejected, [=]() {
        closedError();
    });
}

void error::closedError()
{
    popUp->destroyed();
    errorMessageLabel->destroyed();
}

