#include <iostream>
#include "ex10.10.6.h"

int main()
{
	Move m1 = Move(3, 4);
	m1.showmove();
	Move m2 = Move(5,6);
	m2.showmove();
	Move m3 = m1.add(m2);
	m3.showmove();
	return 0;
}