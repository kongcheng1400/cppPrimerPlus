#include "emp.h"

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;


Abstr_emp::Abstr_emp()
	: fname("Employee"), lname("Nobody"), job("worker") {};

Abstr_emp::Abstr_emp(const string & fn, const string & ln, const string & j)
	: fname(fn), lname(ln), job(j) {}

void Abstr_emp::displayEmployee() const
{
	cout << "Name: " << fname << " " << lname << ",job:" << job << endl;
}

Abstr_emp::~Abstr_emp() {};


void Abstr_emp::setEmployee()
{
	cout << "Please input first name:";
	getline(cin, fname);
	
	cout << "Please input last name: "; 
	getline(cin, lname);
	
	cout << "please input job: ";
	getline(cin, job);
}


void Abstr_emp::showAll() const
{
	cout << "\nEmployee is here: \n";
	displayEmployee();	
	cout << endl;
}

void Abstr_emp::setAll()
{
	cout << "Collect information for set an employee:\n";
	setEmployee();
}

std::ostream & operator<<(std::ostream & os, const Abstr_emp & e)
{

	os << "Name: " << e.fname << " " << e.lname << ",job:" << e.job << endl;
	return os;
}


//class Employee
Employee::Employee() : Abstr_emp() {};
Employee::Employee(const string & fn, const string & ln, const string & j)
	: Abstr_emp(fn, ln, j) {};
void Employee::showAll() const { Abstr_emp::showAll();};
void Employee::setAll() { Abstr_emp::setAll();};

//class Manager
Manager::Manager(): Abstr_emp(), inChargeOf_m(0) {};

Manager::Manager(const string & fn, const string & ln, const string & j, int ico)
	: Abstr_emp(fn, ln, j), inChargeOf_m(ico) {};

Manager::Manager(const Abstr_emp & e, int ico)
	: Abstr_emp(e), inChargeOf_m(ico) {};

Manager::Manager(const Manager & m )
	: Abstr_emp(m), inChargeOf_m(m.inChargeOf()) {};

void Manager::displayManager() const
{
	cout << "In charege of " << inChargeOf() << " employees" << endl;
}

void Manager::setManager()
{
	cout << "Please input manager's charged number:";
	while(! (cin >> inChargeOf()))
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "illegal value, input an unsigned value for this:";
	}
	cin.get();
	//inChargeOf() = num;
}

void Manager::showAll() const
{
	cout << "\nManager is here:\n";
	displayEmployee();
	displayManager();
	
}

void Manager::setAll()
{
	cout << "\nGet information of a manager:\n";
	setEmployee();
	setManager();
}


//class methods of Fink
Fink::Fink(const string & fn, const string & ln, const string & j,
		const string & rpo)
	: Abstr_emp(fn, ln, j), reportsTo_m(rpo) {};

Fink::Fink() : Abstr_emp(), reportsTo_m("nobody") {};

Fink::Fink(const Abstr_emp & e, const string & rpo)
	: Abstr_emp(e), reportsTo_m(rpo) {};

Fink::Fink(const Fink & e) : Abstr_emp(e), reportsTo_m(e.reportsTo()) {};

void Fink::displayFink() const
{
	cout << " reports to " << reportsTo() << endl;
}

void Fink::setFink()
{
	cout << "please input name of his manager:";
	getline(cin, reportsTo());
}


void Fink::showAll() const
{
	cout << "\nFink is below:\n";
	displayEmployee();
	displayFink();

}

void Fink::setAll() 
{
	cout << "\nCollection Information of Fink:\n";
	setEmployee();
	setFink();

}

//class HighFink methods
HighFink::HighFink() : Abstr_emp(), Manager(), Fink() {};

HighFink::HighFink(const string & fn, const string & ln, const string & j,
		const string & rpo, int ico)
	: Abstr_emp(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {};

HighFink::HighFink(const Abstr_emp & e, const string & rpo, int ico)
	: Abstr_emp(e), Manager(e, ico), Fink(e, rpo) {};

HighFink::HighFink(const Fink & f, int ico)
	: Abstr_emp(f), Manager(f, ico), Fink(f) {};

HighFink::HighFink(const Manager & m, const string & rpo)
	: Abstr_emp(m), Manager(m), Fink(m, rpo) {};

HighFink::HighFink(const HighFink & h) : Abstr_emp(h), Manager(h), Fink(h) {};

void HighFink::showAll() const
{
	cout << "\nHigh Fink is below:\n";
	displayEmployee();
	displayManager();
	displayFink();

}

void HighFink::setAll()
{
	cout << "\nCollect information of high fink:\n";
	setEmployee();
	setManager();
	setFink();

}



