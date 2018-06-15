#include <iostream>
#include <cstring>

using namespace std;

const int Max = 5;

//prototypes:
template <typename T>
void printArray(const T arr[], int n);

template <typename T>
T maxn(T arr[], int n);

template <> 
char * maxn<char *>(char * arr[], int n);


int main()
{
	int arr1[5] = {1,2,3,10,9};
	double arr2[5] = {3.1, 1.2, 0.99, 8.74, 10.22};
	
	printArray(arr1, 5);
	cout << "max val is " << maxn(arr1,5) << endl;
	
	printArray(arr2, 5);
	cout << "max val is " << maxn(arr2, 5) << endl;
	
	const char * str1 = {"Repent for the kingdom of heaven is near."};
	const char * str2 = {"preaching in the Desert of Judea"};
	const char * str3 = {"A voice of one"};
	const char * str4 = {"Prepare the way for the lord"};
	const char * str5 = {"make straight paths for him"};
	
	const char * strArray[5] = {str4, str5, str1, str2, str3};
	printArray(strArray, 5);
	cout << "max str is \n" << maxn(strArray, 5) << endl;
	
	
	return 0;
}

template <typename T>
void printArray(const T arr[], int n)
{
	cout << endl;
	for (int i = 0; i < n ; i++)
		cout << arr[i] << ",";
	
	cout << endl;
}

template <typename T>
T maxn(T arr[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
		if (temp < arr[i])
			temp = arr[i];
	
	return temp;
}


template <> 
char * maxn<char *>(char * arr[], int n)
{
	char * temp;
	for (int i = 0; i < n; i++)
		if (strlen(temp) < strlen(arr[i]))
			temp = arr[i];
	
	return temp;
}