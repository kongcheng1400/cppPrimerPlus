#include <iostream>
#include "ex10.10.6.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	std::cout << "( " << x << " , " << y << " )" << std::endl;
}

Move Move::add(const Move & m) const
{
	Move result;
	result.x = x + m.x;
	result.y = y + m.y;
	return result;
}
