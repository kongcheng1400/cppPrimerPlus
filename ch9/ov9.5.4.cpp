#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	double x;
	cout << "Enter value: ";
	while (!(cin >> x))
	{
		cout << "Bad input, please enter a number: ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cout << "value = " << x << endl;
	return 0;	
}