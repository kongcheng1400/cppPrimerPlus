#include <iostream>

using std::cout;
using std::endl;


class Frabjous
{
	private:
		char fab[20];

	public:
		Frabjous(const char * s = "C++ Frab");
		Frabjous(const Frabjous &);
		virtual void tell() {cout << fab;}

};

class Gloam
{
	private:
		int glip;
		Frabjous fb;

	public:
		Gloam(int g = 0, const char * s = "c++ Gloam");
		Gloam(int g, const Frabjous & f);
		void tell();
};

