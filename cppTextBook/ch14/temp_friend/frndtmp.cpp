#include <iostream>

using std::cout;
using std::endl;

//template prototypes
template <typename T> void counts();
template <typename T> void reports(T &);


template <typename TT>
class HasFriend
{
	private:
		TT item;
		static int ct;

	public:
		HasFriend(const TT & i): item(i) {ct++;}
		~HasFriend() {ct--;}
		friend void counts<TT>();
		friend void reports<>(HasFriend<TT> & hf); //template parameter

};


template <typename T>
int HasFriend<T>::ct = 0;

//non-tempalte friend to all HasFrined<T> classes
template <typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriend<T>) << "; ";
	cout << "template counts(): "  << HasFriend<T>::ct << endl;
}

template <typename T>
void reports(T & hf)
{
	cout << "HasFriend<T>: " << hf.item << endl;
}

int main()
{
	cout << "no objects delcared: ";
	counts<int>();
	HasFriend<int> hfi1(10);
	cout << "after hfi1 declared: ";
	counts<int>();
	HasFriend<int> hfi2(20);
	cout << "after hfi2 declared: ";
	counts<int>();
	HasFriend<double> hfdb(10.5);
	cout << "after hfdb declared: ";
	counts<double>();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);


	return 0;
}
