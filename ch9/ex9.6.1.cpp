#include <iostream>
#include "ex9.1_golf.h"

using namespace std;


int main()
{
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	
	golf arrGolf[5];
	for (int i = 0; i < 5; i++) 
	{
		while(!setgolf(arrGolf[i])){
			cin.clear();
			while(cin.get() != '\n')
				continue;
		}
		showgolf(arrGolf[i]);
	}
	
	for (int i = 0; i < 5; i++){
		handicap(arrGolf[i], i+100);
		showgolf(arrGolf[i]);
	}
	return 0;
}