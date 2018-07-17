#include <iostream>
#include <cstring>
#include "dma.h"

using namespace std;

//Abstract class ABC:

ABC::ABC(const char * n, int r )
{
	label_m = new char[strlen(n)+1];
	strcpy(label_m, n);
	rating_m = r;
}

ABC::ABC(const ABC & abcObj)
{
	label_m = new char[strlen(abcObj.label_m) + 1];
	strcpy(label_m, abcObj.label_m);
	rating_m = abcObj.rating_m;
}	

ABC::~ABC()
{
	delete [] label_m;
}

ABC & ABC::operator=(const ABC & obj)
{
	if(this == &obj)
		return *this;
	delete [] label_m;
	label_m = new char[strlen(obj.label_m) + 1];
	strcpy(label_m, obj.label_m);
	rating_m = obj.rating_m;
}

std::ostream & operator<<(std::ostream & os, const ABC & obj)
{
	os << "ABC Label:" << obj.label_m << " Rating: " << obj.rating_m;
	return os;

}



//base methods
BaseDMA::BaseDMA(const char * b, const char * l, int r)
	:ABC(l, r)
{
	basic_m = new char[strlen(b) + 1];
	std::strcpy(basic_m, b);
}

BaseDMA::BaseDMA(const char * s, const ABC & rs)
	:ABC(rs)
{
	basic_m = new char[strlen(s) + 1];
	std::strcpy(basic_m, s);
}


BaseDMA::~BaseDMA()
{
	delete [] basic_m;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs)
{
	if (this == &rs)
		return *this;
	delete [] basic_m;

	ABC::operator=(rs);
	basic_m = new char[strlen(rs.basic_m) + 1];
	strcpy(basic_m, rs.basic_m);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs)
{
	os << (const ABC &) rs;
	cout << " Basic: "  << rs.basic_m << endl;
	
	return os;

}

void BaseDMA::view()
{
	std::cout << "BaseDMA View:\t\t" ;
	std::cout << *this << std::endl;

}

//LacksDMA methods:
LacksDMA::LacksDMA(const char * c, const char * l, int r) : ABC(l, r)
{
	strncpy(color_m, c, LacksDMA::COL_LEN-1);
	color_m[LacksDMA::COL_LEN -1] = '\0';
}

LacksDMA::LacksDMA(const char * c, const ABC & rs) : ABC(rs)
{

	strncpy(color_m, c, LacksDMA::COL_LEN-1);
	color_m[LacksDMA::COL_LEN -1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & rs)
{
	os << "LackDMA color:" << rs.color_m;
	//BaseDMA::<<(os, rs);
	os << (const ABC &) rs;
	return os;
}

void LacksDMA::view()
{
	std::cout << "\ncall lacksDMA view\t" ;
	std::cout << *this << std::endl;
}

//has DMA
HasDMA::HasDMA(const char * s, const char * l, int r):ABC(l, r)
{
	style_m = new char[strlen(s) + 1];
	strcpy(style_m, s);
} 

HasDMA::HasDMA(const char * s, const ABC & rs) : ABC(rs)
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

HasDMA &  HasDMA::operator=(const HasDMA & rs)
{
	if (this == & rs)
		return *this;
	//BaseDMA::=(rs);
	//it's member function so can use::
	ABC::operator=(rs);
	delete [] style_m;
	style_m = new char[strlen(rs.style_m) + 1];
	strcpy(style_m, rs.style_m);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & rs)
{
	os << "HasDMA style: " << rs.style_m;
	//BaseDMA::<<(os, rs);
	//can't use BaseDMA:: because this is friend!
	os << (const ABC &) rs;
	return os;

}

void HasDMA::view()
{
	cout << "\ncall HasDMA view:\t";
	cout << *this << endl;
}


