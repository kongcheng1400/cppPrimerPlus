#include <iostream>

using namespace std;

//prototypes
const int Max = 10;

double * fillArray(double arr[], double * start, double * end);
void showArray(const double arr[], const double * start, const double * end);
void reverseArray(double arr[], double * start, double * end);

int main()
{
	double arr[Max];
	double * arrayEnd = fillArray(arr, arr, arr + Max);
	showArray(arr, &arr[0], arrayEnd);
	reverseArray(arr, &arr[0], arrayEnd);
	showArray(arr, &arr[0], arrayEnd);
	reverseArray(arr, &arr[0], arrayEnd);
	showArray(arr, &arr[0], arrayEnd);
	return 0;
}

double * fillArray(double arr[], double * start, double * end) {
	cout << "filling numbers into arrays:" << endl;
	double tmp = 0;
	int i = 0;
	while (start < end && cin >> tmp) 
	{
		*start = tmp;
		start++;
	}
	
	return start;
}

void showArray(const double arr[], const double * start, const double * end)
{
	cout << "\nDisplay Array:\n";
	while (start < end)
		cout << *(start++) << " ";
	
	cout << endl;
}

void reverseArray(double arr[], double * start, double * end)
{
	double tmp;
	while (start < end) {
		tmp = *start;
		*start = *(end-1);
		*(end-1) = tmp;
		start++;
		end--;
	}
}

