#include <iostream>

using namespace std;
//prototypes

double add(double x, double y);
double mult(double x, double y);
double sub(double x, double y);

double calculate(double x, double y, const char * funcName, double (*pf)(double, double));


int main()
{
	
	cout << "Please input two numbers:\n";
	double a, b;
	while (cin >> a >> b) {
		calculate(a, b, "add", add);
		calculate(a, b, "sub", sub);
		calculate(a, b, "sub", mult);
	}
	
	if (!cin) {
		cout << "end with wrong input!";
	}
	return 0;
}

double add(double x, double y){
	return x + y;
}

double mult(double x, double y){
	return x * y;
}

double sub(double x, double y){
	return x - y;
}
double calculate(double x, double y, const char * funcName, double (*pf)(double, double))
{	
	double result = (*pf)(x, y);
	cout << funcName << " : " << result << endl;
	return result;
}