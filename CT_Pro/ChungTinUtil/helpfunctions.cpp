#include "helpfunctions.h"
#include <codecvt>
#include <io.h>
QFont modFontSize(QFont f, int size)
{
    QFont font = f;
    font.setPointSize(size);
    return font;
}


void widgetConfig(QWidget* wq, QLineEdit** input, QLabel** label, QString name, int x, int x1, int y, int y1, int width, int width1, int height, int height1)
{
    QLineEdit* line = *input;
    line->setParent(wq);
    line->setGeometry(x,y,width,height);
    line->show();
    QLabel* l = *label;
    l->setParent(wq);
    l->setGeometry(x1,y1,width1,height1);
    l->setText(name);
    l->setFont(modFontSize(l->font(),12));
    l->show();
}

void widgetConfigForPopUp(QLineEdit** input, QLabel** label, int x, int x1, int y, int y1, int width, int width1, int height, int height1)
{
    QLineEdit* line = *input;
    line->setGeometry(x,y,width,height);
    line->show();
    QLabel* l = *label;
    l->setGeometry(x1,y1,width1,height1);
    l->setFont(modFontSize(l->font(),12));
    l->show();
}

std::string get_desktop_path()
{
    wchar_t* p;
    if (S_OK != SHGetKnownFolderPath( FOLDERID_Desktop, 0, NULL, &p )) return "";
    std::filesystem::path result = p;
    CoTaskMemFree( p );
    return result.string();
}

std::string centerText(const std::string& text, int width) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::u16string u16text = converter.from_bytes(text);

    int textWidth = static_cast<int>(u16text.length());
    int padding = (width - textWidth) / 2;

    std::string centeredText;
    centeredText.reserve(width);

    // Add left padding
    centeredText.append(padding, ' ');

    // Add the text
    centeredText.append(text);

    // Add right padding
    centeredText.append(width - padding - textWidth, ' ');

    return centeredText;
}

std::string getCurrentDate()
{
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm,&now);
    return std::to_string(ltm.tm_mday) + "-" + std::to_string(ltm.tm_mon + 1) + "-" + std::to_string(ltm.tm_year + 1900);
}

libxl::Sheet* insertPicture(libxl::Book** book, std::string pictureFile, int row, int column)
{
    libxl::Book* newBook = *book;

    const std::string pic = pictureFile;
    std::wstring wstr(pictureFile.begin(), pictureFile.end());
    int id = newBook->addPicture(wstr.c_str());

    if (id == -1)
    {
        std::cout << "picture not found" << std::endl;
        return nullptr;
    }
    libxl::Sheet* sheet = newBook->addSheet(L"Sheet1");
    if (sheet)
    {
        sheet->setPicture(row, column, id);
        return sheet;
    }
    return nullptr;
}

bool directoryExists(const char* dirPath)
{
    if (_access(dirPath, 0) == 0)
    {
        return true;
    }
    return false;
}

void wstringToFile(std::wstring str, std::fstream* item)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string utf8String = converter.to_bytes(str);
    item->write(utf8String.c_str(), utf8String.length());
}


