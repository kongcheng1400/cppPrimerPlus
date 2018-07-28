#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"

class Demo
{
	private:
		std::string word;
	public:
		Demo (const std::string & str)
		{
			word = str;
			std::cout << "Demo " << word << " created\n";	
		}

		~Demo()
		{
			std::cout << "Demo " << word << " destroyed\n";
		}

		void show() const
		{
			std::cout << "Demo " << word << " lives!\n";
		}
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	{
		Demo d1("found in block in main()");
		cout << "Enter two numbers: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y
					 << " is " << z << endl;
				cout << "ENter next pair: ";
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
				cout << "Values used: " << bg.v1 << "," << bg.v2 << endl;
				cout << "sorry, you don't get to play any more.\n";
				break;
			
			}
		
		
		}
		d1.show();
	
	}
	cout << "Bye!\n";
	cin.get();
	cin.get();
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw BadHMean(a, b);
	return 2.0 * a * b / (a + b);

}

double gmean(double a, double b)
{
	if (a < 0 || b <0)
		throw BadGMean(a, b);
	return std::sqrt(a * b);
}

double means(double a, double b)
{
	double am, hm, gm;
	Demo d2("found in means()");
	am = (a + b) / 2.0;
	try 
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (BadHMean & bg)
	{
		bg.msg();
		std::cout << "Caught in means()\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;

}














