#include "baddude.h"


int main()
{
	int n = 4;
	Person * pPerson[4];	
	pPerson[0] = new PokerPlayer;
	pPerson[1] = new GunSlinger;
	pPerson[2] = new BadDude;


	pPerson[0]->show();
	pPerson[1]->show();
	pPerson[2]->show();

	cout << dynamic_cast<BadDude *>(pPerson[2])->cDraw();

return 0;
}
