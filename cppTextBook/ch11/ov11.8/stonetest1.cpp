#include <iostream>
#include "stonewt.h"

using namespace std;

int main()
{
	Stonewt st1;
	Stonewt st2(148.3);
	Stonewt st3(10, 5.0);
	cout << "st1:" << st1 << endl;
	cout << "st2:" << st2 << endl;
	cout << "st3:" << st3 << endl;
	cout << "st2 * 2: " << st2 * 2 << endl;
	cout << "2 * st2: " << 2 * st2 << endl;
	

	return 0;
}
