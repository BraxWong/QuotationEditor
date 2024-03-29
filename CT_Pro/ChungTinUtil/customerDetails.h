#ifndef CUSTOMERDETAILS_H
#define CUSTOMERDETAILS_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
class customerDetails
{
public:

    //Constructor
    customerDetails(std::string cName, std::string cAddr, std::string supe, std::string qID, std::string sName, std::string fName, int cTel, std::string cID)
        :customerName(cName),customerAddr(cAddr), supervisor(supe), quotationID(qID), staffName(sName), customerTel(cTel), customerID(cID)
    {
        setFileName(fName);
    }

    //@setFileName()
    //@Param: std::string fName"
    //@Descriptions: Will check if the name of the file ends with ".csv". If not it will append ".csv" to the end of the string
    //               then store it in fileName variable.
    void setFileName(std::string fName);
    std::string getCustomerName() {return customerName;}
    std::string getCustomerAddr() {return customerAddr;}
    std::string getSupervisor() {return supervisor;}
    std::string getQuotationID() {return quotationID;}
    std::string getStaffName() {return staffName;}
    std::string getfileName() {return fileName;}
    std::string customerDetailsToString() {return getCustomerName() + "\n" + getCustomerAddr() + "\n" + getSupervisor() +
                                           "\n" + getQuotationID() + "\n" + getStaffName() + "\n" + getfileName() + "\n"
                                           + std::to_string(getCustomerTel()) + "\n" + std::to_string(getCustomerID()) + "\n"; }
    int getCustomerTel() {return customerTel;}
    std::string getCustomerID() {return customerID;}
    ~customerDetails();

private:
    std::string customerName;
    std::string customerAddr;
    std::string supervisor;
    std::string quotationID;
    std::string staffName;
    std::string fileName;
    int customerTel;
    std::string customerID;
};

#endif // CUSTOMERDETAILS_H
