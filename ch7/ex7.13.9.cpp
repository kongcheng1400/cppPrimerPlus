#include <iostream>
#include <cstring>

using namespace std;

const int SLEN = 30;

struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int coplevel;
};


int getinfo(student pa[], int n);

void display1(student st);

void display2(const student * ps);

void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	
	for (int i = 0; i < entered; i++) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	
	
	return 0;
}

int getinfo(student pa[], int n){
	cout << "Please input the students informations:\n";
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cout << "\nFullName:\t";
		cin.getline(pa[i].fullname, SLEN);
		if (strlen(pa[i].fullname) == 0)
			break;
		
		cout << "Hobby:\t\t";
		cin.getline(pa[i].hobby, SLEN);
		
		cout << "CopLevel:\t";
		cin >> pa[i].coplevel;	
		while (cin.get() != '\n')
			continue;
		
		
		cnt++;
	}
	
	cout << cnt << " students are inputed.\n";
	return cnt;
	
}

void display1(student st)
{
	cout << "\nFullName:\t" << st.fullname << "\n"
		<< "Hobby:\t" << st.hobby << "\n"
		<< "coplevel:\t" << st.coplevel << "\n";
}

void display2(const student * ps)
{
	cout << "\nDisplay 2:\n";
	display1(*ps);
}

void display3(const student pa[], int n)
{
	cout << "\nDisplay 3:\n";
	for (int i = 0; i < n; i++) {
		display1(*(pa+i));
	}
}