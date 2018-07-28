#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string one("Lottery winner!"); //string(const char *)
	cout << one << endl;
	string two(20 , '$'); //string(size_type n, char c)
	cout << two << endl;
	string three(one); // string(const string & s)
	cout << three << endl;
	one += "oops!";
	cout << one << endl; 
	two = "Sorry! that was "; //string(const char *)
	three[0] = 'P';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20); //string(const char * s, size_type n)
	cout << five << "!\n";
	string six(alls+6, alls + 10);//template <class Iter> string(Iter begin, Iter end)
	cout << six << ", ";
	string seven(&five[6], &five[10]); //template <class Iter> string(Iter begin, Iter end)
	cout << seven << "...\n";
	string eight(four, 7, 16); //string(const string & str, string size_type pos = 0, size_type n = npos)
	cout << eight << " in motion!" << endl;
	return 0;



}
