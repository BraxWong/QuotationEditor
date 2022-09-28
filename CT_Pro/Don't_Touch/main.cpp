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
#define underline "\033[4m"
void clearUserInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class DB{
    public:
        void dataEntry();
        std::string saveFile(std::string fileName);
        void print();
        std::vector<std::string> dataRelease();
};
class DE{
    public:
        void defaultFile();
};

void DE::defaultFile() {
    //clearUserInput();
    std::ofstream object;
    std::string fileName, customerName, customerAdr, responder, quot_num, date;
    int tel, customer_id;
    std::cout << "Please name your file:\n";
    std::getline(std::cin,fileName);
    fileName += ".txt";
    object.open("output/"+fileName);
    object << std::setw(62) << "中天廚房設備有限公司\n" << std::setw(60) <<"CHUNG TIN KITCHEN WARES COMPANY LIMITED\n" << std::setw(66) << "香港九龍馬頭角道105號地下\n" << std::setw(64) << " G/F., 105 Ma Tau Kok Road, Kowloon, Hong Kong\n" << std::setw(69) << "電話: (852) 2363 1482  傳真: (852) 2766 1415\n" << std::setw(82) << "機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)\n" << std::setw(62) << "E-mail: chungtinkitchen@netvigator.com\n";
    object  << std::setw(47) << "報價單\n";

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
        return;
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
    std::string itemString, priceString, MJString,lines,lines2,lines3;
    itemString = saveFile("Database/Item.txt");
    priceString = saveFile("Database/price.txt");
    MJString = saveFile("Database/MJ.txt");

    //Erasing the files for edit
    std::ofstream item,price,mj;
    item.open("Database/Item.txt");
    price.open("Database/price.txt");
    mj.open("Database/MJ.txt");

    //Appending saved files into new files
    std::stringstream newLine(itemString), newLine2(priceString), newLine3(MJString);
    while(std::getline(newLine,lines,',')){
        item << lines << ",";
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
    object.open("Database/Item.txt");
    object2.open("Database/price.txt");
    object3.open("Database/MJ.txt");
    std::cout << "Item" <<std::setw(20) << "Price"  << std::setw(20) << "MJ" << std::endl;
    while(object.good()){
        std::string line, line2, line3;
        getline(object,line,',');
        getline(object2,line2,',');
        getline(object3,line3,',');
        std::cout << line << std::setw(20)<<  line2 << std::setw(15) <<  line3 << std::endl;
    }
}

int main() {
    // Menu menu;
    // menu.mainMenu();
    DE de;
    de.defaultFile();
    return 0;
}