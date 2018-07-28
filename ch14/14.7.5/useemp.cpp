#include <iostream>
using namespace std;
#include "emp.h"


int main(void)
{
	Employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.showAll();

	Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.showAll();

	Fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.showAll();

	HighFink hf(ma, "Curly Kw");
	hf.showAll();
	cout << "Press a key for next phase:\n";
	HighFink hf2;
	hf2.setAll();

	cout << "Using an Abstr_emp * pointer :\n";
	Abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
		tri[i]->showAll();



	return 0;





}
