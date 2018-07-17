#include <iostream>
#include "classic.h"
#include <cstring>

using namespace std;

CD::CD(const char * s1, const char * s2, int n, double x)
{
	performers_m = new char[strlen(s1) + 1];
	strcpy(performers_m, s1);

	label_m = new char[strlen(s2) + 1];
	strcpy(label_m, s2);

	selections_m = n;
	playtime_m = x;

}

CD::CD(const CD & d)
{
	performers_m = new char[strlen(d.performers_m) + 1];
	std::strcpy(performers_m, d.performers_m);

	label_m = new char[strlen(d.label_m) + 1];
	std::strcpy(label_m, d.label_m);

	selections_m = d.selections_m;
	playtime_m = d.playtime_m;

}

CD::CD()
{
	performers_m = new char[strlen("none") + 1];
	strcpy(performers_m, "none");

	label_m = new char[strlen("none") + 1];
	strcpy(label_m, "none");

	selections_m = 0;
	playtime_m = 0;

}

CD::~CD()
{
	delete [] performers_m;
	delete [] label_m;
}

void CD::report() const
{
	cout << "Performers: " << performers_m << " ,Label: " << label_m << endl;
	cout << "selections: " << selections_m << " ,playtime: " << playtime_m << endl;

}

CD & CD::operator=(const CD & d)
{
	if (this == & d)
		return *this;
	delete [] performers_m;
	delete [] label_m;
	performers_m = new char[strlen(d.performers_m)+1];
	label_m = new char[strlen(d.label_m) + 1];
	std::strcpy(performers_m, d.performers_m);
	std::strcpy(label_m, d.label_m);
	selections_m = d.selections_m;
	playtime_m = d.playtime_m;
	return *this;
}

Classic::Classic(const char * kw,const char * s1, const char * s2, int n ,double x)
	:CD(s1, s2, n, x)
{
	keywords_m = new char[strlen(kw)+1];
	strcpy(keywords_m, kw);
}

Classic::Classic(const Classic & cl) 
	:CD(cl)
{
	keywords_m = new char[strlen(cl.keywords_m)+1];
	strcpy(keywords_m, cl.keywords_m);
}

Classic::Classic()
	:CD()
{
	keywords_m = new char[strlen("none") + 1];
	strcpy(keywords_m, "none");
}

Classic::~Classic()
{
	delete [] keywords_m;

}

void Classic::report() const
{
	CD::report();
	cout << "keywords:" << keywords_m << endl;

}

Classic & Classic::operator=(const Classic & cl)
{
	if (this == &cl)
		return *this;
	CD::operator=(cl);
	delete [] keywords_m;
	keywords_m = new char[strlen(cl.keywords_m) + 1];
	strcpy(keywords_m, cl.keywords_m);

	return *this;

}




