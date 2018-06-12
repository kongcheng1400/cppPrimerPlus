#include <iostream>

using namespace std;

double cac_avg(int a, int b);


int main()
{
	int a =0, b = 0;
	
	cout << "Please input two int number, end with 0: \n";
	for (;;) {
		cin >> a >> b;
		if (!cin) {
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "\nillegal input, please input again:\n";
		} else if ( b == 0 || a == 0) {
			cout << "\nBye!";
			break;
		} 
		else {
			cout << "\n average is " << cac_avg(a, b) << endl;
			cout << "continue the input Please:\n";
		}		
	}
	
	return 0;
}

double cac_avg(int a, int b)
{
	return 2.0 * a * b / (a + b);
}