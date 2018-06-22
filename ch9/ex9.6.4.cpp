#include <iostream>
#include "ex9.6.4.h"


namespace SALES
{

	void setSales(Sales & s, const double ar[], int n) {
		int cnt = 0;
		double max, min;
		max = min = ar[0];
		double total = 0;
		cnt = (n > 4) ? 4 : n;
		for (int i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
			if (ar[i] > max)
				max = ar[i];
			if (ar[i] < min)
				min = ar[i];
		
			total += ar[i];
		}
	
		s.average = total/ cnt;
		s.max = max;
		s.min = min;	
	}

	void setSales(Sales & s)
	{
		int cnt = 0;
		double total;
		std::cout << "Please input the 4 sales number:\n";
		while (cnt < 4 && std::cin >> s.sales[cnt])
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
		for (int i = 0; i < cnt; i++)
		{
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			else
				s.min = s.sales[i];
		
			total += s.sales[i];
		}
		s.average = total/cnt;
	}
	
	void showSales(const Sales & s)
	{
		std::ios_base::fmtflags old_flags = std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.precision(3);
		std::cout << "\nsales:" << s.sales[0] << ","
							  << s.sales[1] << ","
							  << s.sales[2] << ","
							  << s.sales[3] << std::endl;
		std::cout << "Average:" << s.average << " , Max=" << s.max << " , Min =" 
				  << s.min << std::endl;
		std::cout.setf(old_flags, std::ios::floatfield);
	}
};