#include <iostream>
#include <string>

//constants
//function prototype
void strcount(const char * str);

int main()
{
        using namespace std;
        string input;
        cout << "Enter a line:\n";
		getline(cin, input);
		if ( input == "")
			cout << "empty string!\n";
        cout << "Bye\n";
        return 0;
}
