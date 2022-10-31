#include "SavingAccountChg.h"

SavingAccountChg::SavingAccountChg(std::string name, double balance, double interest_rate) : AccountChg(name, balance), interest_rate{ interest_rate } {}

bool SavingAccountChg::deposit(double amount) {
	amount += amount * (interest_rate / 100);
	return AccountChg::deposit(amount);
}

std::ostream& operator<<(std::ostream& os, const SavingAccountChg& account) {
	os << "[Saving Account: " << account.name << " - $" << account.balance << " - " << account.interest_rate <<"%]";
	return os;
}