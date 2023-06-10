#include "quotationeditor.h"
MainWindow* editor;
QLineEdit* fileName, *customerName, *customerAddr, *supervisor, *customerTel, *customerID, *quotationID, *staff;
QLabel* fileNameLabel, *customerNameLabel, *customerAddrLabel, *supervisorLabel, *customerTelLabel, *customerIDLabel, *quotationIDLabel, *staffLabel;
QWidget* wq;
QPushButton* submit, *addItems;

bool createNewItems()
{

    QDialog* popUp = new QDialog();
    popUp->setWindowTitle("Adding New Items");
    popUp->show();

    QLineEdit* productName = new QLineEdit(popUp);
    QLabel* productNameLabel = new QLabel("產品名稱",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&productName,&productNameLabel,100,20,50,23,200,100,50,100);

    QLineEdit* quantity = new QLineEdit(popUp);
    QLabel* quantityLabel = new QLabel("數量",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&quantity,&quantityLabel,100,20,120,90,200,100,50,100);

    QLineEdit* pricePerUnit = new QLineEdit(popUp);
    QLabel* pricePerUnitLabel = new QLabel("單價",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&pricePerUnit,&pricePerUnitLabel,100,20,190,160,200,100,50,100);

    QLineEdit* MJHR = new QLineEdit(popUp);
    QLabel* MJHRLabel = new QLabel("兆焦耳",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&MJHR,&MJHRLabel,100,20,260,230,200,100,50,100);

    QLineEdit* model = new QLineEdit(popUp);
    QLabel* modelLabel = new QLabel("模型",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&model,&modelLabel,100,20,330,300,200,100,50,100);

    QLineEdit* dimensions = new QLineEdit(popUp);
    QLabel* dimensionsLabel = new QLabel("尺寸",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensions,&dimensionsLabel,100,20,400,370,200,100,50,100);

    QRadioButton* discount = new QRadioButton("Yes",popUp);
    discount->setGeometry(400,50,100,100);
    discount->setEnabled(true);
    discount->show();

    QRadioButton* discounted = new QRadioButton("No",popUp);
    discounted->setGeometry(550,50,100,100);
    discounted->setEnabled(true);
    discounted->show();

    QLabel* discountLabel = new QLabel("香港中華煤氣有限公司(尊貴客戶)優惠",popUp);
    discountLabel->setGeometry(385,0,300,300);
    discountLabel->setFont(modFontSize(discountLabel->font(),10));
    discountLabel->show();

    QPushButton* complete = new QPushButton("完成",popUp);
    complete->setGeometry(475,180,40,40);
    complete->setFont(modFontSize(complete->font(),10));
    complete->show();
    QObject::connect(complete, &QPushButton::clicked,[&]{

    });
    return true;
}

std::string getCurrentDate()
{
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm,&now);
    return std::to_string(ltm.tm_mday) + "-" + std::to_string(ltm.tm_mon + 1) + "-" + std::to_string(ltm.tm_year + 1900);
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
    HELPFUNCTIONS_H::widgetConfig(wq,&fileName,&fileNameLabel,"檔案名稱:",150,50,50,13,200,100,25,100);

    customerName = new QLineEdit();
    customerNameLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&customerName,&customerNameLabel,"客戶名稱:",150,50,100,100,200,200,25,25);

    customerAddr = new QLineEdit();
    customerAddrLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&customerAddr,&customerAddrLabel,"客戶地址:",150,50,150,150,200,200,25,25);

    supervisor = new QLineEdit();
    supervisorLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&supervisor,&supervisorLabel,"負責人:",150,50,200,200,200,200,25,25);

    customerTel = new QLineEdit();
    customerTelLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&customerTel,&customerTelLabel,"電話:",550,450,50,50,200,200,25,25);

    customerID = new QLineEdit();
    customerIDLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&customerID,&customerIDLabel,"客戶編號:",550,450,100,100,200,200,25,25);

    quotationID = new QLineEdit();
    quotationIDLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&quotationID,&quotationIDLabel,"報價單號碼：",550,450,150,150,200,200,25,25);

    staff = new QLineEdit();
    staffLabel = new QLabel();
    HELPFUNCTIONS_H::widgetConfig(wq,&staff,&staffLabel,"職員：",550,450,200,200,200,200,25,25);

    submit = new QPushButton();
    submit->setText("完成");
    submit->setParent(wq);
    submit->setGeometry(380,500,50,50);
    submit->setFont(modFontSize(submit->font(),15));

    addItems = new QPushButton();
    addItems->setText("添加項目");
    addItems->setParent(wq);
    addItems->setGeometry(360,400,90,30);
    addItems->setFont(modFontSize(addItems->font(),15));
    QObject::connect(addItems,&QPushButton::clicked, [&]
    {
        getCurrentDate();
        //createNewItems();
    });

    editor->setCentralWidget(wq);
    return true;
}
