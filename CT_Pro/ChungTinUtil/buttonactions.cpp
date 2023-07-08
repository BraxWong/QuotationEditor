#include "buttonactions.h"
#include "quotationeditor.h"
#include "helpfunctions.h"
#include <codecvt>
#include "libxl.h"
using namespace libxl;

void exitProgram(QLabel* label, QPushButton* quit, QPushButton* createNewFile, MainWindow* window, QWidget* qw)
{
    qw = nullptr;
    delete qw;
    window = nullptr;
    delete window;
    quit = nullptr;
    delete quit;
    label = nullptr;
    delete label;
    createNewFile = nullptr;
    delete createNewFile;
    exit(0);
}

bool createNewFile()
{
    QUOTATIONEDITOR_H::quotationEditorSetup();
    return true;
}

bool modifyDataBase()
{
    return true;
}


//Forgive me for this abomination
bool appendToFile(customerDetails* details, std::vector<entry*> entries)
{


    int total = 0, totalDiscount = 0;
    float totalMR = 0;
    Book* book = xlCreateBook();

    Font* underlineBoldFont = book->addFont();
    underlineBoldFont->setBold(true);
    underlineBoldFont->setUnderline(UNDERLINE_SINGLEACC);
    underlineBoldFont->setSize(10);
    Format* underlineBoldFormat = book->addFormat();
    underlineBoldFormat->setFont(underlineBoldFont);
    underlineBoldFormat->setAlignH(ALIGNH_LEFT);

    Font* boldFont = book->addFont();
    boldFont->setBold();
    boldFont->setSize(18);
    boldFont->setName(L"Microsoft YaHei UI");
    Format* boldFormat = book->addFormat();
    boldFormat->setFont(boldFont);
    boldFormat->setAlignH(ALIGNH_CENTER);
    boldFormat->setAlignV(ALIGNV_CENTER);

    Font* bold2Font = book->addFont();
    bold2Font->setBold();
    bold2Font->setSize(10);
    bold2Font->setName(L"Microsoft YaHei UI");
    Format* bold2Format = book->addFormat();
    bold2Format->setFont(bold2Font);
    bold2Format->setAlignH(ALIGNH_CENTER);

    Font* boldFontRight = book->addFont();
    boldFontRight->setBold();
    boldFontRight->setSize(10);
    boldFontRight->setName(L"Microsoft YaHei UI");
    Format* bold2FormatRight = book->addFormat();
    bold2FormatRight->setFont(boldFontRight);
    bold2FormatRight->setAlignH(ALIGNH_RIGHT);

    Font* boldFontLeft = book->addFont();
    boldFontLeft->setBold();
    boldFontLeft->setSize(10);
    boldFontLeft->setName(L"Microsoft YaHei UI");
    Format* bold2FormatLeft = book->addFormat();
    bold2FormatLeft->setFont(boldFontLeft);
    bold2FormatLeft->setAlignH(ALIGNH_LEFT);

    Font* normalFont = book->addFont();
    normalFont->setSize(10);
    normalFont->setName(L"Microsoft YaHei UI");
    Format* normalFormat = book->addFormat();
    normalFormat->setFont(normalFont);
    normalFormat->setAlignH(ALIGNH_CENTER);
    normalFormat->setAlignV(ALIGNV_CENTER);

    Font* normalFontLeft = book->addFont();
    normalFontLeft->setSize(10);
    Format* normalFormatLeft = book->addFormat();
    normalFormatLeft->setFont(normalFontLeft);
    normalFormatLeft->setAlignH(ALIGNH_LEFT);

    Font* normalFontRight = book->addFont();
    normalFontRight->setSize(10);
    Format* normalFormatRight = book->addFormat();
    normalFormatRight->setFont(normalFontRight);
    normalFormatRight->setAlignH(ALIGNH_RIGHT);

    Font* linkFont = book->addFont();
    linkFont->setColor(COLOR_BLUE);
    linkFont->setUnderline(UNDERLINE_SINGLE);

    Format* linkFormat = book->addFormat();
    linkFormat->setFont(linkFont);
    linkFormat->setAlignH(ALIGNH_CENTER);


    Font* underlineFont = book->addFont();
    underlineFont->setUnderline(UNDERLINE_SINGLE);
    underlineFont->setBold(true);
    underlineFont->setSize(10);

    Format* underlineFormat = book->addFormat();
    underlineFormat->setFont(underlineFont);
    underlineFormat->setAlignH(ALIGNH_CENTER);

    Font* cubicFont = book->addFont();
    cubicFont->setSize(10);
    cubicFont->setUnderline(UNDERLINE_SINGLEACC);
    Format* cubicFormat = book->addFormat();
    cubicFormat->setFont(cubicFont);
    cubicFormat->setAlignH(ALIGNH_CENTER);
    cubicFormat->setAlignV(ALIGNV_CENTER);

    Format* dollarFormat = book->addFormat(normalFormatRight);
    dollarFormat->setNumFormat(book->addCustomNumFormat(L"_( $* #,##0.00_);_( $* (#,##0.00);_( $* -??_);_(@_)"));

    Font* discountFont = book->addFont();
    discountFont->setUnderline(UNDERLINE_SINGLEACC);
    Format* discountFormat = book->addFormat();
    discountFormat->setNumFormat(book->addCustomNumFormat(L"_(-$* #,##0.00_);_(-$* (#,##0.00);_(-$* -??_);_(@_)"));
    Format* finalDiscountFormat = book->addFormat(discountFormat);
    finalDiscountFormat->setFont(discountFont);
    finalDiscountFormat->setAlignH(ALIGNH_RIGHT);



    Format* MJFormat = book->addFormat(normalFormatRight);
    MJFormat->setNumFormat(book->addCustomNumFormat(L"#.0#\"MJ/HR\""));

    Sheet* sheet = HELPFUNCTIONS_H::insertPicture(&book, "Logo.png", 0, 10);
    sheet->setName(L"中天單入紙");

    sheet->setCol(0, 10, 8);
    sheet->setRow(1, 25);
    sheet->setCol(1, 1, 40);
    sheet->setCol(2, 2, 4);
    sheet->setCol(3, 5, 14);
    sheet->setRow(6, 15);
    sheet->setRow(14, 15);


    sheet->writeStr(1, 0, L"中天廚房設備有限公司", boldFormat);
    sheet->setMerge(1, 1, 0, 5);
    sheet->writeStr(2, 0, L"CHUNG TIN KITCHEN WARES COMPANY LIMITED", bold2Format);
    sheet->setMerge(2, 2, 0, 5);
    sheet->writeStr(3, 0, L"香港九龍馬頭角道105號地下", normalFormat);
    sheet->setMerge(3, 3, 0, 5);
    sheet->writeStr(4, 0, L"G/F 105 Ma Tau Kok Road Kowloon Hong Kong", normalFormat);
    sheet->setMerge(4, 4, 0, 5);
    sheet->writeStr(5, 0, L"電話: (852) 2363 1482  傳真: (852) 2766 1415", normalFormat);
    sheet->setMerge(5, 5, 0, 5);
    sheet->writeStr(6, 0, L"機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)", normalFormat);
    sheet->setMerge(6, 6, 0, 5);
    sheet->writeFormula(7, 0, L"HYPERLINK(\"E-mail:chungtinkitchen@netvigator.com\")", linkFormat);
    sheet->setMerge(7, 7, 0, 5);
    sheet->writeStr(8, 0, L"報價單", underlineFormat);
    sheet->setMerge(8, 8, 0, 5);
    sheet->writeStr(9, 0, L"客戶名稱:", normalFormatRight);
    std::string name = details->getCustomerName();
    std::wstring name2(name.begin(), name.end());
    sheet->writeStr(9, 1, name2.c_str(), normalFormatLeft);
    sheet->writeStr(9, 4, L"報價單號碼:", normalFormatRight);
    std::string quotationID = details->getQuotationID();
    std::wstring quotationID2(quotationID.begin(), quotationID.end());
    sheet->writeStr(9, 5, quotationID2.c_str(), normalFormatLeft);
    sheet->writeStr(10, 0, L"客戶地址:", normalFormatRight);
    std::string addr = details->getCustomerAddr();
    std::wstring addr2(addr.begin(), addr.end());
    sheet->writeStr(10, 1, addr2.c_str(), normalFormatLeft);
    sheet->writeStr(10, 4, L"Staff:", normalFormatRight);
    std::string staffName = details->getStaffName();
    std::wstring staffName2(staffName.begin(), staffName.end());
    sheet->writeStr(10, 5, staffName2.c_str(), normalFormatLeft);
    sheet->writeStr(11, 0, L"負責人:", normalFormatRight);
    std::string supervisor = details->getSupervisor();
    std::wstring supervisor2(supervisor.begin(), supervisor.end());
    sheet->writeStr(11, 1, supervisor2.c_str(), normalFormatLeft);
    sheet->writeStr(11, 4, L"日期:", normalFormatRight);
    std::string date = HELPFUNCTIONS_H::getCurrentDate();
    std::wstring date2(date.begin(), date.end());
    sheet->writeStr(11, 5, date2.c_str(), normalFormatLeft);
    sheet->writeStr(12, 0, L"電話:", normalFormatRight);
    std::string phone = std::to_string(details->getCustomerTel());
    std::wstring phone2(phone.begin(), phone.end());
    sheet->writeStr(12, 1, phone2.c_str(), normalFormatLeft);
    sheet->writeStr(13, 0, L"客戶編號:", normalFormatRight);
    std::string cusId = details->getCustomerID();
    std::wstring cusID2(cusId.begin(), cusId.end());
    sheet->writeStr(13, 1, cusID2.c_str(), normalFormatLeft);
    sheet->writeStr(14, 0, L"項目:", cubicFormat);
    sheet->writeStr(14, 1, L"內容:", cubicFormat);
    sheet->writeStr(14, 2, L"數量", cubicFormat);
    sheet->writeStr(14, 3, L"單價", cubicFormat);
    sheet->writeStr(14, 4, L"金額", cubicFormat);
    sheet->writeStr(14, 5, L"兆焦耳(MJ/HR)", cubicFormat);

    int rowNum = 16;

    for (int i = 0; i < entries.size(); ++i)
    {
        int columnNum = 0;
        sheet->writeNum(rowNum, columnNum, i + 1, normalFormat);
        columnNum++;
        std::wstring stoveName = entries[i]->getProductName();
        sheet->writeStr(rowNum, columnNum, stoveName.c_str(), normalFormatLeft);
        columnNum++;
        sheet->writeNum(rowNum, columnNum, entries[i]->getQuantity(), normalFormat);
        columnNum++;
        if (entries[i]->getPreExists() == true || entries[i]->getProvided() == true)
        {
            if (entries[i]->getPreExists() == true)
            {
                sheet->setMerge(rowNum, rowNum, columnNum, columnNum+1);
                sheet->writeStr(rowNum, columnNum, L"客戶現有爐具", normalFormat);
                columnNum++;
                sheet->writeNum(rowNum, columnNum, entries[i]->getMJHR(), MJFormat);
                totalMR += entries[i]->getMJHR();
            }
            else if (entries[i]->getProvided() == true)
            {
                sheet->setMerge(rowNum, rowNum, columnNum, columnNum + 1);
                sheet->writeStr(rowNum, columnNum, L"煤氣公司提供", normalFormat);
                rowNum++;
                sheet->writeStr(rowNum, columnNum, L"香港中華煤氣有限公司(尊貴客戶)優惠", normalFormatLeft);
                columnNum++;
                sheet->writeNum(rowNum, columnNum, 1, normalFormat);
                columnNum++;
                sheet->setMerge(rowNum, rowNum, columnNum, columnNum + 1);
                sheet->writeStr(rowNum, columnNum, L"煤氣公司提供", normalFormat);
            }
        }
        else
        {
            std::string pricePerUnit = std::to_string(entries[i]->getPricePerUnit());
            std::wstring pricePerUnit2(pricePerUnit.begin(), pricePerUnit.end());
            sheet->writeNum(rowNum, columnNum, entries[i]->getPricePerUnit(), dollarFormat);
            columnNum++;
            int currentProductTotal = entries[i]->getQuantity() * entries[i]->getPricePerUnit();
            total += currentProductTotal;
            sheet->writeNum(rowNum, columnNum, currentProductTotal, dollarFormat);
            columnNum++;
            sheet->writeNum(rowNum, columnNum, entries[i]->getMJHR(), MJFormat);
            totalMR += entries[i]->getMJHR();
            rowNum++;
            columnNum = 1;
            std::wstring model;
            if (entries[i]->getAddOn() != L"N/A")
            {
                model += L"(" + entries[i]->getAddOn() + L")";
            }
            if (entries[i]->getModel() != L"N/A")
            {
                model += L"型號:" + entries[i]->getModel();
            }
            if (entries[i]->getApprovalNumber() != L"N/A")
            {
                model += L",批核編號(" + entries[i]->getApprovalNumber() + L")";
            }
            sheet->writeStr(rowNum, columnNum, model.c_str(), normalFormatLeft);
            rowNum++;
            std::string dimensions = entries[i]->getDimensionsX() + "X" + entries[i]->getDimensionsY() + "X" + entries[i]->getDimensionsZ() + "H";
            std::wstring dimensions2(dimensions.begin(), dimensions.end());
            sheet->writeStr(rowNum, columnNum, dimensions2.c_str(), normalFormatLeft);
            if (entries[i]->getDiscount() > 0)
            {
                rowNum++;
                sheet->writeStr(rowNum, columnNum, L"香港中華煤氣有限公司(尊貴客戶)優惠", normalFormatLeft);
                columnNum++;
                sheet->writeNum(rowNum, columnNum, 1, normalFormat);
                columnNum++;
                sheet->writeNum(rowNum, columnNum, entries[i]->getDiscount(), discountFormat);
                columnNum++;
                sheet->writeNum(rowNum, columnNum, entries[i]->getDiscount(), discountFormat);
                totalDiscount += entries[i]->getDiscount();
            }
        }
       
        rowNum += 2;
    }
    endOfFile(total, totalDiscount, totalMR, &book, &sheet, rowNum, details);
    return true;
}

