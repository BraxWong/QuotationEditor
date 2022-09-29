#include <iostream>
int main()
{
char x[] = "中";
char y[] = u8"中";
wchar_t z = L'中';
char16_t b = u'\u4e2d';
char32_t a = U'\U00004e2d';

std::cout << x << '\n';
std::cout << y << '\n';
std::wcout << z << '\n';
std::cout << a << '\n';
std::cout << b << '\n';    
std::wcout << z << '\n';
}