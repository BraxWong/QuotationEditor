#include "quotationeditor.h"
#include "mainwindow.h"
#include "helpfunctions.h"
#include "customerDetails.h"
#include "entry.h"
#include "buttonactions.h"
#include "libxl.h"
#include "Database.h"
#include "error.h"
#include <codecvt>
#include <sstream>
#include <string>


using namespace libxl;

MainWindow* editor;
QLineEdit* fileName, *customerName, *customerAddr, *supervisor, *customerTel, *customerID, *quotationID, *staff, *productName, *quantity, *pricePerUnit, *MJHR, *model, *approvalNum, *additions,
    *dimensionsX, *dimensionsY, *dimensionsZ, *discount, *preOwned, *provided;
QLabel* fileNameLabel, * customerNameLabel, * customerAddrLabel, * supervisorLabel,
* customerTelLabel, * customerIDLabel, * quotationIDLabel, * staffLabel, * productNameLabel, * quantityLabel, * pricePerUnitLabel, * MJHRLabel, * modelLabel, * approvalNumLabel, *additionsLabel,
    *dimensionsLabel, *dimensionsLabel2, *dimensionsLabel3, *discountLabel, *preOwnedLabel, *providedLabel;
QWidget* wq;
QPushButton* submit, *addItems, *complete, *verifyItem;
QDialog* popUp;
customerDetails* details;
std::vector<entry*> entries;
entry* e;

