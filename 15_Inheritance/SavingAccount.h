#pragma once
#include "Account.h"

class SavingAccount : public Account
{
	friend std::ostream& operator<<(std::ostream& os, const SavingAccount& account);

protected:
	double interestRate;

public:
	SavingAccount();
	SavingAccount(double balance, std::string name, double ir);
	SavingAccount(const SavingAccount& source);
	~SavingAccount();
	SavingAccount& operator=(const SavingAccount& rhs);
	void deposit(double amount);
};

