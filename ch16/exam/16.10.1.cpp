#include <iostream>
#include <iterator>
#include <string>


int main()
{	
	std::cout << "Palindrome Test, please input a word, quit for quit" << std::endl;
	std::string uut;
	std::getline(std::cin, uut);
	while (uut != "quit")
	{
		std::string reversedUUT(uut.rbegin(), uut.rend());
		if (uut == reversedUUT)
			std::cout << "yes, it's a Palindrome." << std::endl;
		else
			std::cout << "No, it's not a Palindrome." << std::endl;

		std::cout << "input a new word for test:";
		std::getline(std::cin, uut);
	
	}

	std::cout << "Bye\n";
	return 0;


}
