/*
1. ʹ�ú�����3������.
    - ��������ԭ��
	- ���庯��
	- ���ú���
2. д�����溯����ԭ��
*/
void igor();
float tofu(int a);
double mpg(double, double);
long summation(long ar[], int len);
double doctor(const char str[]); or double doctor(const char str *)
void ofcource(boss ba);

//3. ��дһ������3�������ĺ���
//prototype
void fillArray(int ar[], int len, int val);

//definition
void fillArray(int ar[], int len, int val) {
	for (int i = 0; i < len; i++)
		ar[i] = val;
}

//4. ��дһ������3�������ĺ�����ʹ������ָ�룬�Լ�һ��int ֵ
//prototype
void fillArrayByPointer(int * start, int * end, int val);

void fillArrayByPointer(int * start, int * end, int val){
	while (start < end) {
		*start = val;
		start++;
	}
}

//5. 
//prototype
double findMax(const double * arr, int len);

double findMax(const double * arr, int len)
{
	double maxVal = 0.0;
	for (int i = 0; i < len; i++) {
		if (*(ar+i) >= maxVal)
			maxVal = *(ar+i);
	}
	
	return maxVal;
}


//6.
������ʹ��const��ζ�Ų����޸�ָ���Ӧ�������ֵ��
��������ʹ��ֵ���ݣ��޲��޶����޷��޸ġ�
����ʹ��ַ���ݣ����ܻ��޸ĵ�ַָ���ֵ��

//7 3���ַ���
char str [10];��'\0'�����ħ�har����
{"abc"}:��������
char *str = {"abc"}; charָ��

//8 ��дһ��������ԭ�����£����ַ����滻
int replace(char * str, char c1, char c2){
	int cnt = 0;
	while (*str) {
		if (*str == c1) {
			*str = c2;
			cnt++;
		}
		str++;
			
	}
	return cnt;
}
//9.
//*pizza : *���ֵ���߽�����������(dereferencing),�õ���ַpizza��ֵ
//taco
//10. C++�Խṹ����Ե���������:��ֵ���ݻ���ʹ��ָ�밴ַ���ݡ�
//11. int judge(int (*funP)(const char *))

//12.
//




