#include "port.h"


int main()
{
	cout << "base class test:\n\n";
	Port p1("Greatwall", "RedWine", 32);
	Port p2(p1);
	Port p3;
	p3 = p2;
	p2 += 32;
	p3 -= 16;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	

	cout << "\n\nderived class test:\n";
	VintagePort p4;
	cout << "\n\ndefault p4:\n" << p4 << endl;
	VintagePort p5("GreatwallVP", "RedWine", 32, "IronMan", 1998);
	cout << "VP P5" << p5 << endl;
	p5 += 32;
	cout << "VP P5 + 32 "  << p5 << endl;
	p4 = p5;
	cout << "VP p4 = p5 " << p4 << endl;

	Port *pp = & p1;
	pp->show();
	
	Port *pv = & p5;
	pv->show();

	return 0;
}
