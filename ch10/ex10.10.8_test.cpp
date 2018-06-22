#include <iostream>
#include "ex10.10.8.h"

int main()
{
	Item i1=3.0;
	Item i2=4.0;
	Item i3=5.0;
	List L1;
	L1.add(i1);
	L1.add(i2);
	L1.add(i3);
	L1.visit(showitem);
	L1.visit(changeitem);
	L1.visit(showitem);
	
	return 0;
}