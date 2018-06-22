#include <iostream>
#include "account.h"


Account::Account(const string & name, const string & account, const double deposit)
{
	name_m = name;
	account_m = account;
	deposit_m = deposit;
}
void Account::showaccount() const
{
	cout << "\nName:" << name_m
		 << "\nAccount:" << account_m
		 << "\ndeposit:" << deposit_m
		 << endl;
}

void Account::deposit(double value)
{
	deposit_m += value;
}
		
void Account::withdraw(double value)
{
	deposit_m -= value;
}