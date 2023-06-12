#include "buttonactions.h"
#include "quotationeditor.h"
#include "helpfunctions.h"
#include <codecvt>

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
    std::ofstream quotationFile;
    quotationFile.open(HELPFUNCTIONS_H::get_desktop_path() + "/" +details->getfileName(),std::ios::out | std::ios::binary);
    quotationFile << '\xEF' << '\xBB' << '\xBF';
    //For header and customer details
    quotationFile << HELPFUNCTIONS_H::centerText("中天廚房設備有限公司",160) << "\r\n" << HELPFUNCTIONS_H::centerText("CHUNG TIN KITCHEN WARES COMPANY LIMITED",150)
                  << "\r\n" << HELPFUNCTIONS_H::centerText("香港九龍馬頭角道105號地下", 156) << "\r\n" << HELPFUNCTIONS_H::centerText("G/F 105 Ma Tau Kok Road Kowloon Hong Kong", 158)
                  << "\r\n" << HELPFUNCTIONS_H::centerText("電話: (852) 2363 1482  傳真: (852) 2766 1415", 157) << "\r\n" << HELPFUNCTIONS_H::centerText("機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)",157)
                  << "\r\n" << HELPFUNCTIONS_H::centerText("E-mail: chungtinkitchen@netvigator.com", 157) << "\r\n" << HELPFUNCTIONS_H::centerText("報價單",145) << "\r\n" << "  客戶名稱:"
                  << ',' << details->getCustomerName() << ",,," << "報價單號碼：" << "," << details->getQuotationID() << "\r\n" << "客戶地址:" << "," << details->getCustomerAddr() << ",,," << "Staff"
                  << "," << details->getStaffName() << "\r\n" << "負責人:" << "," << details->getSupervisor() << ",,," << "日期:" << "," << HELPFUNCTIONS_H::getCurrentDate() << "\r\n"
                  << "電話 :" << "," << std::to_string(details->getCustomerTel()) << "\r\n" << "客戶編號:" << "," << std::to_string(details->getCustomerID()) << "\r\n"
                  << HELPFUNCTIONS_H::centerText("項目", 5) << "," << "內容" << "," << "數量" << "," << HELPFUNCTIONS_H::centerText("單價",10) << "," << HELPFUNCTIONS_H::centerText("金額",10)
                  << "," << "兆焦耳(MJ/HR)" << "\r\n\r\n";
    //For entries
    for(int i = 0; i < entries.size(); ++i)
    {
        quotationFile << HELPFUNCTIONS_H::centerText(std::to_string(i+1),10) << "," << entries[i]->getProductName() << "," << entries[i]->getQuantity() << ","
                      << "$" << entries[i]->getPricePerUnit() << "," << entries[i]->getTotalPrice() << "," << entries[i]->getMJHR() << "MJ/HR" << "\r\n" << ","
                      << entries[i]->getModel() << "\r\n" << "," << entries[i]->getDimensionsX() << "X" << entries[i]->getDimensionsY() << "X" << entries[i]->getDimensionsZ() << "H" << "\r\n";
        total += entries[i]->getTotalPrice();
        if(entries[i]->getDiscount() > 0)
        {
            quotationFile << "," << "香港中華煤氣有限公司(尊貴客戶)優惠" << "," << entries[i]->getDiscount() << "," << "-$" << entries[i]->getDiscount() * entries[i]->getPricePerUnit() << ","
                          << entries[i]->getDiscount() * entries[i]->getPricePerUnit() << "\r\n\r\n";
            total -=  entries[i]->getDiscount() * entries[i]->getPricePerUnit();
        }
    }
    quotationFile << total << "\r\n";
    quotationFile.close();
    return true;
}


