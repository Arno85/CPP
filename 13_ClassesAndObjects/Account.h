#pragma once
#include <string>

class Account {
private:
	std::string name;
	double balance;

public:
	void set_name(std::string);
	std::string get_name();
	void set_balance(double);
	double get_balance();
	bool deposit(double);
	bool withdraw(double);
};

