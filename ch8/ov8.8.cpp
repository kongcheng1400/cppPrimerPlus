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
void showbox(box b);
void setVol(box & b);


template <typename T> 
T compare(const T a, const T b)
{
	return a > b ? a : b;
}

template <> box compare<box>(const box a, const box b); 

int main()
{
	int a = 3, b = 10;
	cout << "a = " << a << ", b= " << b
		<< " ; bigger one is " << compare(a, b) << endl;
		
	box bb = {"Dame Cartoon", 3.93, 2.6, 10.8};
	box ba = {"Crown Box", 4.93, 1.6, 9.8};
	setVol(bb);
	setVol(ba);
	showbox(bb);
	showbox(ba);
	cout << "\nbigger one is " << endl;
	showbox(compare(bb, ba));

	
	return 0;
}

template <> box compare<box>(const box a, const box b)
{
	return a.volume > b.volume ? a : b;
}

//definition:
void showbox(box b)
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