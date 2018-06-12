#include <iostream>

using namespace std;

const int Max = 10;

unsigned fillScore(double * scores, int len);
void displayScore(double * scores, int len);
double cac_avg(double scores[], int len);


int main()
{
	double scores[Max];
	unsigned acutalCnt = 0;
	
	acutalCnt = fillScore(scores, Max);
	displayScore(scores, acutalCnt);
	cac_avg(scores, acutalCnt);
	
	return 0;
}

unsigned fillScore(double * scores, int len)
{
	unsigned actualInput = 0;
	cout << "Input your scores:ends with other!\n";
	double tmp = 0;	
	
	for (int i = 0; i < len; i++) {
		cout << "score " << i << ":";
		
		cin >> tmp;
		while (!cin) {
			cin.clear();
			while(cin.get() != '\n') 
				continue;
			cout << "Wrong input, input again:";
			cin >> tmp;
		}
		if (tmp != 0)
			*(scores + i) = tmp;
		else
			break;
		
		actualInput++;
	}
	return actualInput;	
}

void displayScore(double * scores, int len)
{
	cout << "you got scores of below:\n";
	for (int i = 0; i < len; i++){
		cout << *(scores+i) << "  ";
	}
	cout << endl;
}

double cac_avg(double scores[], int len){
	double result = 0.0;
	double total = 0.0;
	for (int i = 0; i < len; i++)
		total += scores[i];
	
	result = total/len;
	cout << "average value: " << result << endl;
	return result;
}