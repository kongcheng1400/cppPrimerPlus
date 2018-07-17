#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
//averagetime is average process time of a customer:6~8
const int AVERAGEPROCESSTIME = 15; 
const int AVERAGECOMETIME = 8; //average time of customer comes
const int MAXWAITTIME = 5;

int getProcessTime();
bool newCustomer(int averageTime);

int main()
{
	using namespace std;
	srand(time(0));

	const int ticksPerHour = 60;
	unsigned hours;
	cout << "Input test hours:";
	cin >> hours;
	int totalTicks = hours * ticksPerHour;
	cout << "input average time of customer comes:";
	int averageComeTime;
	cin >> averageComeTime;

	Queue ATM(10);
	int totalCustomers=0;
	int turnAwayCustomers = 0;
	int finishedCustomers = 0;
	int costTime = 0;
	int processTime = 0;
	int totalCostTime = 0;
	//main loop:
	for (int i = 0; i < totalTicks; i++)
	{
		int currentTime = i + 1;
		if (newCustomer(averageComeTime))
		{
			Customer cst(totalCustomers, i);
			totalCustomers++;

			if (ATM.isfull())
			{
				turnAwayCustomers++;
				cout << "\nat tick i: " << i << ", " << cst << " turanaway!\n";
			}
			else
				ATM.enqueue(cst);
		}
	
		Customer tmp;
		if (ATM.getHead(tmp))
		{
			processTime++;
			if (processTime > getProcessTime())
			{
				costTime = processTime + currentTime - tmp.getArrivedTime();
				ATM.dequeue(tmp);
				processTime = 0;
				cout << "\nat tick i: " << i << ", " << tmp << " is finished!\n";
				finishedCustomers++;
				totalCostTime += costTime;

			}
		}
	}

	cout << "\nTotal customers: " << totalCustomers << "  finshed : " << finishedCustomers
	 << " average time: "<< totalCostTime/finishedCustomers  << " , turnaways: " << turnAwayCustomers << endl;

	return 0;
}

int getProcessTime()
{
	return AVERAGEPROCESSTIME + rand() % 3;
}

bool newCustomer(int averageTime)
{
	return rand() < (RAND_MAX / averageTime);
}


