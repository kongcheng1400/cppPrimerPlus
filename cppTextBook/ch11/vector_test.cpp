#include <iostream>
#include "vector.h"

using namespace std;
using namespace VECTOR;


const Vector & max(const Vector & v1, const Vector & v2);


int main()
{	
	Vector f1(50,60);
	Vector f2(40,70);
	Vector v3 = max(f1, f2);
	cout << "max is " << v3 << endl;

	return 0;
}

const Vector & max(const Vector & v1, const Vector & v2)
{
	if (v1.magval() > v2.magval())
		return v1;
	else
		return v2;

}
