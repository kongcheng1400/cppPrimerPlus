#include <iostream>
#include <cstring>
#include "cow.h"

using namespace std;

Cow::Cow()
{
	name[0] = '\0';
	name[20] = '\0';
	hobby = NULL;
	weight = 0.0;

}


Cow::Cow(const char * nm, const char * ho, double wt)
{
	strncpy(name, nm, 19);
	int len = strlen(ho);
	hobby = new char[len];
	strcpy(hobby, ho);
	weight = wt;

}

Cow::Cow(const Cow & c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby)];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	
}

Cow::~Cow()
{
	cout << "\ndelete " << name << endl;
	delete [] hobby;

}

Cow & Cow::operator=(const Cow & c)
{
	if (this == &c)
		return *this;
	delete [] this->hobby;

	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby)];
	strcpy(hobby, c.hobby);

	delete [] c.hobby;
	return *this;
}

void Cow::showcow() const
{
	cout<< "\nName: " << name << " , Hobby is : " << hobby << " , weigth: " << weight
		<< endl;

}
