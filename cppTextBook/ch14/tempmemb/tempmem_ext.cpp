#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class beta
{
	private:
		template <typename V> 
			class hold;
		hold<T> q;
		hold<int> n;

	public:
		beta(T t, int i) : q(t), n(i) {};
		template <typename U> 
			U blab(U u, T t);
		void Show() const {q.show(); n.show();}
};

template <typename T>
	template <typename V>
class beta<T>::hold
{
private:
	V val;
public:
	hold(V v= 0) : val(v) {}
	void show() const { cout << val <<endl;}
	V Value() const { return val;}		
};

template<typename T>
	template<typename U> //template method
U beta<T>::blab(U u, T t) 
{
	return (n.Value() + q.Value()) * u / t;
}




int main()
{
beta<double> guy(3.5, 3);
cout << "T was set to double\n";
guy.Show();
cout << "V was set to T, which is double, then V was set to int \n";
cout << guy.blab(10, 2.3) << endl;
cout << "U was set to int\n";
cout << guy.blab(10.0, 2.3) << endl;
cout << "U was set to double\n";
cout << "Done\n";



return 0;
}

