#include <iostream>

using namespace std;

void func(const char * str, int cnt = 1);

int main()
{
	int cnt = 3;
	for (int i = 0; i < cnt; i++)
	{
		func("test", i+1);
	}
	
	return 0;
}

void func(const char *str, int cnt)
{
	cout << str << endl;
	cout << "calling " << cnt << " times!" << endl;
}