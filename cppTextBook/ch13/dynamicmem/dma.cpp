#include <iostream>
#include <cstring>
#include "dma.h"

using namespace std;

//base methods
BaseDMA::BaseDMA(const char * l, int r)
{
	label_m = new char[strlen(l) + 1];
	std::strcpy(label_m, l);
	rating_m = r;
}

BaseDMA::BaseDMA(const BaseDMA & rs)
{
	label_m = new char[strlen(rs.label_m) + 1];
	std::strcpy(label_m, rs.label_m);
	rating_m = rs.rating_m;
}


BaseDMA::~BaseDMA()
{
	delete [] label_m;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs)
{
	if (this == &rs)
		return *this;
	delete [] label_m;
	label_m = new char[strlen(rs.label_m) + 1];
	strcpy(label_m, rs.label_m);
	rating_m = rs.rating_m;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs)
{
	os<< "label:" << rs.label_m << " , rating: " << rs.rating_m << endl;
	return os;

}

//LacksDMA methods:
LacksDMA::LacksDMA(const char * c, const char * l, int r) : BaseDMA(l, r)
{
	strncpy(color_m, c, LacksDMA::COL_LEN-1);
	color_m[LacksDMA::COL_LEN -1] = '\0';
}

LacksDMA::LacksDMA(const char * c, const BaseDMA & rs) : BaseDMA(rs)
{

	strncpy(color_m, c, LacksDMA::COL_LEN-1);
	color_m[LacksDMA::COL_LEN -1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & rs)
{
	os << "color:" << rs.color_m;
	//BaseDMA::<<(os, rs);
	os << (const BaseDMA &) rs;
	return os;
}

//has DMA
HasDMA::HasDMA(const char * s, const char * l, int r):BaseDMA(l, r)
{
	style_m = new char[strlen(s) + 1];
	strcpy(style_m, s);
} 

HasDMA::HasDMA(const char * s, const BaseDMA & rs) : BaseDMA(rs)
{
	style_m = new char[strlen(s) + 1];
	strcpy(style_m, s);
}

HasDMA::~HasDMA()
{
	//auto call it's base' desctructor, so don't need to call ~BaseDMA()
	//~BaseDMA();
	delete [] style_m;
}

void HasDMA::operator=(const HasDMA & rs)
{
	//if (this == & rs)
	//	return *this;
	//BaseDMA::=(rs);
	//it's member function so can use::
	BaseDMA::operator=(rs);
	delete [] style_m;
	style_m = new char[strlen(rs.style_m) + 1];
	strcpy(style_m, rs.style_m);
	//return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & rs)
{
	os << "style: " << rs.style_m;
	//BaseDMA::<<(os, rs);
	//can't use BaseDMA:: because this is friend!
	os << (const BaseDMA &) rs;
	return os;

}




