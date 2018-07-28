#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two number: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				 << " is " << z << endl;
			cout << "Geometric means of " << x << " and " << y
				 << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>:";
		}
		catch (BadHMean & bg)
		{
			bg.msg();
			cout << "Try again.\n";
			continue;
		}
		catch (BadGMean & bg)
		{
			cout << bg.msg();
			cout << "values used: " << bg.v1 << ", " << bg.v2 << endl;
			break;
		}
	
	
	
	}
	cout << "Bye:\n";
	return 0;




}


double hmean(double a, double b)
{
	if (a == -b)
		throw BadHMean(a, b);
	return 2.0 * a * b/(a+b);

}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw BadGMean(a, b);
	return std::sqrt(a * b);


}


