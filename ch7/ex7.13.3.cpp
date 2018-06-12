#include <iostream>

using namespace std;

//prototpyes

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void displayBox(box b);
void calVol(box * b);

int main()
{
	box b1 = {"Made by Box", 1.99, 2.33, 4.55, 0};
	displayBox(b1);
	calVol(&b1);
	displayBox(b1);
	return 0;
}

void displayBox(box b)
{
	cout << "Height:\t" << b.height << endl;
	cout << "width:\t" << b.width << endl;
	cout << "length:\t" << b.length << endl;
	cout << "volume:\t" << b.volume << endl;
}

void calVol(box * pBox){
	pBox->volume = pBox->height * pBox->width * pBox->length;
}