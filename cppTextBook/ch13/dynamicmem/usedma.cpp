#include <iostream>
#include "dma.h"

int main()
{
	using std::cout;
	using std::endl;

	BaseDMA shirt("portablelly", 8);
	LacksDMA balloon("Red", "Blimpo", 4);
	HasDMA map("Mercator", "Buffalo keys", 5);
	cout << "BaseDMA shirt:\n";
	cout << shirt << endl;

	cout << "LacksDMA obj:\n";
	cout << balloon << endl;

	cout << "HasDMA obj:\n";
	cout << map << endl;

	LacksDMA balloon2(balloon);
	cout << "Result of LacksDMA copy:\n";
	cout << balloon2 << endl;
	
	HasDMA map2;
	map2 = map;
	cout << "Result of HasDMA assignment:\n";
	cout << map2 << endl;
	return 0;


}
