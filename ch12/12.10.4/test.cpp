#include <iostream>
#include "stack.h"

int main()
{
	using namespace std;
	Stack s1;
	for (int i = 0; i < Stack::MAX; i++)
		s1.push(100+i);

	Stack s2 = s1;
	Stack s3(s1);

	while(!s1.isempty())
	{
		Item i;
		s1.pop(i);
		cout << "s1 poped " << i << endl;
	}

	Item i1;
	s2.pop(i1);
	s2.pop(i1);
	while(!s2.isempty())
	{
		Item i;
		s2.pop(i);
		cout << "s2 poped " << i << endl;
	}



	return 0;
}
