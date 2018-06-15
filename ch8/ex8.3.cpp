#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void toUp(string & str);

int main()
{
	string word = "C++ Primer Plus is my favorate book!";
	cout << word << endl;
	toUp(word);
	
	
	string testword;
	cout << "Enter a string (q to quit):";
	getline(cin, testword);
	while (testword != "q")
	{
		toUp(testword);
		cout << "next string (q to quit): ";
		getline(cin, testword);
		
	}
	return 0;
}

void toUp(string & str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	
	cout << str << endl;
}
