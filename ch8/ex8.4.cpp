#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct stringy{
	char * str;
	int ct;
};

//prototypes
void set(stringy & stry, const char * org_str);
void show(const stringy & stry, int times = 1);
void show(const char * str, int times = 1); 
void free(stringy & stry);



int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	
	set(beany, testing);
	
	show(beany);
	show(beany, 2);
	
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	free(beany);
	
	return 0;
}

void set(stringy & stry, const char * org_str)
{
	stry.ct = strlen(org_str);
	stry.str = new char [stry.ct + 1];
	strcpy(stry.str, org_str);
}

void free(stringy & stry)
{
	if (stry.str)
		delete [] stry.str;
}

void show(const stringy & stry, int times)
{
	cout << "show " << times << " times!\n";
	for (int i = 0; i < times; i++)
	{
		cout << stry.str << endl;
	}
}

void show(const char * str, int times)
{
	cout << "show " << times << " times!\n";
	for (int i = 0; i < times; i++)
	{
		cout << str << endl;
	}
}
