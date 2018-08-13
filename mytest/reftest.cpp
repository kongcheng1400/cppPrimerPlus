#include <iostream>


int main()
{
	int i1 {3};
	int i2 {4};
	int && ri = i1 + i2;
	std::cout << "rvalue reference ri is " << ri << std::endl;
	return 0;
}
