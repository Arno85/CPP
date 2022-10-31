#pragma once
#include <string>

class Account
{
	friend std::ostream& operator<<(std::ostream& os, const Account& account);
protected:
	double balance;
	std::string name;
public:
	Account();
	Account(double b, std::string n);
	Account(const Account& source);
	~Account();
	Account& operator=(const Account& rhs);
	void deposit(double amount);
	void withdraw(double amount);
};

