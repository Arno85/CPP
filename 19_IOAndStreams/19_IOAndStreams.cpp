#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
	std::cout << "\n============================================= I/O & STREAMS =========================================================\n";

	/*******************************************************************
	* STREAM MANIPULATORS - BOOLEAN
	*******************************************************************/

	std::cout << "\n--------------------------------- STREAM MANIPULATORS - BOOLEAN -----------------------------------------\n";

	std::cout << "10 == 10: " << (10 == 10) << std::endl;								// Default behavior: 1 - 0

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::boolalpha;														// Show boolean as true and false
	std::cout << "10 == 10: " << (10 == 10) << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::noboolalpha;														// Default behavior
	std::cout << "10 == 10: " << (10 == 10) << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout.setf(std::ios::boolalpha);												// Other way to set
	std::cout << "10 == 10: " << (10 == 10) << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::resetiosflags(std::ios::boolalpha);								// Reset to default behavior
	std::cout << "10 == 10: " << (10 == 10) << std::endl;

	/*******************************************************************
	* STREAM MANIPULATORS - INTEGER
	*******************************************************************/

	std::cout << "\n--------------------------------- STREAM MANIPULATORS - INTEGER -----------------------------------------\n";

	int num{ 255 };

	std::cout << std::dec << num << std::endl;											// Decimal (Default)
	std::cout << std::hex << num << std::endl;											// Hexadecimal
	std::cout << std::oct << num << std::endl;											// Octal

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::showbase;															// Prefix base (0x for hex and 0 for octal)
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::dec << std::showpos;												// Show a plus sign for positives and minus sign for negatives numbers
	std::cout << num << std::endl;
	std::cout << -num << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout.setf(std::ios::showbase);
	std::cout.setf(std::ios::showpos);
	std::cout.setf(std::ios::uppercase);

	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;

	std::cout << std::resetiosflags(std::ios::basefield);								// Reset base (default decimal)
	std::cout << std::resetiosflags(std::ios::showbase);
	std::cout << std::resetiosflags(std::ios::showpos);
	std::cout << std::resetiosflags(std::ios::uppercase);

	/*******************************************************************
	* STREAM MANIPULATORS - FLOAT
	*******************************************************************/

	std::cout << "\n--------------------------------- STREAM MANIPULATORS - FLOAT -----------------------------------------\n";

	double num2{ 123456789.987654321 };
	double num3{ 123.456 };

	std::cout << num2 << std::endl;														// Default precision is 6 digits
	std::cout << num3 << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::fixed;															// Fixed will set the precisions of 6 digits AFTER the decimal point
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;
	std::cout << std::resetiosflags(std::ios::floatfield);

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::setprecision(9);													// Precision to 9 before and after the decimal point
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::setprecision(3) << std::fixed;									// Fixed but 3 digits after decimal point
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;

	/*******************************************************************
	* STREAM MANIPULATORS - ALIGN AND FILL
	*******************************************************************/

	std::cout << "\n--------------------------------- STREAM MANIPULATORS - ALIGN AND FILL -----------------------------------------\n";

	std::string hello{ "Hello" };
	std::string world{ "World" };

	std::cout << hello << world << std::endl;

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::setw(10) << hello << std::setw(10) << world << std::endl;			// Width of 10 char and the content is align to the right by default

	std::cout << "\n---------------------------------------------------------------------------\n";

	std::cout << std::setfill('*');
	std::cout << std::setw(10) << std::left << hello;
	std::cout << std::setfill('-');
	std::cout << std::setw(15) << world << std::endl;

	/*******************************************************************
	* READ FROM TEXT FILE
	*******************************************************************/

	std::cout << "\n--------------------------------- READ FROM TEXT FILE -----------------------------------------\n";

	std::string name;
	int n;
	double dbl;
	std::string line;
	std::ifstream in_file;
	in_file.open("MyFile.txt");

	if (!in_file.is_open()) {
		std::cerr << "Cannot open file" << std::endl;
		return 1;
	}

	while (!in_file.eof()) {
		std::getline(in_file, line);
		std::cout << line << std::endl;

		in_file >> name >> n >> dbl;
		std::cout
			<< std::setw(10) << name
			<< std::setw(10) << n
			<< std::setw(10) << dbl
			<< std::endl;
	}

	in_file.close();

	/*******************************************************************
	* WRITE TO TEXT FILE
	* truncation mode is the default (replace all)
	*******************************************************************/

	std::cout << "\n--------------------------------- WRITE TO TEXT FILE -----------------------------------------\n";

	std::ofstream out_file{ "output.txt", std::ios::app };				// Appending mode

	if (!out_file) {
		std::cerr << "Error creating file" << std::endl;
		return 1;
	}

	std::string text;
	std::cout << "Enter something you want to write to the file: ";
	std::getline(std::cin, text);

	out_file << text << std::endl;

	out_file.close();

	/*******************************************************************
	* STRING STREAM INPUT
	*******************************************************************/

	std::cout << "\n--------------------------------- STRING STREAM INPUT -----------------------------------------\n";

	int score{};
	double total{};
	std::string fullname{};

	std::string info{ "Jack 87 123.45" };
	std::istringstream iss{ info };

	iss >> fullname >> score >> total;
	std::cout << fullname << "-" << score << "-" << total << std::endl;

	/*******************************************************************
	* STRING STREAM OUTPUT
	*******************************************************************/

	std::cout << "\n--------------------------------- STRING STREAM OUTPUT -----------------------------------------\n";

	std::ostringstream oss{};

	oss << std::setw(10) << fullname << std::setw(10) << score << std::setw(10) << total;
	std::cout << oss.str() << std::endl;

	/*******************************************************************
	* STRING STREAM FOR DATA VALIDATION
	*******************************************************************/

	std::cout << "\n--------------------------------- STRING STREAM FOR DATA VALIDATION -----------------------------------------\n";

	int value{};
	std::string entry{};
	bool done = false;

	do {
		std::cout << "Please enter an integer: ";
		std::cin >> entry;
		std::istringstream validator{ entry };

		if (validator >> value) {
			done = true;
		}
		else {
			std::cout << "Please enter a valid integer" << std::endl;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');					// If user enter "12 Hello there"
	} while (!done);

	std::cout << "You entered the value: " << value << std::endl;

	std::cout << "\n=======================================================================================================\n";

	return 0;
}
