#include "port.h"

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 20);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	style[19] = '\0';
	bottles = p.bottles;

}


Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;

	delete [] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	style[19] = '\0';
	bottles = p.bottles;
}

Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	if (bottles >= b)
		bottles -= b;
	else 
		bottles = 0;
	return *this;
}


void Port::show() const
{
	cout << "Brand:\t\t " << brand << endl;
	cout << "Kind:\t\t" << style << endl;
	cout << "Bottles:\t" << bottles << endl;
}


ostream & operator<<(ostream & os, const Port & p)
{
	cout << p.brand << ", " << p.style << ", " << p.bottles << endl;

}


//VintagePort methods
VintagePort::VintagePort()
	:Port()
{
	nickname = new char[strlen("none") + 1];
	strcpy(nickname, "none");
	year = 1900;
}

VintagePort::VintagePort(const char * br, const char * st, int b, const char *nn, int y)
	:Port(br, st, b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
	:Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;

}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == & vp)
		return *this;	
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;

}

void VintagePort::show() const
{
	Port::show();
	cout << "NickName:\t\t" << nickname << endl;
	cout << "Year:\t\t"		<< year << endl;

}

ostream & operator<<(ostream & os, const VintagePort & vp) 
{
	os << (const Port &) vp;
	os << vp.nickname << " ," << vp.year << endl;
	return os;
}









