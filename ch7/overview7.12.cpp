/*
1. 使用函数的3个步骤.
    - 声明函数原型
	- 定义函数
	- 调用函数
2. 写出下面函数的原型
*/
void igor();
float tofu(int a);
double mpg(double, double);
long summation(long ar[], int len);
double doctor(const char str[]); or double doctor(const char str *)
void ofcource(boss ba);

//3. 编写一个接受3个参数的函数
//prototype
void fillArray(int ar[], int len, int val);

//definition
void fillArray(int ar[], int len, int val) {
	for (int i = 0; i < len; i++)
		ar[i] = val;
}

//4. 编写一个接受3个参数的函数：使用区间指针，以及一个int 值
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
对数组使用const意味着不能修改指针对应的数组的值。
基本类型使用值传递，限不限定都无法修改。
数组使用址传递，可能会修改地址指向的值。

//7 3种字符串
char str [10];以'\0'结束的сhar数组
{"abc"}:常量数组
char *str = {"abc"}; char指针

//8 编写一个函数：原型如下，做字符串替换
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
//*pizza : *间接值或者解除引用运算符(dereferencing),得到地址pizza的值
//taco
//10. C++对结构就像对单个变量样:按值传递或者使用指针按址传递。
//11. int judge(int (*funP)(const char *))

//12.
//




