#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

void toUpper(std::string & str);
char my_toupper(char ch)
{
	return std::toupper(static_cast<unsigned char>(ch));
}

int main()
{

	std::string strTest("test string");
	std::cout << "original str is " << "\"" << strTest << "\"" << std::endl;
	toUpper(strTest);
	std::cout << "after to upper" << "\"" << strTest << "\"" << std::endl;

return 0;
}


void toUpper(std::string & str)
{
	std::transform(str.begin(), str.end(), str.begin(), my_toupper);

}
