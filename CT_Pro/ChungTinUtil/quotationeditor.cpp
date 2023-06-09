#include "quotationeditor.h"
MainWindow* editor;
QLineEdit* fileName, *customerName, *customerAddr, *supervisor, *customerTel, *customerID, *quotationID, *staff;
QLabel* fileNameLabel, *customerNameLabel, *customerAddrLabel, *supervisorLabel, *customerTelLabel, *customerIDLabel, *quotationIDLabel, *staffLabel;
QWidget* wq;
QPushButton* submit;
void widgetConfig(QLineEdit** input, QLabel** label, QString name, int x, int x1, int y, int y1, int width, int width1, int height, int height1)
{
    QLineEdit* line = *input;
    line->setParent(wq);
    line->setGeometry(x,y,width,height);
    QLabel* l = *label;
    l->setParent(wq);
    l->setGeometry(x1,y1,width1,height1);
    l->setText(name);
    l->setFont(modFontSize(l->font(),12));
}

std::string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return std::to_string(ltm->tm_mday) + "-" + std::to_string(ltm->tm_mon + 1) + "-" + std::to_string(ltm->tm_year + 1900);
}

QFont modFontSize(QFont f, int size)
{
    QFont font = f;
    font.setPointSize(size);
    return font;
}

bool quotationEditorSetup()
{
    editor = new MainWindow();
    editor->setAttribute(Qt::WA_DeleteOnClose);  // Set the delete on close attribute
    editor->setFixedSize(800,800);
    editor->setWindowTitle("編輯程序");
    quotationWidgetSetup();
    editor->show();
    return true;
}

bool quotationWidgetSetup()
{
    wq = new QWidget();

    fileName = new QLineEdit();
    fileNameLabel = new QLabel();
    widgetConfig(&fileName,&fileNameLabel,"檔案名稱:",150,50,50,13,200,100,25,100);

    customerName = new QLineEdit();
    customerNameLabel = new QLabel();
    widgetConfig(&customerName,&customerNameLabel,"客戶名稱:",150,50,100,100,200,200,25,25);

    customerAddr = new QLineEdit();
    customerAddrLabel = new QLabel();
    widgetConfig(&customerAddr,&customerAddrLabel,"客戶地址:",150,50,150,150,200,200,25,25);

    supervisor = new QLineEdit();
    supervisorLabel = new QLabel();
    widgetConfig(&supervisor,&supervisorLabel,"負責人:",150,50,200,200,200,200,25,25);

    customerTel = new QLineEdit();
    customerTelLabel = new QLabel();
    widgetConfig(&customerTel,&customerTelLabel,"電話:",550,450,50,50,200,200,25,25);

    customerID = new QLineEdit();
    customerIDLabel = new QLabel();
    widgetConfig(&customerID,&customerIDLabel,"客戶編號:",550,450,100,100,200,200,25,25);

    quotationID = new QLineEdit();
    quotationIDLabel = new QLabel();
    widgetConfig(&quotationID,&quotationIDLabel,"報價單號碼：",550,450,150,150,200,200,25,25);

    staff = new QLineEdit();
    staffLabel = new QLabel();
    widgetConfig(&staff,&staffLabel,"職員：",550,450,200,200,200,200,25,25);

    submit = new QPushButton();
    submit->setText("完成");
    submit->setParent(wq);
    submit->setGeometry(380,500,50,50);
    submit->setFont(modFontSize(submit->font(),15));

    editor->setCentralWidget(wq);
    return true;
}
