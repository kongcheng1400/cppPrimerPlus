#include <iostream>
#include <cstring>
#include "stock.h"



Stock::Stock(const char * nm, int mnt, double pri)
{
	name = new char[std::strlen(nm) + 1];
	strcpy(name, nm);
	amount = mnt;
	price = pri;
	totalvalue = amount * price;
	
}


Stock::~Stock()
{

	delete [] name;
}



Stock::Stock()
{
	name = new char[1];
	name[0] = '\0';
	amount = 0;
	price = 0;
	totalvalue = 0;

}

Stock::Stock(const Stock & st)
{
	name = new char[strlen(st.name) + 1];
	strcpy(name, st.name);
	amount = st.amount;
	price =st.price;
	totalvalue = st.totalvalue;


}


void Stock::show() const
{
	std::cout << "name: " << name << ",value: " << totalvalue << std::endl;

}

const Stock & Stock::topval(const Stock & ps) const
{
	if(totalvalue > ps.totalvalue)
		return *this;
	else
		return ps;

}
