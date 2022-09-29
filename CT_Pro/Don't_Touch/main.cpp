#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <limits>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
#include <cwchar>
#include <stddef.h>
#include <codecvt>
void clearUserInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class DB{
    public:
        void dataEntry();
        std::string saveFile(std::string fileName);
        std::wstring saveFile2(std::string fileName);
        void print();
        std::vector<std::string> dataRelease();
        std::vector<std::string> mjRelease();
        std::vector<std::string> priceRelease();
};
class DE{
    public:
        void defaultFile();
};

void DE::defaultFile() {
    clearUserInput();
    std::cout << "Use https://document.online-convert.com/convert-to-pdf to convert txt files to pdf files.\n";
    std::ofstream object;
    std::string fileName, customerName, customerAdr, responder, quot_num, date;
    std::vector<std::string> vectorItem, vectorPirce,vectorMJ;
    char quit;
    int tel, customer_id,count = 1, choice, quantity;
    std::cout << "Please name your file:\n";
    std::getline(std::cin,fileName);
    fileName += ".txt";
    object.open(fileName);
    object << std::setw(62) << "中天廚房設備有限公司\n" << std::setw(60) <<"CHUNG TIN KITCHEN WARES COMPANY LIMITED\n" << std::setw(66) << "香港九龍馬頭角道105號地下\n" << std::setw(63) << " G/F., 105 Ma Tau Kok Road, Kowloon, Hong Kong\n" << std::setw(68) << "電話: (852) 2363 1482  傳真: (852) 2766 1415\n" << std::setw(81) << "機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)\n" << std::setw(61) << "E-mail: chungtinkitchen@netvigator.com\n\n\n";
    object  << std::setw(47) << "報價單\n";
    std::cout << "Customer's Name:\n";
    std::getline(std::cin,customerName);
    std::cout << "Quotation Number:\n";
    std::getline(std::cin,quot_num);
    object << "客戶名稱: " << customerName <<std::setw(75) << "報價單號碼: " <<quot_num << std::endl;
    std::cout << "Customer's Address:\n";
    std::getline(std::cin, customerAdr);
    object << "客戶地址: " << customerAdr << std::setw(35) << "Staff: Nicole Wong\n";
    std::cout << "Responder:\n";
    std::getline(std::cin,responder);
    std::cout << "Date:(DD-MM-YYYY)\n";
    std::getline(std::cin,date);
    object << "負責人: " << responder << std::setw(75) << "日期： " << date << std::endl;
    std::cout << "Tel:\n";
    std::cin >> tel;
    std::cout << "Customer's ID:\n";
    std::cin >> customer_id;
    object << "電話: " << tel << std::setw(75) << "客戶編號: " << customer_id << std::endl;
    object << "項目 " << "內容" << std::setw(40) << "數量 " << " 單價" << " 金額" << " 兆焦耳(MJ/HR)\n";
    DB db;
    db.print();
    vectorItem = db.dataRelease();
    vectorPirce = db.priceRelease();
    vectorMJ = db.mjRelease();
    while(true){
        std::cout <<"Enter the number corresponded to the item: " << std::endl;
        std::cin >> choice;
        while(true){
            if(choice >= vectorItem.size()){
                std::cout << "The range is 1 - " << vectorItem.size() << std::endl;
                std::cout <<"Enter the number corresponded to the item: " << count << std::endl;
                std::cin >> choice;
            } 
            else {
                break;
            }
        }
        std::cout << "Quantity: " << std::endl;
        std::cin >> quantity;
        object << count << std::setw(20) << vectorItem[choice - 1] << std::setw(20) << quantity << std::setw(20) << quantity * std::stoi(vectorPirce[choice - 1]) << std::setw(20) << vectorPirce[choice - 1] << std::setw(20) << vectorMJ[choice - 1] << "MJ/HR";
        std::cout << "Press Q to exit and save the file.\n";
        std::cin >> quit;
        if(quit == 'Q' || quit == 'q'){
            break;
        }
        ++count;
    }
    object.close();
}
class Menu {
    public:
        void mainMenu();
};

