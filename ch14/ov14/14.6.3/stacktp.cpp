#include <iostream>
#include <string>
#include <cctype>

#include "stacktp.h"


using std::cin;
using std::cout;

int main()
{
	Stack<std::string> st;
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order, \n"
		 << "p to process a PO, or Q to quit.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
			case 'A':
			case 'a': cout << "Enter a PO nunmber to add: ";
					  cin >> po;
					  if (st.isfull())
						  cout << "stack already full\n";
					  else
						  st.push(po);
					  break;
			case 'p':
			case 'P': if (st.isempty())
						  cout << "stack already empty\n";
					  else 
					  {
						st.pop(po);
						cout << "PO #" << po << " poped\n";
						break;
					  }
		}
		cout << "Please enter A to add a purchase order, \n"
			 << "p to process a PO, or Q to quit.\n";
	}
	cout << "byte\n";
return 0;
}
