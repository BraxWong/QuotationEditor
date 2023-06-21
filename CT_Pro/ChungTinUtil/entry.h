#ifndef ENTRY_H
#define ENTRY_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

//TODO: Model has to be divided into 2 parts. Model name and approval number. Approval number can be empty.
class entry
{
public:
    entry(std::wstring ao,std::wstring pName, std::wstring modelName, std::string pDimensionsX, std::string pDimensionsY, std::string pDimensionsZ, std::wstring approveNum, int quant, int price, float MH, int D)
        :addOn(ao),productName(pName), quantity(quant),pricePerUnit(price),discount(D),MJHR(MH),
        model(modelName),dimensionsX(pDimensionsX),dimensionsY(pDimensionsY),dimensionsZ(pDimensionsZ),approvalNumber(approveNum)
    {
        MJHR = floor(MJHR * 100) / 100;
    }

    std::wstring getProductName() {return productName;}
    std::wstring getModel() {return model;}
    std::string getDimensionsX() {return dimensionsX;}
    std::string getDimensionsY() {return dimensionsY;}
    std::string getDimensionsZ() {return dimensionsZ;}
    std::wstring getApprovalNumber() { return approvalNumber; }
    std::wstring getAddOn() { return addOn; }
    int getQuantity() {return quantity;}
    int getPricePerUnit() {return pricePerUnit;}
    int getTotalPrice() {return totalPrice;}
    void setTotalPrice() {totalPrice = pricePerUnit * quantity;}
    float getMJHR() {return MJHR;}
    int getDiscount() {return discount;}

private:
    std::wstring productName, addOn;
    int quantity;
    int pricePerUnit;
    int totalPrice;
    int discount;
    float MJHR;
    std::wstring model;
    std::string dimensionsX, dimensionsY, dimensionsZ;
    std::wstring approvalNumber;

};

#endif // ENTRY_H