void Menu::mainMenu() {
    int decide;
    std::cout << std::setw(60) << "Menu\n" << "Press 1: Database\nPress 2: Data Entry\n";
    std::cin >> decide;
    if(decide == 1){
        DB db;
        std::cout << "Press 1: Inserting data into database\nPress 2: Print out database\n";
        std::cin>>decide;
        if(decide == 1){
            db.dataEntry();
        }
        else {
            db.print();
        }
    }
    else {
        DE de;
        de.defaultFile();
    }
}
std::string DB::saveFile(std::string fileName) {
    std::ifstream object;
    std::string lines,save;
    object.open(fileName);
    while(object.good()){
        std::getline(object,save,'\n');
        lines = lines + save;
    }
    return lines;
}


void DB::dataEntry() {
    
    //Saving the files into strings
    std::string itemString, priceString, MJString,line,lines2,lines3;

    itemString = saveFile("Database/Item.txt");
    priceString = saveFile("Database/price.txt");
    MJString = saveFile("Database/MJ.txt");

    //Erasing the files for edit
    std::ofstream item, price,mj;
    item.open("Database/Item.txt");
    price.open("Database/price.txt");
    mj.open("Database/MJ.txt");

    //Appending saved files into new files
    std::stringstream newLine(itemString),newLine2(priceString), newLine3(MJString);
    while(std::getline(newLine,line,',')){
        item << line << ",";
    }
    while(std::getline(newLine2,lines2,',')){
        price << lines2 << ",";
    }
        while(std::getline(newLine3,lines3,',')){
        mj << lines3 << ",";
    }

    //Adding new items to the file
    std::string itemName;
    int Price;
    float MJ;
    char quit;
    while(true){
        clearUserInput();
        std::cout << "Item Name:\n";
        std::getline(std::cin,itemName);
        item << itemName << ",";
        std::cout << "Price:\n";
        std::cin >> Price;
        price << Price << ",";
        std::cout << "MJ:\n";
        std::cin >> MJ;
        mj << MJ << ",";
        std::cout << "Finished? (Q to exit, Any Key to continue)";
        std::cin >> quit;
        if(quit == 'Q' || quit == 'q'){
            break;
        }
    }
    item.close();
    price.close();
    mj.close();
}

void DB::print() {
    std::ifstream object, object2, object3;
    char something;
    int count = 1;
    object.open("Database/Item.txt");
    object2.open("Database/price.txt");
    object3.open("Database/MJ.txt");
    std::cout << "Item" <<std::setw(20) << "Price"  << std::setw(20) << "MJ" << std::endl;
    while(object.good()){
        std::string line, line2, line3;
        getline(object,line,',');
        getline(object2,line2,',');
        getline(object3,line3,',');
        std::cout << "Press " << count  << " for: "<< line << std::setw(20)<<  line2 << std::setw(15) <<  line3 << std::endl;
        ++count;
    }
    std::cout << "Press Q to quit\n";
    std::cin >> something;
    if(something == 'Q' || something == 'q'){
        return;
    }
}

std::vector<std::string> DB::dataRelease() {
    std::ifstream object1;
    object1.open("Database/Item.txt");
    std::vector<std::string> result;
    while(object1.good()){
        std::string line;
        getline(object1,line,',');
        result.push_back(line);
    }
    return result;
}

std::vector<std::string> DB::mjRelease() {
    std::ifstream object1;
    object1.open("Database/MJ.txt");
    std::vector<std::string> result;
    while(object1.good()){
        std::string mj;
        getline(object1,mj,',');
        result.push_back(mj);
    }
    return result;
}

std::vector<std::string> DB::priceRelease() {
    std::ifstream object1;
    object1.open("Database/price.txt");
    std::vector<std::string> result;
    while(object1.good()){
        std::string line;
        getline(object1,line,',');
        result.push_back(line);
    }
    return result;
}
int main() {
    Menu menu;
    menu.mainMenu();
    return 0;
}