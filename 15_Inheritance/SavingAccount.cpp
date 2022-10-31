#include "SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount() : Account{}, interestRate{ 3.0 } {
	std::cout << "SavingAccount constructor" << std::endl;
}

SavingAccount::SavingAccount(double balance, std::string name, double ir) : Account{ balance, name }, interestRate{ ir } {
	std::cout << "SavingAccount overloaded constructor" << std::endl;
}

SavingAccount::SavingAccount(const SavingAccount& source) : Account{source}, interestRate{ source.interestRate } {
	std::cout << "SavingAccount copy constructor" << std::endl;
}

SavingAccount::~SavingAccount() {
	std::cout << "SavingAccount destructor" << std::endl;
}

SavingAccount& SavingAccount::operator=(const SavingAccount& rhs) {
	if (this != &rhs) {
		Account::operator=(rhs);
		interestRate = rhs.interestRate;
	}

	return *this;
}

void SavingAccount::deposit(double amount) {
	amount = amount + (amount * interestRate / 100);
	Account::deposit(amount);
}

std::ostream& operator<<(std::ostream& os, const SavingAccount& account) {
	os << "\n----------------------------------------------------------\n";
	os << "Account: " << account.name << " - balance: " << account.balance;
	os << "\n----------------------------------------------------------\n";
	return os;
}