#include "buttonactions.h"
#include "quotationeditor.h"
#include "helpfunctions.h"
#include <codecvt>
#include "libxl.h"

using namespace libxl;

void exitProgram(QLabel *label, QPushButton *quit, QPushButton *createNewFile, MainWindow *window, QWidget *qw)
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


    int total = 0;
    Book* book = xlCreateBook();
   
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
    bold2Font->setSize(12);
    bold2Font->setName(L"Microsoft YaHei UI");
    Format* bold2Format = book->addFormat();
    bold2Format->setFont(bold2Font);
    bold2Format->setAlignH(ALIGNH_CENTER);

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
    underlineFont->setSize(12);

    Format* underlineFormat = book->addFormat();
    underlineFormat->setFont(underlineFont);
    underlineFormat->setAlignH(ALIGNH_CENTER);


    Format* cubicFormat = book->addFormat();
    cubicFormat->setBorderBottomColor(COLOR_BLACK);
    cubicFormat->setBorderTopColor(COLOR_WHITE);
    cubicFormat->setBorderRightColor(COLOR_WHITE);
    cubicFormat->setBorderLeftColor(COLOR_WHITE);
    cubicFormat->setFont(normalFont);
    cubicFormat->setBorder(BORDERSTYLE_MEDIUM);
    cubicFormat->setAlignH(ALIGNH_CENTER);
    cubicFormat->setAlignV(ALIGNV_CENTER);

    Sheet* sheet = HELPFUNCTIONS_H::insertPicture(&book, "Logo.png", 0, 10);
    sheet->setName(L"中天單入紙");

    sheet->setCol(0, 10, 8);
    sheet->setRow(1,25);
    sheet->setCol(1, 1, 30);
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
    sheet->writeFormula(7, 0, L"HYPERLINK(\"E-mail:chungtinkitchen@netvigator.com\")",linkFormat);
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
    sheet->writeStr(10,5, staffName2.c_str(), normalFormatLeft);
    sheet->writeStr(11, 0, L"負責人:", normalFormatRight);
    std::string supervisor = details->getSupervisor();
    std::wstring supervisor2(supervisor.begin(), supervisor.end());
    sheet->writeStr(11, 1, staffName2.c_str(), normalFormatLeft);
    sheet->writeStr(11, 4, L"日期:", normalFormatRight);
    std::string date = HELPFUNCTIONS_H::getCurrentDate();
    std::wstring date2(date.begin(), date.end());
    sheet->writeStr(11, 5, date2.c_str(), normalFormatLeft);
    sheet->writeStr(12, 0, L"電話:", normalFormatRight);
    std::string phone = std::to_string(details->getCustomerTel());
    std::wstring phone2(phone.begin(), phone.end());
    sheet->writeStr(12, 1, phone2.c_str(), normalFormatLeft);
    sheet->writeStr(13, 0, L"客戶編號:", normalFormatRight);
    std::string cusId = std::to_string(details->getCustomerID());
    std::wstring cusID2(cusId.begin(), cusId.end());
    sheet->writeStr(13, 1, cusID2.c_str(), normalFormatLeft);
    sheet->writeStr(14, 0, L"項目:", cubicFormat);
    sheet->writeStr(14, 1, L"內容:", cubicFormat);
    sheet->writeStr(14, 2, L"數量", cubicFormat);
    sheet->writeStr(14, 3, L"單價", cubicFormat);
    sheet->writeStr(14, 4, L"金額", cubicFormat);
    sheet->writeStr(14, 5, L"兆焦耳(MJ/HR)", cubicFormat);

    std::string path = HELPFUNCTIONS_H::get_desktop_path() + "/" + details->getfileName();
    std::wstring wstr(path.begin(), path.end());

    for (int i = 0; i < entries.size(); ++i)
    {
        sheet->writeNum(16, 0, i, normalFormat);
    }

    

    book->save(wstr.c_str());
    book->release();
    delete book;
    //for(int i = 0; i < entries.size(); ++i)
    //{
    //    quotationFile << HELPFUNCTIONS_H::centerText(std::to_string(i+1),10) << "," << entries[i]->getProductName() << "," << entries[i]->getQuantity() << ","
    //                  << "$" << entries[i]->getPricePerUnit() << "," << entries[i]->getTotalPrice() << "," << entries[i]->getMJHR() << "MJ/HR" << "\r\n" << ","
    //                  << entries[i]->getModel() << "\r\n" << "," << entries[i]->getDimensionsX() << "X" << entries[i]->getDimensionsY() << "X" << entries[i]->getDimensionsZ() << "H" << "\r\n";
    //    total += entries[i]->getTotalPrice();
    //    if(entries[i]->getDiscount() > 0)
    //    {
    //        quotationFile << "," << "香港中華煤氣有限公司(尊貴客戶)優惠" << "," << entries[i]->getDiscount() << "," << "-$" << entries[i]->getDiscount() * entries[i]->getPricePerUnit() << ","
    //                      << entries[i]->getDiscount() * entries[i]->getPricePerUnit() << "\r\n\r\n";
    //        total -=  entries[i]->getDiscount() * entries[i]->getPricePerUnit();
    //    }
    //}
    //quotationFile << total << "\r\n";
    //quotationFile.close();
    return true;
}


