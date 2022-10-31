#include <iostream>
#include "SavingAccount.h"
#include "Account.h"


int main()
{
	/*******************************************************************
	* INHERITANCE
	*******************************************************************/

	std::cout << "\n--------------------------------- INHERITANCE -----------------------------------------\n";

	Account acc{};

	SavingAccount sacc{};

	SavingAccount sacc2{ 2000.0, "Arno", 5.0 };
	sacc2.deposit(1500);

	SavingAccount sacc3{ sacc2 };
	sacc3.deposit(371);

	sacc = sacc3;
	sacc.withdraw(3000);

	std::cout << acc << std::endl;
	std::cout << sacc << std::endl;
	std::cout << sacc2 << std::endl;
	std::cout << sacc3 << std::endl;

	return 0;
}
