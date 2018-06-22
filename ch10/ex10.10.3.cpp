#include <iostream>
#include "ex10.10.3.h"

using namespace std;

Golf::Golf()
{
	cout << "\nPlease input the name:";
	std::getline(cin, fullname_m);
	
	cout << "Please input the hc level:";
	while (! (cin >> handicap_m)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Illegal input, please input again:";
	}
}
	
Golf::Golf(const std::string & str, const int hc)
{
	fullname_m = str;
	handicap_m = hc;
}

void Golf::changehandicap(int hc)
{
	handicap_m = hc;
}

void Golf::showgolf() const
{
	cout << endl;
	cout << "Golf " << fullname_m << "'s hc = " << handicap_m << endl;	
}