#ifndef ENTRY_H
#define ENTRY_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

class entry
{
public:
    entry(std::string pName, std::string modelName, std::string pDimensionsX, std::string pDimensionsY, std::string pDimensionsZ, int quant, int price, double MH, int D)
        :productName(pName), quantity(quant),pricePerUnit(price),discount(D),MJHR(MH),
        model(modelName),dimensionsX(pDimensionsX),dimensionsY(pDimensionsY),dimensionsZ(pDimensionsZ)
    {

    }

    std::string getProductName() {return productName;}
    std::string getModel() {return model;}
    std::string getDimensionsX() {return dimensionsX;}
    std::string getDimensionsY() {return dimensionsY;}
    std::string getDimensionsZ() {return dimensionsZ;}
    std::string entryToString() {return getProductName() + "\n" + getModel() + "\n" + getDimensionsX() + "\n" +
                                        getDimensionsY() + "\n" + getDimensionsZ() + "\n" + std::to_string(getQuantity()) + "\n"
                                        + std::to_string(getPricePerUnit()) + "\n" + std::to_string(getMJHR()) + "\n" +
                                        std::to_string(getDiscount()) + "\n";
    }
    int getQuantity() {return quantity;}
    int getPricePerUnit() {return pricePerUnit;}
    int getTotalPrice() {return totalPrice;}
    void setTotalPrice() {totalPrice = pricePerUnit * quantity;}
    double getMJHR() {return MJHR;}
    int getDiscount() {return discount;}

private:
    std::string productName;
    int quantity;
    int pricePerUnit;
    int totalPrice;
    int discount;
    double MJHR;
    std::string model;
    std::string dimensionsX, dimensionsY, dimensionsZ;

};

#endif // ENTRY_H
