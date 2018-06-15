#include <iostream>

using namespace std;

const int Max = 5;

//prototypes:
template <typename T>
void printArray(const T arr[]);

template <typename T>
T max5(T arr[]);


int main()
{
	int arr1[5] = {1,2,3,10,9};
	double arr2[5] = {3.1, 1.2, 0.99, 8.74, 10.22};
	
	printArray(arr1);
	cout << "max val is " << max5(arr1) << endl;
	
	printArray(arr2);
	cout << "max val is " << max5(arr2) << endl;
	
	
	return 0;
}

template <typename T>
void printArray(const T arr[])
{
	cout << endl;
	for (int i = 0; i < Max ; i++)
		cout << arr[i] << ",";
	
	cout << endl;
}

template <typename T>
T max5(T arr[])
{
	T temp;
	for (int i = 0; i < Max; i++)
		if (temp < arr[i])
			temp = arr[i];
	
	return temp;
}
