#include <iostream>
#include <cstring>

#include "stacktp.h"
#include "workermi.h"


const int SIZE = 5;


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	
	Stack<Worker *> sw;
	Worker * lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
		     << "w: waiter s: singer "
		     << "t: singing waiter q: quit\n";
		cin >> choice;

		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q:";
			cin >> choice;
		
		
		}		
		if (choice == 'q')
			break;
		switch (choice)
		{
			case 'w': lolas[ct] = new Waiter;
					  break;
			case 's': lolas[ct] = new Singer;
					  break;
			case 't': lolas[ct] = new SingingWaiter;
					  break;
		
		
		}
		cin.get();
		lolas[ct]->set();

		sw.push(lolas[ct]);
	}


	Worker * pw;

	int i;
	for (i = 0 ; i < ct; i++)
	{
		cout << "*****pop and ***** print";
		cout << endl;
		sw.pop(pw);
		pw->show();
		delete pw;
	
	}
	

	return 0;
};
