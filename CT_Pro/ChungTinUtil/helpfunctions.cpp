#include "helpfunctions.h"

QFont modFontSize(QFont f, int size)
{
    QFont font = f;
    font.setPointSize(size);
    return font;
}


void widgetConfig(QWidget* wq, QLineEdit** input, QLabel** label, QString name, int x, int x1, int y, int y1, int width, int width1, int height, int height1)
{
    QLineEdit* line = *input;
    line->setParent(wq);
    line->setGeometry(x,y,width,height);
    line->show();
    QLabel* l = *label;
    l->setParent(wq);
    l->setGeometry(x1,y1,width1,height1);
    l->setText(name);
    l->setFont(modFontSize(l->font(),12));
    l->show();
}

void widgetConfigForPopUp(QLineEdit** input, QLabel** label, int x, int x1, int y, int y1, int width, int width1, int height, int height1)
{
    QLineEdit* line = *input;
    line->setGeometry(x,y,width,height);
    line->show();
    QLabel* l = *label;
    l->setGeometry(x1,y1,width1,height1);
    l->setFont(modFontSize(l->font(),12));
    l->show();
}
