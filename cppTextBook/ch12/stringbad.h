#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
	private:
		char * str;
		int len;
		static int num_strings;

	public:
		StringBad(const char * s);
		StringBad();
		~StringBad();
		StringBad(const StringBad & st);
		
		StringBad & operator=(const StringBad & st);

	//friend
		friend std::ostream & operator<<(std::ostream & os, const StringBad & st);


};











#endif
