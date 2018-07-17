#include <cstring>
#include <cctype>
#include "string1.h"
using std::cin;
using std::cout;

int String:: num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

//class methods
String::String(const char * s)
{

	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_strings++;
	std::cout << "\nconstructed with char * " << str << std::endl;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
	std::cout << "\nconstructed with  default " << std::endl;
}

String::String(const String & st)
{
	num_strings++;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str); 
	std::cout << "\nconstructed with  copy:" << str << std::endl;
}

String::~String()
{
	--num_strings;
	std::cout << "\ndestructed " << str;
	std::cout << " ; Object number is " << num_strings << std::endl;
	delete [] str;
}

String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;

	delete [] str;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
	std::cout << "\nconstucted by = object" << std::endl;
	return *this;
}

String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char [len + 1];
	std::strcpy(str, s);
	return *this;




}

char & String::operator[](int i)
{
	return str[i];

}

const char & String::operator[](int i) const
{
	return str[i];
}

String  String::operator+(const String & st) const
{
	String result;
	result.len = len + st.len;
	result.str = new char [result.len+1];
	std::strcpy(result.str, str);
	std::strcpy(result.str + length(), st.str);

	return result;

}

void String::stringlow() 
{
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (isupper(ch))
			str[i] = tolower(ch);	
	}

}

void String::stringup()
{
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (islower(ch))
			str[i] = toupper(ch);
	}

}

int String::has(const char c)
{
	int res = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == c)
			res++;
	return res;

}


String  operator+(const char * str1, const String & st)
{
	String result;
	result.len = std::strlen(str1) + st.len;
	result.str = new char [result.len + 1];
	std::strcpy(result.str, str1);
	std::strcpy(result.str + std::strlen(str1), st.str);
	return result;

}


bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);

}

ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;

}





