#include <direct.h>
#include <string>
#include <locale>
#include "Database.h"
#include "helpfunctions.h"
#include <codecvt>

void Database::databaseEntry(std::wstring ao, std::wstring pName, std::wstring modelName, std::string pDimensionsX, std::string pDimensionsY, std::string pDimensionsZ, std::wstring approveNum, int quant, int price, float MH)
{
	if (itemExistsInDatabase(pName))
	{
		return;
	}
	std::string filePath = HELPFUNCTIONS_H::get_desktop_path() + "/" + "Database";
	
	if (!HELPFUNCTIONS_H::directoryExists(filePath.c_str()))
	{
		if (_mkdir(filePath.c_str()) != 0)
		{
			return;
		}
	}
	std::fstream file;
	file.open(filePath + "/" + "Database.txt", std::ios::app | std::ios::binary);
	HELPFUNCTIONS_H::wstringToFile(pName, &file);
	file << " ";
	HELPFUNCTIONS_H::wstringToFile(modelName, &file);
	file << " ";
	file << pDimensionsX << " " << pDimensionsY << " " << pDimensionsZ << " ";
	HELPFUNCTIONS_H::wstringToFile(approveNum, &file);
	file << " " << price << " " << MH << "\n";
	file.close();
}

bool Database::itemExistsInDatabase(std::wstring ao)
{
	return false;
}
