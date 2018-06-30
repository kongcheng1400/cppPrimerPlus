#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include "vector.h"

using namespace std;
using namespace VECTOR;

int randwalk(double target, double step);

int main()
{
	int N;
	int max, min, avg, total;
	min = INT_MAX;
	cout << "input test times: ";
	while (!(cin >> N)){
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "input correct value:";
	}

	cout << "\ninput taregt distance:";
	double target;
	while (!(cin >> target)) {
	
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "input correct value:";
	}

	
	cout << "\ninput each step:";
	double step;
	while (!(cin >> step)){
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "input correct value:";
	}

	srand(time(0));
	
	int temp = 0;
	for (int i = 0; i < N; i++){
		temp = randwalk(target, step);
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;	
		total = temp + total;
	}
	avg = total / N;
	
	cout << endl;
	cout << "with " << N << " times, max = " << max
		 << "; min = " << min << " , avg = " << avg << endl;



	return 0;
}

int randwalk(double target, double step)
{
	int steps = 0;
	Vector v;
	double randAng=0;
	
	while(v.magval() < target){
		randAng = rand() % 360;
		//cout << "rangAng=" << randAng << endl;
		v = v + Vector(step, randAng, Vector::POL);
		steps++;
	
	}

	return steps;
}
