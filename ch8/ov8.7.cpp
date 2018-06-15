#include <iostream>

using namespace std;

template <typename T> 
T compare(const T a, const T b)
{
	return a > b ? a : b;
}



int main()
{
	int a = 3, b = 10;
	cout << "a = " << a << ", b= " << b
		<< " ; bigger one is " << compare(a, b) << endl;
	return 0;
}