#include <iostream>
#include <string>
#include "account.h"

using namespace std;

int main()
{
	Account A1 = Account("Harry He", "A1325", 32004.2);
	A1.showaccount();
	A1.deposit(3000);
	A1.withdraw(4000);
	A1.showaccount();
	
	return 0 ;
}