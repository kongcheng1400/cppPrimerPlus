#include <iostream>

using namespace std;

//prototypes
const int Max = 10;

int fillArray(double arr[], int len);
void showArray(double arr[], int len);
void reverseArray(double arr[], int len);

int main()
{
	double arr[Max];
	int arrayLen = fillArray(arr, Max);
	showArray(arr, arrayLen);
	reverseArray(arr, arrayLen);
	showArray(arr, arrayLen);
	reverseArray(arr, arrayLen);
	showArray(arr, arrayLen);
	return 0;
}

int fillArray(double arr[], int len) {
	cout << "filling numbers into arrays:" << endl;
	double tmp = 0;
	int i = 0;
	while (cin >> tmp && i < len) 
	{
		arr[i] = tmp;
		i++;
	}
	
	return i;
}

void showArray(double arr[], int len)
{
	cout << "\nDisplay Array:\n";
	int i = 0;
	while (i < len)
	{
		cout << arr[i] << " ";
		i++;
	}
	
	cout << endl;
}

void reverseArray(double arr[], int len)
{
	int i = 0;
	int j = len - 1;
	double tmp;
	while (i < j) {
		tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
		i++;
		j--;
	}
}

