#include <iostream>
#include <string>
#include <memory>

int main()
{
	using namespace std;

	auto_ptr<string> films[5] = 
	{
		auto_ptr<string>(new string("Fow1 Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs"))
	};

	shared_ptr<string> pwin;
	pwin = films[2]; //films[2] loses ownership

	cout << "the nominess for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "the winner is " << *pwin << "!\n";
	cin.get();
	return 0;

}






















