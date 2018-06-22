#include <iostream>
#include <string>
#include <cstring>
#include "ex9.1_golf.h"

using namespace std;

void setgolf(golf & g, const char * name, int hc)
{
	strncpy(g.fullname, name, Len);
	g.handicap = hc;
}

int setgolf(golf &g) 
{
	cout << "\nPlease input the name:";
	cin.getline(g.fullname, Len);

	if (!cin) {
		cout << "\nillegal input.!\n";
		cin.clear();
		while (cin.get() != '\n')
			continue;
		return 0;
	}
	
	cout << "Please input the hc level:";
	cin >> g.handicap;
	while (cin.get() != '\n')
		continue;
	
	if (!cin) {
		cout << "\nillegal input.!\n";
		cin.clear();
		while (cin.get() != '\n')
			continue;
		return 0;
	}
	

	return 1;
}

void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << endl;
	cout << "Golf " << g.fullname << "'s hc = " << g.handicap << endl;
}