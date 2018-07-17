#include <iostream>
#include "string1.h"

int main()
{
	using namespace std;
	
	{
		String s1("S1");
		cout << "\n\nS2 created by = String s2 = s1:\n";
		String s2 = s1;
		

		cout << "\n\nS3 =s2 + \"s3\"";
		String s3;
		s3 = s2 + "   s3";
	
	}

	cout << "\n\nfinale object nuber is " << String::HowMany() << endl;
	return 0;
}
