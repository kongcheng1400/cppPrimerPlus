#include <iostream>
#include "tabtenn1.h"

int main(void)
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "duck", true);
	
	rplayer1.name(); //drived object uses base method.
	if (rplayer1.hasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";

	player1.name(); //base object uses base method.
	if (player1.hasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";

	cout << "Name: ";
	rplayer1.name();
	cout << "; Rating: " << rplayer1.rating() << endl;
	
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.name();
	cout << "; Raing: " << rplayer2.rating() << endl;

return 0;
}
