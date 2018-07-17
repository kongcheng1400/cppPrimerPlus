#include <iostream>
using namespace std;

#include "classic.h"

void bravo(const CD & disk);

int main()
{
	CD c1("Beatles", "Captol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
						 "Alfred Brendel", "Philips", 2, 57.17);

	CD *pcd = & c1;
	c1.report();
	c2.report();

	cout << "using base pointer to objects:\n";
	pcd->report();
	pcd = & c2;
	pcd->report();

	cout << "calling a fucntion with a base reference:\n";
	bravo(c1);
	bravo(c2);

	cout << "Tesintg assignment:";
	Classic copy;
	copy = c2;
	copy.report();


	return 0;



}

void bravo(const CD & disk)
{
	disk.report();

}
