#include "quotationeditor.h"
MainWindow* editor;
QLineEdit* fileName, *customerName, *customerAddr, *supervisor, *customerTel, *customerID, *quotationID, *staff, *productName, *quantity, *pricePerUnit, *MJHR, *model,
    *dimensionsX, *dimensionsY, *dimensionsZ;
QLabel* fileNameLabel, *customerNameLabel, *customerAddrLabel, *supervisorLabel,
    *customerTelLabel, *customerIDLabel, *quotationIDLabel, *staffLabel, *productNameLabel, *quantityLabel, *pricePerUnitLabel, *MJHRLabel, *modelLabel,
    *dimensionsLabel, *dimensionsLabel2, *dimensionsLabel3, *discountLabel;
QWidget* wq;
QPushButton* submit, *addItems, *complete;
QDialog* popUp;
QRadioButton* discount, *discounted;
customerDetails* details;
std::vector<entry*> entries;
entry* e;
bool createNewItems()
{
    popUp = new QDialog();
    popUp->setWindowTitle("Adding New Items");
    popUp->show();
    popUp->setAttribute(Qt::WA_DeleteOnClose);

    productName = new QLineEdit(popUp);
    productNameLabel = new QLabel("產品名稱",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&productName,&productNameLabel,100,20,50,23,200,100,50,100);

    quantity = new QLineEdit(popUp);
    quantityLabel = new QLabel("數量",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&quantity,&quantityLabel,100,20,120,90,200,100,50,100);

    pricePerUnit = new QLineEdit(popUp);
    pricePerUnitLabel = new QLabel("單價",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&pricePerUnit,&pricePerUnitLabel,100,20,190,160,200,100,50,100);

    MJHR = new QLineEdit(popUp);
    MJHRLabel = new QLabel("兆焦耳",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&MJHR,&MJHRLabel,100,20,260,230,200,100,50,100);

    model = new QLineEdit(popUp);
    modelLabel = new QLabel("模型",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&model,&modelLabel,100,20,330,300,200,100,50,100);

    dimensionsX = new QLineEdit(popUp);
    dimensionsY = new QLineEdit(popUp);
    dimensionsZ = new QLineEdit(popUp);
    dimensionsLabel = new QLabel("尺寸",popUp);
    dimensionsLabel2 = new QLabel("X",popUp);
    dimensionsLabel3 = new QLabel("X",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensionsX,&dimensionsLabel,100,20,400,375,50,100,50,100);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensionsY,&dimensionsLabel2,200,170,400,370,50,100,50,100);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensionsZ,&dimensionsLabel3,300,270,400,370,50,100,50,100);

    discount = new QRadioButton("Yes",popUp);
    discount->setGeometry(400,50,100,100);
    discount->show();

    discounted = new QRadioButton("No",popUp);
    discounted->setGeometry(550,50,100,100);
    discounted->show();

    discountLabel = new QLabel("香港中華煤氣有限公司(尊貴客戶)優惠",popUp);
    discountLabel->setGeometry(385,0,300,300);
    discountLabel->setFont(modFontSize(discountLabel->font(),10));
    discountLabel->show();

    complete = new QPushButton("完成",popUp);
    complete->setGeometry(475,180,40,40);
    complete->setFont(modFontSize(complete->font(),10));
    complete->show();
    QObject::connect(complete, &QPushButton::clicked,[&]{
        bool checked = false;
        //std::string pName, std::string modelName, std::string pDimensionsX, std::string pDimensionsY, std::string pDimensionsZ, int quant, int price, double MH, bool D
        if(discount->isChecked())
            checked = true;
        std::cout << discount->isChecked();
        e = new entry(productName->text().toStdString(),model->text().toStdString(),
                             dimensionsX->text().toStdString(),dimensionsY->text().toStdString(), dimensionsZ->text().toStdString(),
                             std::stoi(quantity->text().toStdString()), std::stoi(pricePerUnit->text().toStdString()), std::stod(MJHR->text().toStdString()),checked);
        entries.push_back(e);
        popUp->close();
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
    editor->setAttribute(Qt::WA_DeleteOnClose);
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
    QObject::connect(submit,&QPushButton::clicked, [&]{
        if(entries.size() != 0)
            details = new customerDetails(customerName->text().toStdString(),customerAddr->text().toStdString(),supervisor->text().toStdString(),
                                          quotationID->text().toStdString(),staff->text().toStdString(),fileName->text().toStdString(),
                                          std::stoi(customerTel->text().toStdString()),std::stoi(customerID->text().toStdString()));
        for(int i = 0; i < entries.size(); ++i)
        {
            std::cout << entries[i]->entryToString() << "\n";
        }
        editor->close();
    });

    addItems = new QPushButton();
    addItems->setText("添加項目");
    addItems->setParent(wq);
    addItems->setGeometry(360,400,90,30);
    addItems->setFont(modFontSize(addItems->font(),15));
    QObject::connect(addItems,&QPushButton::clicked, [&]
    {
        createNewItems();
    });

    editor->setCentralWidget(wq);
    return true;
}
