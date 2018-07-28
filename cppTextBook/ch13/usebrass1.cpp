#include <iostream>
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.viewAcct();
	cout << endl;
	Hoggy.viewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account:\n";
	Hoggy.deposit(1000.00);
	cout << "new balance: $" << Hoggy.balance() << endl;
	cout << "Withdrwaing $4200 from Pigg Account:\n";
	Piggy.withdraw(4200);
	cout << "Pigg account balance: $" << Piggy.balance() << endl;
	cout << "Withdraw 4200 from Hogg account:\n";
	Hoggy.withdraw(4200);
	Hoggy.viewAcct();


	return 0;

}
