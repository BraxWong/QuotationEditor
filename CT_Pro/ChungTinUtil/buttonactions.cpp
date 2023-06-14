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


bool appendToFile(customerDetails* details, std::vector<entry*> entries)
{


    int total = 0;
    Book* book = xlCreateBook();
   



    Font* boldFont = book->addFont();
    boldFont->setBold();
    boldFont->setSize(15);
    boldFont->setName(L"Microsoft YaHei UI");
    Format* boldFormat = book->addFormat();
    boldFormat->setFont(boldFont);
    boldFormat->setAlignH(ALIGNH_CENTER);

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

    Sheet* sheet = HELPFUNCTIONS_H::insertPicture(&book, "Logo.png", 0, 10);


    sheet->setCol(1, 1, 30);
    sheet->writeStr(1, 1, L"中天廚房設備有限公司", boldFormat);
    sheet->setMerge(1, 1, 1, 5);
    sheet->writeStr(2, 1, L"CHUNG TIN KITCHEN WARES COMPANY LIMITED", bold2Format);
    sheet->setMerge(2, 2, 1, 5);
    sheet->writeStr(3, 1, L"香港九龍馬頭角道105號地下", normalFormat);
    sheet->setMerge(3, 3, 1, 5);
    sheet->writeStr(4, 1, L"G/F 105 Ma Tau Kok Road Kowloon Hong Kong", normalFormat);
    sheet->setMerge(4, 4, 1, 5);
    sheet->writeStr(5, 1, L"電話: (852) 2363 1482  傳真: (852) 2766 1415", normalFormat);
    sheet->setMerge(5, 5, 1, 5);
    sheet->writeStr(6, 1, L"機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)", normalFormat);
    sheet->setMerge(6, 6, 1, 5);
    sheet->writeFormula(7, 1, L"HYPERLINK(\"chungtinkitchen@netvigator.com\")",linkFormat);
    sheet->setMerge(7, 7, 1, 5);
    sheet->writeStr(8, 1, L"報價單", underlineFormat);
    sheet->setMerge(8, 8, 1, 5);

    std::string path = HELPFUNCTIONS_H::get_desktop_path() + "/" + details->getfileName();
    std::wstring wstr(path.begin(), path.end());


    

    book->save(wstr.c_str());
    book->release();
    delete book;

    //quotationFile << '\xEF' << '\xBB' << '\xBF';
    ////For header and customer details "客戶名稱:"
    //              << ',' << details->getCustomerName() << ",,," << "價單號碼：" << "," <<  "\"" << details->getQuotationID() << "\"\r\n" << "客戶地址:" << "," << details->getCustomerAddr() << ",,," << "Staff:"
    //              << "," << details->getStaffName() << "\r\n" << "負責人:"  << " " + details->getSupervisor() << ",,," << "日期:" << "," << HELPFUNCTIONS_H::getCurrentDate() << "\r\n"
    //              << "電話 :" << "," << std::to_string(details->getCustomerTel()) << "\r\n" << "客戶編號:" << "," << std::to_string(details->getCustomerID()) << "\r\n"
    //              << HELPFUNCTIONS_H::centerText("項目", 5) << "," << "內容" << "," << "數量" << "," << HELPFUNCTIONS_H::centerText("單價",10) << "," << HELPFUNCTIONS_H::centerText("金額",10)
    //              << "," << "兆焦耳(MJ/HR)" << "\r\n\r\n";
    ////For entries
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


