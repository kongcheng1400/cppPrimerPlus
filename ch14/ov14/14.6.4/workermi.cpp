#include <iostream>
#include "workermi.h"



Worker::~Worker() {};


void Worker::data() const
{

	std::cout << "Name: " << fullName_m << "\tID: " << id_m; 
}

void Worker::get()
{
	std::getline(std::cin, fullName_m);
	std::cout << "Please input ID:";
	std::cin >> id_m;
	while (std::cin.get() != '\n')
		continue;
}



void Worker::set()
{
	std::cout << "Please input worker's name:";
	get();
}


void Worker::show() const
{
	std::cout << "category: worker:\n";
	data();
	std::cout << std::endl;
}
//waiter methods


void Waiter::get()
{
	std::cout << "Please input panache: ";
	std::cin >> panache_m;
	while (std::cin.get() != '\n')
		continue;

}

void Waiter::set()
{
	std::cout << "Enter waiter's name: ";
	Worker::get();
	get();
}

void Waiter::data() const
{
	std::cout << "\tpanache: " << panache_m;
}

void Waiter::show() const 
{
	std::cout << "Category: waiter\n";
	Worker::data();
	data();
	std::cout << std::endl;

}

//singer methods
const char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};
//protected methods
void Singer::get()
{
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

void Singer::data() const
{

	std::cout << "\tvocal rang: " << pv[voice_m]; 

}


void Singer::show() const
{
	std::cout << "Category: signer\n";
	Worker::data();
	data();
	std::cout << std::endl;
}

void Singer::set()
{
	std::cout << "Please input singer's name:\n";
	Worker::get();
	get();

}


//SingingWaiter methods
void SingingWaiter::data() const
{
	Waiter::data();
	Singer::data();


}



void SingingWaiter::get()
{
	Waiter::get();
	Singer::get();

}

void SingingWaiter::set()
{
	std::cout << "Enter singing waiter's name: ";
	Worker::get();
	get();
}

void SingingWaiter::show() const
{
	std::cout << "category: singing waiter\n";
	Worker::data();
	data();

	std::cout << '\n';
}


