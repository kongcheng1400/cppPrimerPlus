#include <iostream>

using namespace std;

class Useless
{
	int n;
	char * pc;
	static int ct;
	void showObject() const;

public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f);//regular copy constructor
	Useless(Useless && f); //move constructor
	~Useless();

	Useless operator+(const Useless & f) const;
	void showData() const;


};

//implementation
int Useless::ct = 0;

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	cout << "default constructor called; number of objects: " << ct << endl;
	showObject();
}


Useless::Useless(int k) : n(k)
{
	++ct;
	cout << "int constructor called; number of ojbects: " << ct << endl;
	pc = new char[n];
	showObject();
}

Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	cout << "int, char constructor called, number of ojbects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	showObject();
}


Useless::Useless(const Useless & f): n(f.n)
{
	++ct;
	cout << "copy const called, number of ojbects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];

	showObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
	++ct;
	cout << "Move constructor called: number of ojbects: " << ct << endl;
	pc = f.pc; //steal address
	f.pc = nullptr;
	f.n = 0;
	showObject();
}

Useless::~Useless()
{
	cout << "destructor called; ojbects left: " << --ct << endl;
	cout << "deleted object:\n";
	showObject();
	delete [] pc;
}

Useless Useless::operator+(const Useless & f) const
{
	cout << "Entering operator+()\n";
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];

	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i-n];

	cout << "temp object:\n";
	cout << "Leaving operator+() \n";
	return temp;
}


void Useless::showObject() const
{
	cout << "Number of elements: " << n;
	cout << " data address: " << (void *)pc << endl;
}

void Useless::showData() const
{
	if (n == 0)
		cout << "(object empty)";
	else
		for (int i = 0; i < n; i++)
			cout << pc[i];

	cout << endl;
}

//application
int main()
{
	{
		Useless one(10, 'x');
		Useless two = one; //calls copy constructor
		Useless three(20, 'o');
		Useless four (one + three); //calls operator+(), move constructor
		
		cout << "Ojbect one: ";
		one.showData();
		cout << "Ojbect two: ";
		two.showData();
		cout << "Ojbect three: ";
		three.showData();
		cout << "Object four: ";
		four.showData();
	
	}

}














