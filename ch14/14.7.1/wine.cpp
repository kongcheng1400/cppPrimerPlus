#include <iostream>
#include "wine.h"

using std::cin;
using std::cout;
using std::endl;


Wine::Wine(const char * br, int yrs, int y[], int b[])
	: brand(br), numOfYears(yrs), inventory(ArrayInt(y, yrs), ArrayInt(b, yrs))
{}

Wine::Wine(const char * br, int yrs)
	: brand(br), numOfYears(yrs), inventory(ArrayInt(yrs), ArrayInt(yrs))
{}

void Wine::getBottles()
{
	int i = 0;
	int year, bottles;
	for (i = 0; i < numOfYears; i++)
	{
		cout << "Please enter the year and bottle split by space:";
		cin >> year >> bottles;
		inventory.first[i] = year;
		inventory.second[i] = bottles;
	
	}
}


void Wine::show() const
{
	cout << brand << "\n";
	for (int i = 0; i < numOfYears; i++)
	{
		cout << "\t" << inventory.first[i]<< "\t" << inventory.second[i];
		cout << endl;
	}
}


int Wine::sum() const
{
	cout << "total bottles for " << brand << " is " << inventory.second.sum() << ".\n";
	return inventory.second.sum();

}