bool createNewItems()
{
    popUp = new QDialog();
    popUp->setWindowTitle("Adding New Items");
    popUp->show();
    popUp->setAttribute(Qt::WA_DeleteOnClose);
    popUp->setFixedSize(700, 620);
    quantity = new QLineEdit(popUp);
    quantityLabel = new QLabel("數量", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&quantity, &quantityLabel, 100, 20, 120, 90, 200, 100, 50, 100);

    pricePerUnit = new QLineEdit(popUp);
    pricePerUnitLabel = new QLabel("單價", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&pricePerUnit, &pricePerUnitLabel, 100, 20, 190, 160, 200, 100, 50, 100);

    MJHR = new QLineEdit(popUp);
    MJHRLabel = new QLabel("兆焦耳", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&MJHR, &MJHRLabel, 100, 20, 260, 230, 200, 100, 50, 100);

    model = new QLineEdit(popUp);
    modelLabel = new QLabel("模型", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&model, &modelLabel, 100, 20, 330, 300, 200, 100, 50, 100);

    approvalNum = new QLineEdit(popUp);
    approvalNumLabel = new QLabel("批核編號", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&approvalNum, &approvalNumLabel, 100, 20, 400, 370, 200, 100, 50, 100);

    additions = new QLineEdit(popUp);
    additionsLabel = new QLabel("額外增加", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&additions, &additionsLabel, 100, 20, 470, 440, 200, 100, 50, 100);

    dimensionsX = new QLineEdit(popUp);
    dimensionsY = new QLineEdit(popUp);
    dimensionsZ = new QLineEdit(popUp);
    dimensionsLabel = new QLabel("尺寸", popUp);
    dimensionsLabel2 = new QLabel("X", popUp);
    dimensionsLabel3 = new QLabel("X", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensionsX, &dimensionsLabel, 100, 20, 540, 515, 50, 100, 50, 100);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensionsY, &dimensionsLabel2, 200, 170, 540, 510, 50, 100, 50, 100);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&dimensionsZ, &dimensionsLabel3, 300, 270, 540, 510, 50, 100, 50, 100);

    discount = new QLineEdit(popUp);
    discountLabel = new QLabel("香港中華煤氣有限公司(尊貴客戶)優惠", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&discount, &discountLabel, 420, 385, 180, 0, 200, 300, 50, 300);

    preOwned = new QLineEdit(popUp);
    preOwnedLabel = new QLabel("客戶現有爐具 Y/N", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&preOwned, &preOwnedLabel, 420, 450, 280, 100, 200, 300, 50, 300);

    provided = new QLineEdit(popUp);
    providedLabel = new QLabel("煤氣公司提供 Y/N", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&provided, &providedLabel, 420, 450, 380, 200, 200, 300, 50, 300);

    complete = new QPushButton("完成", popUp);
    complete->setGeometry(500, 450, 40, 40);
    complete->setFont(modFontSize(complete->font(), 10));
    complete->show();
    QObject::connect(complete, &QPushButton::clicked, [&] {

        std::wstring modelText, approvalText, additionText;
        if (approvalNum->text().isEmpty())
        {
            approvalText = L"N/A";
        }
        else
        {
            approvalText = approvalNum->text().toStdWString();
        }
        if (model->text().isEmpty())
        {
            modelText = L"N/A";
        }
        else
        {
            modelText = model->text().toStdWString();
        }
        if (additions->text().isEmpty())
        {
            additionText = L"N/A";
        }
        else
        {
            additionText = additions->text().toStdWString();
        }
        Database db;
        if (!db.itemExistsInDatabase(productName->text().toStdWString()))
        {
            db.databaseEntry(additionText, productName->text().toStdWString(), modelText, dimensionsX->text().toStdString(), dimensionsY->text().toStdString(), dimensionsZ->text().toStdString(), approvalText, std::stoi(quantity->text().toStdString()),
                std::stoi(pricePerUnit->text().toStdString()), std::stof(MJHR->text().toStdString()));
        }
        bool pO, pV;
        if (preOwned->text() == "Y" || preOwned->text() == "y" || preOwned->text() == "yes" || preOwned->text() == "Yes")
        {
            pO = true;
        }
        else
        {
            pO = false;
        }
        if (provided->text() == "Y" || provided->text() == "y" || provided->text() == "yes" || provided->text() == "Yes")
        {
            pV = true;
        }
        else
        {
            pV = false;
        }
        e = new entry(additionText, productName->text().toStdWString(), modelText, dimensionsX->text().toStdString(), dimensionsY->text().toStdString(), dimensionsZ->text().toStdString(), approvalText, std::stoi(quantity->text().toStdString()),
            std::stoi(pricePerUnit->text().toStdString()), std::stof(MJHR->text().toStdString()), std::stoi(discount->text().toStdString()), pO, pV);
        entries.push_back(e);
        popUp->close();
        delete popUp;
    });

    productName = new QLineEdit(popUp);
    productNameLabel = new QLabel("產品名稱", popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&productName, &productNameLabel, 100, 20, 50, 23, 200, 100, 50, 100);

    verifyItem = new QPushButton("查對", popUp);
    verifyItem->show();
    verifyItem->setGeometry(323, 53, 40, 40);
    verifyItem->setFont(modFontSize(verifyItem->font(), 10));
    QObject::connect(verifyItem, &QPushButton::clicked, [&] {
       Database db;
       db.itemExistsInDatabase(productName->text().toStdWString());
       if (db.itemExistsInDatabase(productName->text().toStdWString()))
       {
           std::vector<std::wstring> result = db.dataToEditor(productName->text().toStdWString());
           if (result.size() != 0)
           {
               model->setText(QString::fromStdWString(result[1]));
               additions->setText(QString::fromStdWString(result[2]));
               dimensionsX->setText(QString::fromStdWString(result[3]));
               dimensionsY->setText(QString::fromStdWString(result[4]));
               dimensionsZ->setText(QString::fromStdWString(result[5]));
               approvalNum->setText(QString::fromStdWString(result[6]));
               pricePerUnit->setText(QString::fromStdWString(result[7]));
               MJHR->setText(QString::fromStdWString(result[8]));
           }
       }
       else
       {
          error* Error = new error();
          Error->showError("This item is not in the database", 110,0,182,182);
       }
     });

   
    return true;
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
        {
            details = new customerDetails(customerName->text().toStdString(),customerAddr->text().toStdString(),supervisor->text().toStdString(),
                                          quotationID->text().toStdString(),staff->text().toStdString(),fileName->text().toStdString(),
                                          std::stoi(customerTel->text().toStdString()),customerID->text().toStdString());
            BUTTONACTIONS_H::appendToFile(details,entries);
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
