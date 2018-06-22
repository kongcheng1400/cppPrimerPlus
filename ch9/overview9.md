# overview 9 answer
1. 存储方案
4 种存储方案: 
- 自动存储持续性:
- 静态存储,外部链接性， 静态存储内部链接性， 静态存储无链接性
- 线程存储
- 动态存储.
1.a  homer函数形参, 自动存储持续性
1.b secret两个文件共享：静态存储外部链接性
1.c topsecret: 静态存储内部链接性，
1.d beencalled:静态存储无链接性

2. using声明与 using编译指令的区别:
using std::cout; //声明，引入一个名字
using namespace std; //编译指令引入所有名字 

6. 未命名的namespace:从声明点开始到声明区域结束。 因为没有命名所以其他文件无法引用，相当于内部链接性.
