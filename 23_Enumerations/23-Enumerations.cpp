#include <iostream>

enum Direction { North, South, East, West };

std::ostream& operator<<(std::ostream& os, Direction& direction) {
	switch (direction) {
	case North: os << "North"; break;
	case South: os << "South"; break;
	case East: os << "East"; break;
	case West: os << "West"; break;
	}

	return os;
}

enum State { Engine_Failure, Inclement_Weather, Nominal, Unknown };
enum Sequence { Abort, Hold, Launch };

std::istream& operator>>(std::istream& is, State& state) {
	int user_input{};
	is >> user_input;

	switch (user_input) {
	case Engine_Failure:
	case Inclement_Weather:
	case Nominal:
	case Unknown:
		state = State(user_input);
		break;
	default:
		std::cout << "User input invalid" << std::endl;
		state = Unknown;
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, Sequence& sequence) {
	switch (sequence) {
	case Abort: os << "Abort"; break;
	case Hold: os << "Hold"; break;
	case Launch: os << "Launch"; break;
	}

	return os;
}

void initiate(Sequence sequence) {
	std::cout << "Initiate " << sequence << " sequence!" << std::endl;
}

enum class Grocery_Item {Milk, Bread, Apple, Orange};
enum class Favorite_Food { Pizza, Bread, Apple };

int main()
{
	std::cout << "\n========================================== ENUMERATIONS =====================================================\n";

	/*******************************************************************
	* UNSCOPED ENUMERATIONS
	*******************************************************************/

	std::cout << "\n------------------------------------------ UNSCOPED ENUMERATIONS ------------------------------------------------\n";

	Direction direction1{ South };
	std::cout << direction1 << std::endl;

	State state;
	std::cout << "Launch state: ";
	std::cin >> state;

	switch (state) {
	case Engine_Failure:
	case Unknown:
		initiate(Abort);
		break;
	case Inclement_Weather:
		initiate(Hold);
		break;
	case Nominal:
		initiate(Launch);
		break;
	}

	/*******************************************************************
	* SCOPED ENUMERATIONS
	* enum class My_Enum {}
	* Allows to use same key in different enums
	*******************************************************************/

	std::cout << "\n------------------------------------------ SCOPED ENUMERATIONS ------------------------------------------------\n";

	Grocery_Item gi{ Grocery_Item::Bread };
	Favorite_Food ff{ Favorite_Food::Bread };

	std::cout << static_cast<int>(gi) << std::endl;
	std::cout << static_cast<int>(ff) << std::endl;

	std::cout << "\n========================================== ENUMERATIONS =====================================================\n";
	return 0;
}
