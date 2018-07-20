#include <iostream>
#include "wine_dc.h"
using std::cout;
using std::endl;
using std::cin;


Wine::Wine(const char * br, int yrs, int y[], int b[])
	: string(br), years(yrs),PairArray(ArrayInt(y, yrs), ArrayInt(b,yrs)) 
{}

Wine::Wine(const char * br, int yrs)
	: string(br), years(yrs),PairArray(ArrayInt(yrs), ArrayInt(yrs)) 
{}

void Wine::getBottles()
{
	int y, b;
	int i = 0;
	for (i = 0; i < years; i++)
	{
		cout << "Please input years and bottles pair(eg: 2011 192): ";
		cin >> y >> b;
		dynamic_cast<PairArray *>((Wine *)this)->first[i] = y;
		(dynamic_cast<PairArray *>((Wine *)this))->second[i] = b;
	}
}

void Wine::show() const
{
	cout << "Wine: " << (string)*this << endl;
	cout << "\tyears" << "\tbottles" << endl;
	for (int i = 0; i < years; i++) {
		cout << "\t";
		cout << ((PairArray)*this).first[i] << "\t"
			<< ((PairArray)*this).second[i] << "\n";
	}
}


const string & Wine::label() const
{
	return (const string &)*this;
}



int Wine::sum() const
{
	return ((PairArray)*this).second.sum();
}
