#include <iostream>
#include "stonewt.h"

int main()
{
	Stonewt st1(12.35);
	Stonewt st2(15, 33.28);
	std::cout << "st1: " << st1 << std::endl;
	std::cout << "st2: " << st2 << std::endl;
	std::cout << "st1 + st2 "  << (st1 + st2) << std::endl;
	std::cout << "st1 * 3.5 "  << st1 * 3.5 << std::endl;
	std::cout << "3.5 * st1 " << 3.5 * st1 << std::endl;

	return 0;
}
