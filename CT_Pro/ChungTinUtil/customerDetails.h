#ifndef CUSTOMERDETAILS_H
#define CUSTOMERDETAILS_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class customerDetails
{
public:
    customerDetails(std::string cName, std::string cAddr, std::string supe, std::string qID, std::string sName, std::string fName, int cTel, int cID)
        :customerName(cName),customerAddr(cAddr), supervisor(supe), quotationID(qID), staffName(sName), customerTel(cTel), customerID(cID)
    {
        setFileName(fName);
    }

    void setFileName(std::string fName);
    std::string getCustomerName() {return customerName;}
    std::string getCustomerAddr() {return customerAddr;}
    std::string getSupervisor() {return supervisor;}
    std::string getQuotationID() {return quotationID;}
    std::string getStaffName() {return staffName;}
    std::string getfileName() {return fileName;}
    int getCustomerTel() {return customerTel;}
    int getCustomerID() {return customerID;}
    ~customerDetails();

private:
    std::string customerName;
    std::string customerAddr;
    std::string supervisor;
    std::string quotationID;
    std::string staffName;
    std::string fileName;
    int customerTel;
    int customerID;
};

#endif // CUSTOMERDETAILS_H
