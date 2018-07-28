#include <iostream>
#include "tabtenn0.h"

int main(void)
{
	using std::cout;
	TableTennisPlayer player1("Chunck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.name();

	if (player1.hasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";

	player2.name();
	if (player2.hasTable())
		cout << ": has a table";
	else
		cout << ": hasn't a table.\n";


	return 0;
}
