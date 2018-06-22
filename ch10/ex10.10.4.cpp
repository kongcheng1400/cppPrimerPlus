#include <iostream>
#include "ex10.10.4.h"

void Sales::calculate()
{
	double total = 0;
	max = min = sales[0];
	for (int i = 0; i < QUARTERS; i++)
	{
		if (sales[i] > max)
			max = sales[i];
		else
			min = sales[i];
	
		total += sales[i];
	}
	average = total/QUARTERS;	
}


Sales::Sales()
{
	int cnt = 0;
	std::cout << "Please input the 4 sales number:\n";
	while (cnt < QUARTERS && std::cin >> sales[cnt])
	{
		if (!std::cin){
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
		} else
		{
			cnt++;
		}
	}
	calculate();
}


Sales::Sales(const double ar[], int n)
{
		int cnt = 0;
		cnt = (n > QUARTERS) ? QUARTERS : n;
		for (int i = 0; i < cnt; i++)
		{
			sales[i] = ar[i];	
		}
		calculate();
}

void Sales::showSales() const
{
	std::ios_base::fmtflags old_flags = std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);
	std::cout << "\nsales:" << sales[0] << ","
							<< sales[1] << ","
							<< sales[2] << ","
							<< sales[3] << std::endl;
	std::cout << "Average:" << average << " , Max=" << max << " , Min =" 
				  << min << std::endl;
	std::cout.setf(old_flags, std::ios::floatfield);
}