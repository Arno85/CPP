#pragma once
#include "AccountChg.h"
#include <string>

class SavingAccountChg : public AccountChg
{
	friend std::ostream& operator<<(std::ostream& os, const SavingAccountChg& account);

private:
	static constexpr const char* def_name = "Unnamed Saving Account";
	static constexpr const double def_balance = 0.0;
	static constexpr const double def_interest_rate = 0.0;

protected:
	double interest_rate;

public:
	SavingAccountChg(std::string name = def_name, double balance = def_balance, double interest_rate = def_interest_rate);
	bool deposit(double amount);
};

