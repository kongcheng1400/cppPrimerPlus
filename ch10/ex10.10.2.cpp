#include <iostream>
#include <cstring>
#include "ex10.10.2.h"


Person::Person(const std::string & ln, const char * fn)
{
	lname_m = ln;
	strcpy(fname_m, fn);
}
	
void Person::show() const
{
	std::cout << "\n" << fname_m << "." << lname_m;
}

void Person::formalshow() const
{
	std::cout << "\n" << lname_m << "." << fname_m;
}