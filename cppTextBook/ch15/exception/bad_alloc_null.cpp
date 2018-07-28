#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

struct Big
{
	double stuff[20000];
};

int main()
{
	Big * pb;
	try {
		cout << "trying to get a big block of memory:\n";
		pb = new (std::nothrow) Big[10000];
		cout << "got past the new request:\n";
	}
	catch (bad_alloc & ba)
	{
		cout << "caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	
	}
	if (pb == 0)
	{
		cout << "could not allocate momry. Bye\n";
		exit(EXIT_FAILURE);	
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[4] << endl;
	delete [] pb;


	return 0;
}
