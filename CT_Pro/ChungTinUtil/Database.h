#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
class Database
{
	public:
		//@databaseEntry()
		//@Param: std::wstring ao, std::wstring pName, std::wstring modelName, std::string pDimensionsX, std::string pDimensionsY, 
		//		  std::string pDimensionsZ, std::wstring approveNum, int quant, int price, float MH
		//@Descriptions: It will first call itemExistsInDatabase to see if the product exists within the database, if so no actions will be performed.
		//				 If the product does not exist within the database, then all the parameter will be written into the database
		void databaseEntry(std::wstring ao, std::wstring pName, std::wstring modelName, std::string pDimensionsX, std::string pDimensionsY, 
			std::string pDimensionsZ, std::wstring approveNum, int quant, int price, float MH);
		//@itemExistsInDatabase()
		//@Param: std::wstring ao
		//@Descriptions: It will check if the product is already in the database, if so it will return true. If it does not exist, it will return false.
		//@Return: True -> item is already in the database. False -> item is not in the database
		bool itemExistsInDatabase(std::wstring ao);
		//@dataToEditor()
		//@Param: std::wstring ao
		//@Descriptions: It will first call itemExistsInDatabase(), if it return false, no actions will be performed. If it returns true, it will then
		//			     look for the product within the database, then return all the relevant info along with the product name as a form of vector
		//@Return: std::vector<std::wstring> result
		std::vector<std::wstring> dataToEditor(std::wstring ao);
};

