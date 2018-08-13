auto_ptr<int> pia(new int[20]); //数组的delete方法不一样，不能这样用
auto_ptr<string> (new string); //生成一个匿名对象啊，析构函数怎么用.

int rigue = 7;
auto_ptr<int>pr(&rigue);//不能指向堆内存
auto_ptr db1 (new double); //nok，这是模板类。
