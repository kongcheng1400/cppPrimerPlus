#include <iostream>
#include <sstream>
#include <string>

int main()
{
	using namespace std;
	ostringstream outstr;

	string hdisk;
	cout << "what's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "what's its capacity in GB? ";
	cin >> cap;

	outstr << " The hard disk " << hdisk << " has a capacity of "
		   << cap << " gigabytes.\n";

	string result = outstr.str();
	cout << result;

	return 0;
}
