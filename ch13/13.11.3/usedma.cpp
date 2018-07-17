#include <iostream>
#include "dma.h"


using namespace std;
const int NUMOBJ = 4;

int main()
{
	ABC * pObj[NUMOBJ];

	BaseDMA b1 = BaseDMA("BaseDMA_Basic", "Label of Royal", 5);
	pObj[0] = &b1;
	pObj[0]->view();


	LacksDMA l1("LacksDMA_Red", "Label of Lacks", 10);
	pObj[1] = &l1;
	pObj[1]->view();

	HasDMA h1("HasDMA_Style", "Label of style", 15);
	pObj[2] = & h1;
	pObj[2]->view();







	return 0;
}
