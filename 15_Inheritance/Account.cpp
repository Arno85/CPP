#include "Account.h"
#include <iostream>

Account::Account() : balance{ 0.0 }, name{ "" } {
	std::cout << "Account constructor" << std::endl;
}

Account::Account(double b, std::string n) : balance{ b }, name{ n } {
	std::cout << "Account overloaded constructor" << std::endl;
}

Account::Account(const Account& source) : balance{ source.balance }, name{ source.name } {
	std::cout << "Account copy constructor" << std::endl;
}

Account::~Account() {
	std::cout << "Account destructor" << std::endl;
}

Account& Account::operator=(const Account& rhs) {
	if (this != &rhs) {
		balance = rhs.balance;
		name = rhs.name;
	}

	return *this;
}

void Account::deposit(double amount) {
	balance += amount;
}

void Account::withdraw(double amount) {
	if (balance - amount >= 0) {
		balance -= amount;
	}
	else {
		std::cout << "Insufficient funds" << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
	os << "\n----------------------------------------------------------\n";
	os << "Account: " << account.name << " - balance: " << account.balance;
	os << "\n----------------------------------------------------------\n";
	return os;
}