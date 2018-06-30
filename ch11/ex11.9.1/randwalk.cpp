#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;

	srand(time(0));
	
	double direction;

	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream ofresult;
	ofresult.open("result");
	

	cout << "Enter target distance (q to quit):";
	while (cin >> target)
	{
		if (!ofresult.good())
			break;

		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			ofresult << "dstep = " << dstep << ", direction= " << direction << endl;
			 
			step.reset(dstep, direction, Vector::POL);
			result =result + step;
			steps++;
			ofresult << "step" << steps << ": " << result << endl;
		}

		cout << "Afeter " << steps << " steps, the subject "
			 "has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step =  "
			 << result.magval()/steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";

	}
	ofresult.close();

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}
