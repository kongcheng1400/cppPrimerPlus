#include <iostream>

using namespace std;

int factorial(int a);

int main()
{
	int inVal = 0;
	cout << "Input a integer, other to quit:";
	while (cin >> inVal) {
		cout << "result is " << factorial(inVal) << endl;
		cout << "Input a integer, other to quit:";		
	}
	if (!cin) {
		cin.clear();
		cout << "Bye with illegal input!\n";
	}
		
	return 0;
}


int factorial(int a)
{
	int result = 0;
	if (a == 0 || a == 1)
		result = 1;
	else 
		result = a * factorial(a - 1);
	return result;
}