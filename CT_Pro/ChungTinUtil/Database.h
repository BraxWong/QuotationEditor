#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
class Database
{
	public:
		void databaseEntry(std::wstring ao, std::wstring pName, std::wstring modelName, std::string pDimensionsX, std::string pDimensionsY, 
			std::string pDimensionsZ, std::wstring approveNum, int quant, int price, float MH);
		bool itemExistsInDatabase(std::wstring ao);
		std::vector<std::wstring> dataToEditor(std::wstring ao);
};

