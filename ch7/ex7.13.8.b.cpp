#include <iostream>

using namespace std;


const int nSeasons = 4;

const char * seasonNames[4] = {"Spring", "Summer", "Fall", "Winter"};

struct expense {
	double exp;
};

//prototypes
void fill(expense expArr[], int len);
void show(expense expArr[], int len);

int main()
{
	expense expArr[nSeasons];
	fill(expArr, nSeasons);
	show(expArr, nSeasons);
	return 0;
}

void fill(expense expArr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Enter " << i << " expense: ";
		cin >> expArr[i].exp;
	}
}

void show(expense expArr[], int len)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	
	for (int i = 0; i < len; i++) {
		cout << seasonNames[i] << ": \t$" << expArr[i].exp << endl;
		total += ""[i].exp;
	}
	cout << "Total Expenses: $" << total << endl;
}