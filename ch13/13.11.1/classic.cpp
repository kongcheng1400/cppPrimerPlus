#include <iostream>
#include "classic.h"
#include <cstring>

using namespace std;

CD::CD(const char * s1, const char * s2, int n, double x)
{
	std::strncpy(performers_m, s1, 49);
	performers_m[49] = '\0';
	std::strncpy(label_m, s2, 19);
	label_m[19] = '\0';
	selections_m = n;
	playtime_m = x;

}

CD::CD(const CD & d)
{
	std::strcpy(performers_m, d.performers_m);
	std::strcpy(label_m, d.label_m);
	selections_m = d.selections_m;
	playtime_m = d.playtime_m;

}

CD::CD()
{
	strcpy(performers_m, "none");
	strcpy(label_m, "none");
	selections_m = 0;
	playtime_m = 0;

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
	std::strcpy(performers_m, d.performers_m);
	std::strcpy(label_m, d.label_m);
	selections_m = d.selections_m;
	playtime_m = d.playtime_m;
	return *this;
}

Classic::Classic(const char * kw,const char * s1, const char * s2, int n ,double x)
	:CD(s1, s2, n, x)
{
	std::strncpy(keywords_m, kw, 29);
	keywords_m[29] = '\0';

}

Classic::Classic(const Classic & cl) 
	:CD(cl)
{
	std::strcpy(keywords_m, cl.keywords_m);

}

Classic::Classic()
	:CD()
{

	strcpy(keywords_m, "none");
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
	strcpy(keywords_m, cl.keywords_m);
	return *this;

}




