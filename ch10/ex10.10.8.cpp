#include <iostream>
#include "ex10.10.8.h"

bool List::add(const Item & it)
{
	if(isfull())
		return false;
	else 
		arr[cnt++] = it;
	
	return true;
}
void List::visit(void (*pf) (Item & it))
{
	std::cout << "\n\nVisit Items:\n" << std::endl;
	for (int i = 0; i < cnt ; i++ )
	{
		pf(arr[i]);
	}
}

void showitem(Item & it)
{
	std::cout << it << std::endl;
}

void changeitem(Item & it)
{
	it *= 2;
}