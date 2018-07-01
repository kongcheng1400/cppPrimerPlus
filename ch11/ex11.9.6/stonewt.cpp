#include <iostream>
#include "stonewt.h"


Stonewt::Stonewt() 
{
	st_m = 0;
	pnd_m = 0;
	pnd_left_m = 0;
	fmt_m = PND;
}

Stonewt::Stonewt(double pnd, format fmt)
{
	pnd_m = pnd;
	fmt_m = PND;
	pndToSt();

}   

Stonewt::Stonewt(int st, double pnd_left, format fmt)
{
	st_m = st;
	pnd_left_m = pnd_left;
	fmt_m = fmt;
	stToPnd();
}

Stonewt Stonewt::operator+(const Stonewt & st) const
{
	return Stonewt(pnd_m + st.pnd_m);
}

Stonewt Stonewt::operator-(const Stonewt & st) const
{
	Stonewt result;
	if (pnd_m >= st.pnd_m)
		result.pnd_m = pnd_m - st.pnd_m;
	result.pndToSt();

	return result;
}

Stonewt Stonewt::operator*(const double n) const
{
	return Stonewt(pnd_m * n);
}

Stonewt operator*(const double n, const Stonewt st)
{
	return Stonewt(st.pnd_m * n);
}

bool Stonewt::operator>(const Stonewt & st) const
{
	return (pnd_m > st.pnd_m);
}

bool Stonewt::operator<(const Stonewt & st) const
{
	return (pnd_m < st.pnd_m);
}

bool Stonewt::operator==(const Stonewt & st) const
{
	return (pnd_m == st.pnd_m);
}

std::ostream & operator<<(std::ostream & os, const Stonewt st)
{
	if (st.fmt_m == Stonewt::PND)
		os << st.pnd_m << "pounds.\n";
	else
		os << st.st_m << "stones and " << st.pnd_left_m << " pounds.\n";
	
	return os;

}








    
