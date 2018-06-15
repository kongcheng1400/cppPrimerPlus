#include <iostream>

using namespace std;

struct box 
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};


//prototype:
void showbox(box & b);
void setVol(box & b);

int main()
{
	box b = {"Dame Cartoon", 3.93, 2.6, 10.8};
	box a = {"Dame Cartoon", 4.93, 1.6, 9.8};
	setVol(b);
	showbox(b);
	return 0;
}




//definition:
void showbox(box & b)
{
	cout << "Maker: " << b.maker << endl;
	cout << "Height * width * length = Vol:\n" << b.height << " * " 
			<< b.width << " * " << b.length 
			<< " = " << b.volume << endl;
}

void setVol(box & b)
{
	b.volume = b.height * b.width * b.length;
}