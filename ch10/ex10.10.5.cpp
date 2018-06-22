#include <iostream>
#include "ex10.10.5.h"

bool Stack::pop(Customer & cus)
{
	if (isempty()) {
		std::cout <<"\nStack Empty!\n";
		return false;
	}
	else {
		cus = content[--cnt];
		total += cus.payment;
		std::cout << "\npop customer: " << cus.fullname << ", val:" 
				  << cus.payment << std::endl;
		std::cout << "\nTotal pay:" << total << std::endl;
		return true;
	}
}
bool Stack::push(const Customer & cus)
{
	if (isfull())
		return false;
	else {
		content[cnt++] = cus;
		return true;
	}
}