bool endOfFile(int total, int totalDiscount, float totalMR, Book** newBook, Sheet** newSheet, int rowNum, customerDetails* details)
{
    Sheet* sheet = *newSheet;
    Book* book = *newBook;

    Font* boldFontRight = book->addFont();
    boldFontRight->setBold();
    boldFontRight->setSize(10);
    boldFontRight->setName(L"Microsoft YaHei UI");
    Format* bold2FormatRight = book->addFormat();
    bold2FormatRight->setFont(boldFontRight);
    bold2FormatRight->setAlignH(ALIGNH_RIGHT);

    Font* boldFontLeft = book->addFont();
    boldFontLeft->setBold();
    boldFontLeft->setSize(10);
    boldFontLeft->setName(L"Microsoft YaHei UI");
    Format* bold2FormatLeft = book->addFormat();
    bold2FormatLeft->setFont(boldFontLeft);
    bold2FormatLeft->setAlignH(ALIGNH_LEFT);

    Font* cubicFont = book->addFont();
    cubicFont->setSize(10);
    cubicFont->setUnderline(UNDERLINE_SINGLEACC);
    Format* cubicFormat = book->addFormat();
    cubicFormat->setFont(cubicFont);
    cubicFormat->setAlignH(ALIGNH_CENTER);
    cubicFormat->setAlignV(ALIGNV_CENTER);

    Font* normalFontRight = book->addFont();
    normalFontRight->setSize(10);
    Format* normalFormatRight = book->addFormat();
    normalFormatRight->setFont(normalFontRight);
    normalFormatRight->setAlignH(ALIGNH_RIGHT);

    Font* discountFont = book->addFont();
    discountFont->setUnderline(UNDERLINE_SINGLEACC);
    Format* discountFormat = book->addFormat();
    discountFormat->setNumFormat(book->addCustomNumFormat(L"_(-$* #,##0.00_);_(-$* (#,##0.00);_(-$* -??_);_(@_)"));
    Format* finalDiscountFormat = book->addFormat(discountFormat);
    finalDiscountFormat->setFont(discountFont);
    finalDiscountFormat->setAlignH(ALIGNH_RIGHT);

    Format* dollarFormat = book->addFormat(normalFormatRight);
    dollarFormat->setNumFormat(book->addCustomNumFormat(L"_( $* #,##0.00_);_( $* (#,##0.00);_( $* -??_);_(@_)"));

    Font* dollarBoldFont = book->addFont();
    dollarBoldFont->setBold(true);
    dollarBoldFont->setSize(10);
    dollarBoldFont->setUnderline(UNDERLINE_DOUBLE);
    Format* dollarBoldFormat = book->addFormat(dollarFormat);
    dollarBoldFormat->setFont(dollarBoldFont);
    dollarBoldFormat->setAlignH(ALIGNH_RIGHT);

    Font* zeroDollarBoldFont = book->addFont();
    zeroDollarBoldFont->setBold(true);
    zeroDollarBoldFont->setSize(10);
    zeroDollarBoldFont->setUnderline(UNDERLINE_DOUBLEACC);
    Format* zeroDollarBoldFormat = book->addFormat();
    zeroDollarBoldFormat->setFont(zeroDollarBoldFont);
    zeroDollarBoldFormat->setAlignH(ALIGNH_RIGHT);

    Font* normalFont = book->addFont();
    normalFont->setSize(10);
    normalFont->setName(L"Microsoft YaHei UI");
    Format* normalFormat = book->addFormat();
    normalFormat->setFont(normalFont);
    normalFormat->setAlignH(ALIGNH_CENTER);
    normalFormat->setAlignV(ALIGNV_CENTER);

    Font* MJBoldFont = book->addFont();
    MJBoldFont->setBold(true);
    MJBoldFont->setSize(10);
    Format* MJBoldFormat = book->addFormat();
    MJBoldFormat->setFont(MJBoldFont);
    MJBoldFormat->setNumFormat(book->addCustomNumFormat(L"#.0#\"MJ/HR\""));

    Font* underlineBoldFont = book->addFont();
    underlineBoldFont->setBold(true);
    underlineBoldFont->setUnderline(UNDERLINE_SINGLE);
    underlineBoldFont->setSize(10);
    Format* underlineBoldFormat = book->addFormat();
    underlineBoldFormat->setFont(underlineBoldFont);
    underlineBoldFormat->setAlignH(ALIGNH_LEFT);

    Font* normalFontLeft = book->addFont();
    normalFontLeft->setSize(10);
    Format* normalFormatLeft = book->addFormat();
    normalFormatLeft->setFont(normalFontLeft);
    normalFormatLeft->setAlignH(ALIGNH_LEFT);

    sheet->writeStr(rowNum, 0, L"*", bold2FormatRight);
    sheet->writeStr(rowNum, 1, L"以上報價不包括煤氣錶按金及街喉費用", bold2FormatLeft);
    rowNum++;
    sheet->writeStr(rowNum, 4, L" ", cubicFormat);
    rowNum++;
    sheet->writeStr(rowNum, 3, L"合共金額:", normalFormatRight);
    sheet->writeNum(rowNum, 4, total, dollarFormat);
    rowNum++;
    sheet->writeStr(rowNum, 3, L"香港中華煤氣有限公司『尊貴客戶』優惠 - 合共金額:", normalFormatRight);
    sheet->writeNum(rowNum, 4, totalDiscount, finalDiscountFormat);
    rowNum++;
    sheet->writeStr(rowNum, 3, L"客人應付金額:", bold2FormatRight);
    if (total - totalDiscount == 0)
    {
        sheet->writeStr(rowNum, 4, L"$0", zeroDollarBoldFormat);
    }
    else
    {
        sheet->writeNum(rowNum, 4, total - totalDiscount, dollarBoldFormat);
    }
    rowNum++;
    sheet->writeStr(rowNum, 4, L"合共兆焦耳(MJ/HR)", bold2FormatRight);
    sheet->writeNum(rowNum, 5, totalMR, MJBoldFormat);
    rowNum += 2;
    sheet->writeStr(rowNum, 0, L"* 備注 : ", bold2FormatRight);
    sheet->writeStr(rowNum, 1, L"1)上述 (尊貴客戶) 爐具優惠以香港中華煤氣有限公司最後批核作準。", underlineBoldFormat);
    rowNum++;
    sheet->writeStr(rowNum, 1, L"2)上述兆焦耳(MJ/HR) 以最後現場已完成之爐具批核作準, 如超過1150MJ/HR, ", underlineBoldFormat);
    rowNum++;
    sheet->writeStr(rowNum, 1, L"客人需自行申報環保。", underlineBoldFormat);
    rowNum++;
    sheet->writeStr(rowNum, 1, L"上述所有由香港中華煤氣有限公司提供(尊貴客戶)優惠", normalFormatLeft);
    rowNum++;
    sheet->writeStr(rowNum, 1, L"之爐具已包括本公司首年之免費維修保養及零件更換.", normalFormatLeft);
    rowNum += 2;
    sheet->setMerge(rowNum, rowNum, 4, 5);
    sheet->writeStr(rowNum, 1, L"客戶簽署及蓋印", normalFormatLeft);
    sheet->writeStr(rowNum, 4, L"中天廚房設備有限公司", normalFormat);
    rowNum += 5;
    sheet->setMerge(rowNum, rowNum, 4, 5);
    sheet->writeStr(rowNum, 1, L" ", cubicFormat);
    sheet->writeStr(rowNum, 4, L" ", cubicFormat);


    std::string path = HELPFUNCTIONS_H::get_desktop_path() + "/" + details->getfileName();
    std::wstring wstr(path.begin(), path.end());
    book->save(wstr.c_str());
    book->release();
    return false;
}

