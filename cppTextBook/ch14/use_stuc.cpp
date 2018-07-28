#include <iostream>
#include "studentc.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student &sa, int n);
const int pupiles = 3;
const int quizzes = 5;

int main()
{

	Student ada[pupiles] = {Student(quizzes), Student(quizzes), Student(quizzes)};

	int i;
	for (i = 0; i < pupiles; ++i)
		set(ada[i], quizzes);

	cout << "\nStudent List:\n";
	for (i = 0; i < pupiles; ++i)
		cout << ada[i].name() << endl;
	cout << "\nResults:";

	for (i = 0; i < pupiles; ++i)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].average() << endl;
	}

	cout << "Done.\n";
return 0;
}


void set(Student & sa, int n)
{
	cout << "Please enter the name of students: ";
	cin >> sa;
	while (cin.get() != '\n')
		continue;
	//getline(cin, sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;

}

