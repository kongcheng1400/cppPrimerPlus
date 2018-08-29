#include <iostream>
#include <iomanip>


int main()
{
	char name[20];
	float hourlyWage;
	float workingHour;

	std::cout << "Enter your name: ";
	std::cin.getline(name, 20);

	std::cout << "Enter your hourly wages: ";
	std::cin >> hourlyWage;

	std::cout << "Enter your number of hours worked: ";
	std::cin >> workingHour;

	std::cout << "First format: \n";
	std::cout << std::right << std::setw(20) << name << ": "
			  << "$" << std::setw(10) << hourlyWage << ": "
			  << std::setw(5) << workingHour
			  << std::endl;

	std::cout << "Second format: \n";
	std::cout << std::left << std::setw(20) << name << ": "
			  << "$" << std::setw(10) << hourlyWage << ": "
		      << std::setw(5) << workingHour
			  << std::endl;	  

	return 0;
}
