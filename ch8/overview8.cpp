//1. inline function: 短的，常用的

//2. 
void song(const char * name, int times = 1);
//函数定义不做修改.
//不行.
//3.
void iquote(int a);
void iquote(double a);
void iquote(string a);

4.
//prototype:
void showbox(box & b);
void setVol(box & b);
//definition:
void showbox(box & b)
{
	cout << "Maker: " << b.maker << endl;
	cout << "Height * width * length " << b.height << " * " 
			<< b.width << "*" << b.length << endl;
}

void setVol(box & b)
{
	b.volume = b.height * b.width * b.length;
}

6.
//a. 可以使用缺省参数完成
//b. 可以使用重载完成
//c. 重载可以完成
//d. 都不行。函数签名返回值不算.

7.
//
template <typename T> 
T compare(const T a, const T b)
{
	return a > b ? a : b;
}

