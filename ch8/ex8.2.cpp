#include <iostream>

using namespace std;

struct CandyBar
{
	char brand[30];
	float weight;
	int calory;
};



void fillCandy(CandyBar & candy, const char * br="Millennium Munch", float w = 2.85, int calory = 350);

void showCandy(const CandyBar & candy);

int main()
{
	CandyBar cand1;
	fillCandy(cand1, "M&M", 3.12, 1200);
	showCandy(cand1);
	
	CandyBar cand2;
	fillCandy(cand2);
	showCandy(cand2);
	return 0;
}

void fillCandy(CandyBar & candy, const char * br, float w, int calory)
{
	int i = 0;
	while(*(br+i)) {
		candy.brand[i] = *(br+i);
		i++;
	}
	candy.brand[i] = '\0';
	candy.weight = w;
	candy.calory = calory;
}

void showCandy(const CandyBar & candy)
{
	cout << "Brand: " << candy.brand 
		<< "\nweight: " << candy.weight
		<< "\ncalroy: "	<< candy.calory << endl;
}