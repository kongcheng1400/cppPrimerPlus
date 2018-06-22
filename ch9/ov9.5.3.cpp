#include <iostream>
int main()
{
	double x;
	std::cout << "Enter value: ";
	while (!(std::cin >> x))
	{
		std::cout << "Bad input, please enter a number: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cout << "value = " << x << std::endl;
	return 0;
}