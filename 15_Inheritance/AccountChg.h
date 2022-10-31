#pragma once
#include <iostream>
#include <string>

class AccountChg
{
	friend std::ostream& operator<<(std::ostream& os, const AccountChg& account);

private :
	static constexpr const char* def_name = "Unnamed Account";
	static constexpr const double def_balance = 0.0;

protected:
	std::string name;
	double balance;

public:
	AccountChg(std::string name = def_name, double balance = def_balance);
	bool deposit(double amount);
	bool withdraw(double amount);
};

