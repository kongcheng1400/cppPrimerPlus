#include <iostream>
#include <new>
#include <cstring>

using namespace std;

//prototypes
struct chaff
{
	char dross[20];
	int slag;
};

char buff[500];

int main()
{
	chaff * pChaff = new (buff) chaff[2];
	strcpy((*(pChaff+0)).dross, "test1");
	(*(pChaff)).slag = 100;
	strcpy((*(pChaff+1)).dross, "test2");
	(*(pChaff+1)).slag = 200;
	
	for (int i = 0; i < 2; i++)
		cout << (*(pChaff+i)).dross << " : " << (*(pChaff+i)).slag << endl;	
	return 0;
}