#include <cstring>
#include "frabgloam.h"
Frabjous::Frabjous(const char * s)
{
	std::strncpy(fab, s, 19);
	fab[19] = '\0';
}

Frabjous::Frabjous(const Frabjous & fb)
{
	std::strncpy(fab, fb.fab, 19);
	fab[19] = '\0';
}


Gloam::Gloam(int g, const char * s)
	:fb(s), glip(g)
{
}


Gloam::Gloam(int g, const Frabjous & f)
	: glip(g), fb(f)
{
}

void Gloam::tell()
{
	fb.tell();

	cout << "glip = " << glip << endl;
}

int main()
{
	Gloam g1;
	g1.tell();
	cout << endl;
	Gloam g2(10, "mytest!");
	g2.tell();
	return 0;

}
