#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullName_m = s;
	acctNum_m = an;
	balance_m = bal;

}

void AcctABC::deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; deposit is cancelled.\n";
	else
		balance_m -= amt;
}

void AcctABC::withdraw(double amt)
{
	balance_m -= amt;
}

//protected methods for formatting

AcctABC::Formatting AcctABC::setFormat() const
{
	//setup ###.## format
	Formatting f;
	f.flag_m = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr_m = cout.precision(2);
	return f;
}

void AcctABC::restore(Formatting & f) const
{
	cout.setf(f.flag_m, ios_base::floatfield);
	cout.precision(f.pr_m);
}

//Brass methods
void Brass::withdraw(double amt)
{
	if (amt < 0 )
		cout << "withdrawl amount must positive; withdraw cancelled.\n";
	else if (amt <= balance())
		AcctABC::withdraw(amt);
	else
		cout << "withdraw amout of $" << amt << " exceeds your balance.\n";

}

void Brass::viewAcct() const
{
	Formatting f = setFormat();
	cout << "Brass client: " << fullName() << endl;
	cout << "Account Number:" << acctNum() << endl;
	cout << "Balance:$" << balance() << endl;
	restore(f);

}

//BrasPlus methods

BrassPlus::BrassPlus(const std::string & s , long an  , double bal , double ml, double r):AcctABC(s, an, bal)
{
	maxLoan_m = ml;
	rate_m = r;
	owesBank_m = 0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml , double r ):AcctABC(ba)   //used implicit copy constructor
{
	maxLoan_m = ml;
	rate_m = r;
	owesBank_m = 0;

}

void BrassPlus::viewAcct() const
{
	Formatting f = setFormat();
	cout << "Brass client: " << fullName() << endl;
	cout << "Account Number:" << acctNum() << endl;
	cout << "Balance:$" << balance() << endl;
	cout << "maxmum load: $" << maxLoan_m << endl;
	cout << "owed to bank: $" << owesBank_m << endl;
	cout.precision(3);
	cout << "load rate: " << 100 * rate_m << "%\n";
	restore(f);


}



void BrassPlus::withdraw(double amt)
{
	Formatting f = setFormat();
	double bal = balance();
	if (amt <= bal)
		AcctABC::withdraw(amt);
	else if (amt <= bal + maxLoan_m - owesBank_m)
	{
		double advance = amt -bal;
		owesBank_m += advance * (1.0 + rate_m);
		cout << "back advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate_m << endl;
		deposit(advance);
		AcctABC::withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";

	restore(f);

}





