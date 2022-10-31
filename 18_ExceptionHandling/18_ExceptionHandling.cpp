#include <iostream>

class DivideByZeroException : public std::exception {
public:
	virtual const char* what() const noexcept {
		return "Sorry, you can't divide by zero";
	}
};

class NegativeValueException : public std::exception {
public:
	virtual const char* what() const noexcept {
		return "Sorry, one of your parameter is negative";
	}
};

double calculate_mpg(int miles, int gallons) {
	if (gallons == 0) {
		throw DivideByZeroException();
	}

	if (miles < 0 || gallons < 0) {
		throw NegativeValueException();
	}

	return static_cast<double>(miles) / gallons;
}

int main()
{
	/*******************************************************************
	* EXCEPTION HANDLING
	*******************************************************************/

	std::cout << "\n--------------------------------- EXCEPTION HANDLING -----------------------------------------\n";

	int miles{};
	int gallons{};
	double miles_per_gallon{};

	std::cout << "Enter the miles driven: ";
	std::cin >> miles;
	std::cout << "Enter the gallons used: ";
	std::cin >> gallons;

	try {
		miles_per_gallon = calculate_mpg(miles, gallons);
		std::cout << "Result: " << miles_per_gallon << std::endl;
	}
	catch (const DivideByZeroException& ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch (const NegativeValueException& ex) {
		std::cerr << ex.what() << std::endl;
	}

	std::cout << "Bye!" << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	return 0;
}
