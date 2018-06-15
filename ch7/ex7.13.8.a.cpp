#include <iostream>

using namespace std;


const int nSeasons = 4;

const char * seasonNames[4] = {"Spring", "Summer", "Fall", "Winter"};

//prototypes
void fill(double expense[], int len);
void show(double expense[], int len);

int main()
{
	double expense[nSeasons];
	fill(expense, nSeasons);
	show(expense, nSeasons);
	return 0;
}

void fill(double expense[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Enter " << seasonNames[i] << " expense: ";
		cin >> expense[i];
	}
}

void show(double expense[], int len)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	
	for (int i = 0; i < len; i++) {
		cout << seasonNames[i] << ": \t$" << expense[i] << endl;
		total += expense[i];
	}
	cout << "Total Expenses: $" << total << endl;
}