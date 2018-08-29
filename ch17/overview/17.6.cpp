#include <iostream>
#include <iomanip>
int main()
{
	int a;
	std::cout << "Please input a integer: ";
	std::cin >> a;

	std::cout << "hex: " << std::hex << a << ", Dec: " << std::dec << a << ", oct: " << std::oct << a << std::endl;

	std::cout << std::setw(15) << std::showbase << std::hex << a
			  << std::setw(15) << std::dec << a
			  << std::setw(15) << std::oct << a
			  << std::endl;

	return 0;
}
