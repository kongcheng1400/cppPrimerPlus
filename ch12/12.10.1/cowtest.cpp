#include <iostream>
#include "cow.h"


int main()
{
	using namespace std;
	Cow cow1("Jerry Smith", "fishing", 32.3);
	cow1.showcow();
	Cow cow2(cow1);
	cout << "cow2 copies cow1:";
	cow2.showcow();

	Cow cow3;
	cow3 = cow2;
	cout << "cow3 = cow2:";
	cow3.showcow();

	return 0;
}
