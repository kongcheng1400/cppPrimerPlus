#include <iostream>

#include <string>
#include "queuetp.h"

int main()
{
	using std::string;
	using std::cin;
	using std::cout;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "Please enter your name. you will be served in the order of arrival.\n"
				"Name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	
	}

	cout << "the queue is full, processing begins!\n";

	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	
	}

	return 0;


}
