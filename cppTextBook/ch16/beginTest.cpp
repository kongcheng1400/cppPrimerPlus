#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
	using namespace std;
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
	cout << *(v1.begin()) << endl;

	cout << "test begin() can be an output iterator:\n" << endl;
	*(v1.begin()) = 10;
	cout << *(v1.begin()) << endl;


	return 0;
}
