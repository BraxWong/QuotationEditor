#include "quotationeditor.h"
MainWindow* editor;
QLineEdit* fileName, *customerName, *customerAddr, *supervisor, *customerTel, *customerID, *quotationID, *staff;
QLabel* fileNameLabel, *customerNameLabel, *customerAddrLabel, *supervisorLabel, *customerTelLabel, *customerIDLabel, *quotationIDLabel, *staffLabel;
QWidget* wq;
QPushButton* submit, *addItems;

bool createNewItems(QWidget** wq)
{

    QDialog* popUp = new QDialog();
    popUp->setWindowTitle("Adding New Items");
    popUp->show();
    QWidget *widget = *wq;
    QLineEdit* productName = new QLineEdit(popUp);
    QLabel* productNameLabel = new QLabel("產品名稱",popUp);
    HELPFUNCTIONS_H::widgetConfigForPopUp(&productName,&productNameLabel,100,20,50,23,200,100,50,100);

    QLineEdit* quantity = new QLineEdit();
    QLabel* quantityLabel = new QLabel();
    quantity->setParent(widget);
    QLineEdit* pricePerUnit = new QLineEdit();
    QLabel* pricePerUnitLabel = new QLabel();
    pricePerUnit->setParent(widget);
    QLineEdit* MJHR = new QLineEdit();
    QLabel* MJHRLabel = new QLabel();
    MJHR->setParent(widget);
    QLineEdit* model = new QLineEdit();
    QLabel* modelLabel = new QLabel();
    model->setParent(widget);
    QLineEdit* size = new QLineEdit();
    QLabel* sizeLabel = new QLabel();
    size->setParent(widget);
    QMenu* discount = new QMenu("Discount");
    discount->setParent(widget);
    QAction* applied = discount->addAction("Yes");
    QAction* nApplied = discount->addAction("No");
    return true;
}

std::string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return std::to_string(ltm->tm_mday) + "-" + std::to_string(ltm->tm_mon + 1) + "-" + std::to_string(ltm->tm_year + 1900);
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
        createNewItems(&wq);
    });

    editor->setCentralWidget(wq);
    return true;
}
