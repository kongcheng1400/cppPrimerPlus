#include <iostream>

using namespace std;

const int ArraySize = 10;

void fillArrayByPointer(int * start, int * end, int val);
void printArray(int ar[], int len);

int main()
{
	int arrayVal[ArraySize];
	printArray(arrayVal, ArraySize);
	int val = 5;
	fillArrayByPointer(arrayVal, arrayVal+ArraySize, val);
	printArray(arrayVal, ArraySize);
	
	
	return 0;
}

void fillArrayByPointer(int * start, int * end, int val){
	while (start < end) {
		*start = val;
		start++;
	}
}

void printArray(int ar[], int len){
	cout << "\nShow Array!" << endl;
	for (int i = 0; i < len; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
	
}