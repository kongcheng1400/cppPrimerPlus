#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) 
	: firstName(ln), lastName(ln), hasTable_m(ht) {}


void TableTennisPlayer::name() const
{
	std::cout << lastName << ", " << firstName;

}
