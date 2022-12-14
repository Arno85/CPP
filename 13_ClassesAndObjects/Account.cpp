#include "Account.h"

void Account::set_name(std::string n) {
	name = n;
}

std::string Account::get_name() {
	return name;
}

void Account::set_balance(double amount) {
	balance = amount;
}

double Account::get_balance() {
	return balance;
}

bool Account::deposit(double amount) {
	balance += amount;
	return true;
}

bool Account::withdraw(double amount) {
	if (amount > balance) {
		return false;
	}

	balance -= amount;
	return true;
}