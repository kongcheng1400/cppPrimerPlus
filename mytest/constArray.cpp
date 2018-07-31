#include<iostream>

const double * find(const double * arr, int len, const double & val);


int main()
{

	return 0;
}





const double * find(const double * arr, int len, const double & val)
{
	for (int i = 0; i < len; i++)
		if (*(arr+i) == val)
			return arr+i;
	return nullptr;

}

