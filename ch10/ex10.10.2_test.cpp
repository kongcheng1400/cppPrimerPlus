#include <iostream>
#include "ex10.10.2.h"

int main()
{
	Person one;
	Person two("Smythecrash");
	Person three("Dimwiddy", "Sam");
	one.show();
	std::cout << std::endl;
	one.formalshow();
	three.show();
	std::cout << std::endl;
	three.formalshow();	
	return 0;
}