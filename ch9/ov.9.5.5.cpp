#include <iostream>
using namespace std;
static int average (int a, int b);
extern void displayD();


int main()
{
	cout << "Int call:" << average(3,6) << endl;
	displayD();
	return 0;
}

static int average(int a, int b)
{
	return (a + b) / 2;
}

