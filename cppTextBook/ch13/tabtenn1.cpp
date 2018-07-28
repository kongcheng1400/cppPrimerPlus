#include "tabtenn1.h"
#include <iostream>


TableTennisPlayer::TableTennisPlayer(const string & fn,
		const string & ln, bool ht): firstName_m(fn), lastName_m(ln), hasTable_m(ht) {}


void TableTennisPlayer::name() const
{
	std::cout << lastName_m << ", " << firstName_m;

}


RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, 
						 bool ht): TableTennisPlayer(fn, ln, ht)
{
	rating_m = r;
}


RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
	: TableTennisPlayer(tp), rating_m(r)
{
}
