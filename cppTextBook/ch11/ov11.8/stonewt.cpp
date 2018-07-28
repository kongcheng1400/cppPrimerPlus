#include <iostream>
#include "stonewt.h"

using std::cout;
using std::ostream;

Stonewt::Stonewt(double lbs)
{
	stone = int (lbs) / Lbs_per_stn;
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{}

void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

Stonewt::operator int() const
{
	return int (pounds + 0.5);
}

Stonewt::operator double() const
{
	return pounds;
}


Stonewt Stonewt::operator*(double mul)
{
	return Stonewt(pounds * mul);
}


Stonewt operator*(double mul, Stonewt & st)
{
	Stonewt result;
	double totalPds = mul * st.pounds;
	result.stone = totalPds / Stonewt::Lbs_per_stn;
	result.pds_left = (int)totalPds % (int)Stonewt::Lbs_per_stn + totalPds - int (totalPds);
	result.pounds = totalPds;
	return result; 
}

ostream & operator<<(ostream & os, const Stonewt & st) 
{
	os << st.stone << " stones, " << st.pds_left << " pds = " << st.pounds << "pounds.\n";
	return os;
}
