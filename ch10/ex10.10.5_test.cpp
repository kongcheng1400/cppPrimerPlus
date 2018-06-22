#include <iostream>
#include "ex10.10.5.h"

int main()
{
	Customer c1 = {"Harry He", 98.69};
	Customer c2 = {"Harry He", 35.47};
	Customer c3 = {"Pielin Cai", 402.3};
	
	Stack st1;
	st1.push(c1);
	st1.push(c2);
	st1.push(c3);
	Customer c;
	st1.pop(c);
	st1.pop(c);
	st1.pop(c);
	st1.pop(c);
	
	return 0;
}