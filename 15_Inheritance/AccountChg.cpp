#include "AccountChg.h"

AccountChg::AccountChg(std::string name, double balance): name{name}, balance{balance} {}

bool AccountChg::deposit(double amount) {
	if (amount < 0) {
		return false;
	}

	balance += amount;
	return true;
}

bool AccountChg::withdraw(double amount) {
	if (balance - amount <= 0) {
		return false;
	}

	balance -= amount;
	return true;
}

std::ostream& operator<<(std::ostream& os, const AccountChg& account) {
	os << "[Account: " << account.name << " - $" << account.balance << "]";
	return os;
}