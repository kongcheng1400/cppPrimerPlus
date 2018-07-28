#include "baddude.h"

Card & Card::operator=(const Card & c)
{
	if (this == &c)
		return *this;
	else
	{
		color_m = c.color_m;
		value = c.value;
		return *this;
	}

}

ostream & operator<<(ostream & os, const Card & c)
{
	os << "his card is ";
	switch (c.color_m){
		case Card::spade: os << " spade "; break;
		case Card::heart: os << " heart "; break;
		case Card::club:  os << " club "; break;
	    case Card::diamond: os << " diamond "; break;

	}

	os << c.value ;
	return os;	
}

Person & Person::operator=(const Person & p)
{
	if (this == &p)
		return *this;
	else {
		firstName = p.firstName;
		lastName = p.lastName;
		return *this;	
	}
}


GunSlinger & GunSlinger::operator=(const GunSlinger & gs)
{
	if (this == &gs)
		return *this;
	Person::operator=(gs);
	time = gs.time;
	kills = gs.kills;
	return *this;

}


PokerPlayer & PokerPlayer::operator=(const PokerPlayer & pp)
{
	if (this == &pp)
		return *this;
	Person::operator=(pp);
	myCard = pp.myCard;
	return *this;
}

BadDude & BadDude::operator=(const BadDude & bd)
{
	if (this == &bd)
		return *this;
	Person::operator=(bd);
	GunSlinger::operator=(bd);
	PokerPlayer::operator=(bd);
	return *this;


}



