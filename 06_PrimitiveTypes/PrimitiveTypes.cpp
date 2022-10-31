#include <iostream>

using namespace std;

void challenge() {
	const double price_per_small_room{ 25 };
	const double price_per_large_room{ 35 };
	const double tax_rate{ 6 };
	const short estimate_validity{ 30 };

	cout << endl << endl;
	cout << "Hello, welcome to Arno's Carpet Cleaning Service";
	cout << endl << endl;
	cout << "How many small rooms would you like cleaned?";

	int small_rooms{ 0 };
	cin >> small_rooms;

	cout << "How many large rooms you like cleaned?";

	int large_rooms{ 0 };
	cin >> large_rooms;

	double cost = (small_rooms * price_per_small_room) + (large_rooms * price_per_large_room);
	double total_estimate = cost + cost * (tax_rate / 100);

	cout << endl << endl;
	cout << "Estimate for carpet cleaning service" << endl;
	cout << "Number of small rooms: " << small_rooms << endl;
	cout << "Number of large rooms: " << large_rooms << endl;
	cout << "Price per small room: $" << price_per_small_room << endl;
	cout << "Price per large room: $" << price_per_large_room << endl;
	cout << "Cost: $" << cost << endl;
	cout << "Taxes: " << tax_rate << "%" << endl;
	cout << "======================================" << endl;
	cout << "Total estimate: $" << total_estimate << endl;
	cout << "This estimate is valid for " << estimate_validity << "days";
	cout << endl << endl;
}

int main()
{
	/****************************************************
	* Character type
	****************************************************/

	char middle_initial{ 'J' };
	cout << "My middle initial is " << middle_initial << endl;

	/****************************************************
	* Integer type
	****************************************************/

	short exam_score{ 55 };
	cout << "My exam score is " << exam_score << endl;

	int countries_represented{ 65 };
	cout << "There were " << countries_represented << " countries represented in my meeting" << endl;

	long people_on_florida{ 2'610'000 };
	cout << "There are about " << people_on_florida << " people on Florida" << endl;

	long long distance_to_alpha_centauri{ 9'461'000'000'000 };
	cout << "The distance to Alpha Centauri is " << distance_to_alpha_centauri << " kilometers" << endl;

	/****************************************************
	* Floating type
	****************************************************/

	float car_payment{ 401.23 };
	cout << "My car payment is " << car_payment << endl;

	double pi{ 3.14159 };
	cout << "Pi is " << pi << endl;

	long double large_amount{ 2.7e120 };
	cout << large_amount << " is a very big number" << endl;

	/****************************************************
	* Boolean type
	****************************************************/

	bool game_over{ false };
	cout << "The value of game over is " << game_over << endl;

	/****************************************************
	* Primitive typoes informations
	****************************************************/

	cout << endl;
	cout << "==========================================" << endl;
	cout << "=========== sizeof information ===========" << endl;
	cout << "==========================================" << endl;

	cout << "char: " << sizeof(char) << " bytes" << endl;
	cout << "short: " << sizeof(short) << " bytes" << endl;
	cout << "int: " << sizeof(int) << " bytes" << endl;
	cout << "unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
	cout << "long: " << sizeof(long) << " bytes" << endl;
	cout << "long long: " << sizeof(long long) << " bytes" << endl;
	cout << "float: " << sizeof(float) << " bytes" << endl;
	cout << "double: " << sizeof(double) << " bytes" << endl;
	cout << "long double: " << sizeof(long double) << " bytes" << endl;

	cout << endl;
	cout << "==========================================" << endl;
	cout << "============= Minimum values =============" << endl;
	cout << "==========================================" << endl;

	cout << "char: " << CHAR_MIN << endl;
	cout << "short: " << SHRT_MIN << endl;
	cout << "int: " << INT_MIN << endl;
	cout << "long: " << LONG_MIN << endl;
	cout << "long long: " << LLONG_MIN << endl;
	cout << "float: " << FLT_MIN << endl;
	cout << "double: " << DBL_MIN << endl;
	cout << "long double: " << LDBL_MIN << endl;

	cout << endl;
	cout << "==========================================" << endl;
	cout << "============= Maximum values =============" << endl;
	cout << "==========================================" << endl;

	cout << "char: " << CHAR_MAX << endl;
	cout << "short: " << SHRT_MAX << endl;
	cout << "unsigned short: " << USHRT_MAX << endl;
	cout << "int: " << INT_MAX << endl;
	cout << "unsigned int: " << UINT_MAX << endl;
	cout << "long: " << LONG_MAX << endl;
	cout << "long long: " << LLONG_MAX << endl;
	cout << "float: " << FLT_MAX << endl;
	cout << "double: " << DBL_MAX << endl;
	cout << "long double: " << LDBL_MAX << endl;

	challenge();

	return 0;
}
