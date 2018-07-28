#include <iostream>
using std::cout;
#include "stringbad.h"

void callme1(StringBad &);
void callme2(StringBad);


int main()
{
	using std::endl;
	{
	
		cout << "Starting an inner block.\n";
		StringBad headline1("HEADLINE1");
		StringBad cpTest;
	    cpTest = headline1;
	}



	return 0;
}


void callme1(StringBad & rsb)
{
	cout << "\nString passed by reference:\n";
	cout << "   \"" << rsb << " \"\n";

}

void callme2(StringBad sb)
{
	cout << "\nString passed value:\n";
	cout << "     \"" << sb << "\"\n";

}
