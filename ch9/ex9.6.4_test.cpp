#include <iostream>
#include "ex9.6.4.h"

using namespace SALES;
using namespace std;

int main()
{
	int arsize = 4;
	Sales s1, s2;
	double ar[4] = {3000033.22, 4000055.11, 1000033.44, 50004.3};
	setSales(s1, ar, arsize);
	showSales(s1);
	setSales(s2);
	showSales(s2);
	return 0;
}