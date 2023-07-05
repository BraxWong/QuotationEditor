#include <direct.h>
#include <string>
#include <locale>
#include "Database.h"
#include "helpfunctions.h"
#include <codecvt>
#include <vector>
#include <sstream>
#include <string>

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
	HELPFUNCTIONS_H::wstringToFile(ao, &file);
	file << " " << pDimensionsX << " " << pDimensionsY << " " << pDimensionsZ << " ";
	HELPFUNCTIONS_H::wstringToFile(approveNum, &file);
	file << " " << price << " " << MH << "\n";
	file.close();
}

bool Database::itemExistsInDatabase(std::wstring ao)
{
	std::ifstream file;
	file.open(HELPFUNCTIONS_H::get_desktop_path() + "/" + "Database/Database.txt");
	std::string firstword;
	std::vector<std::string> wv;

	while (getline(file, firstword)) {
		std::string lastWord;
		std::stringstream ss(firstword);
		while (ss >> lastWord)
		{
			wv.push_back(lastWord);
		}
	}

	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
	std::string converted_str = converter.to_bytes(ao);

	for (int i = 0; i < wv.size(); ++i)
	{
		if (wv[i] == converted_str)
		{
			return true;
		}
	}
	return false;
}

std::vector<std::wstring> Database::dataToEditor(std::wstring ao)
{
	std::ifstream file;
	file.open(HELPFUNCTIONS_H::get_desktop_path() + "/" + "Database/Database.txt");
	std::string firstword;
	std::vector<std::string> wv;
	std::vector<std::wstring> result;
	while (getline(file, firstword)) {
		std::string lastWord;
		std::stringstream ss(firstword);
		while (ss >> lastWord)
		{
			wv.push_back(lastWord);
		}
	}

	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;
	std::string converted_str = converter.to_bytes(ao);

	for (int i = 0; i < wv.size(); ++i)
	{
		if (wv[i] == converted_str)
		{
			
			std::wstring str(wv[i].begin(), wv[i].end());
			std::wstring str2(wv[i + 1].begin(), wv[i + 1].end());
			std::wstring str3(wv[i + 2].begin(), wv[i + 2].end());
			std::wstring str4(wv[i + 3].begin(), wv[i + 3].end());
			std::wstring str5(wv[i + 4].begin(), wv[i + 4].end());
			std::wstring str6(wv[i + 5].begin(), wv[i + 5].end());
			std::wstring str7(wv[i + 6].begin(), wv[i + 6].end());
			std::wstring str8(wv[i + 7].begin(), wv[i + 7].end());
			std::wstring str9(wv[i + 8].begin(), wv[i + 8].end());
			result.push_back(str);
			result.push_back(str2);
			result.push_back(str3);
			result.push_back(str4);
			result.push_back(str5);
			result.push_back(str6);
			result.push_back(str7);
			result.push_back(str8);
			result.push_back(str9);
		}
	}
	return result;
}
