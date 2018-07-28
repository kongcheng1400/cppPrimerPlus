#include <iostream>
#include "worker0.h"



Worker::~Worker() {};

void Worker::set()
{
	std::cout << "Please input worker's name:";
	std::getline(std::cin, fullName_m);
	std::cout << "Please input ID:";
	std::cin >> id_m;
	while (std::cin.get() != '\n')
		continue;
}


void Worker::show() const
{
	std::cout << "Name: " << fullName_m << "\tID: " << id_m; 
}


void Waiter::set()
{
	Worker::set();
	std::cout << "Please input panache: ";
	std::cin >> panache_m;
	while (std::cin.get() != '\n')
		continue;

}

void Waiter::show() const 
{
	std::cout << "Category: waiter\n";
	Worker::show();
	std::cout << "\tpanache: " << panache_m;
	std::cout << std::endl;

}


//singer methods
const char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set()
{
	Worker::set();
	std::cout << "Enter number for singer's vocal range:\n";
	int i;

	for (i = 0; i < Vtypes; i++)
	{
		std::cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			std::cout << std::endl;
	}
	if (i % 4 == 3)
		std::cout << std::endl;
	
	while (std::cin >> voice_m && (voice_m < 0 || voice_m >= Vtypes))
		std::cout << "Please enter a value >=0 < " << Vtypes << std::endl;

	while (std::cin.get() != '\n')
		continue;
}


void Singer::show() const
{
	std::cout << "Category: signer\n";
	Worker::show();
	std::cout << "vocal rang: " << pv[voice_m] << std::endl;
}
