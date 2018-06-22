#include <iostream>
using namespace std;
static double average(int a, int b);
void displayD();


static double average(int a, int b)
{
	return (a + b)/2.0;
}

void displayD(){
	cout << "\ndouble average is " << average(9, 10);
}