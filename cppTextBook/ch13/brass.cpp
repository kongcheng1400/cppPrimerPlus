#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string & s, long an, double bal)
{
	fullName_m = s;
	acctNum_m = an;
	balance_m = bal;
}

void Brass::deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed;"
			 << "deposit is cancelled.\n";
	else
		balance_m += amt;
}

void Brass::withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "withdraw amount must be positive;"
			 << "withdraw cancelled.\n";
	else if (amt <= balance_m)
		balance_m -= amt;
	else
		cout << "withdraw amout of $" << amt
			 << "exceeeds your banlance.\n"
			 << "withdrawal cancelled.\n";
	restore(initialState, prec);
}

double Brass::balance() const
{
	return balance_m;
}

void Brass::viewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName_m << endl;
	cout << "Account number: " << acctNum_m << endl;
	cout << "Balance: $" << balance_m << endl;
	restore(initialState, prec);//

}

//Brass plus methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r):Brass(s, an, bal)
{
	maxLoan_m = ml;
	owesBank_m = 0.0;
	rate_m = r;

}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r): Brass(ba)
{
	maxLoan_m = ml;
	owesBank_m = 0.0;
	rate_m = r;
}




void BrassPlus::viewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::viewAcct();
	cout << "Max load: $" << maxLoan_m << endl;
	cout << "Owed to bank: $" << owesBank_m << endl;
	cout.precision(3);
	cout << "loan Rate: " << 100 * rate_m << "%\n";
	restore(initialState, prec);
}

void BrassPlus::withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = balance();
	if (amt <= bal)
		Brass::withdraw(amt);
	else if (amt <= bal + maxLoan_m - owesBank_m)
	{
		double advance = amt - bal;
		owesBank_m	+= advance *(1.0 + rate_m);
		cout << "Band advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate_m << endl;
		deposit(advance);
		Brass::withdraw(amt);
	}
	else
		cout << "Credit limit exceeded, Transaction cancelled.\n";
	restore(initialState, prec);
}


format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}










