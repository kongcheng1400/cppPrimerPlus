#include <iostream>
#include "ex10.10.4.h"

int main()
{
	int arsize = 4;
	double ar[4] = {3000033.22, 4000055.11, 1000033.44, 50004.3};
	Sales s1 = Sales(ar, arsize);
	s1.showSales();
	Sales s2;
	s2.showSales();
	return 0;
}