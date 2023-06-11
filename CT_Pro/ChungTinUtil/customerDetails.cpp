#include "customerDetails.h"


void CUSTOMERDETAILS_H::customerDetails::setFileName(std::string fName)
{
    if(fName[fName.length() - 1] != 'v' && fName[fName.length() - 2] != 's' && fName[fName.length() - 3] != 'c' && fName[fName.length() - 4] != '.')
    {
        std::string tmp;
        for(int i = 0; i < fName.length(); ++i)
        {
            if(fName[i] == '.')
            {
                break;
            }
            tmp += fName[i];
        }
        tmp += ".csv";
        this->fileName = tmp;
    }
    else
    {
        this->fileName = fName;
    }
}


