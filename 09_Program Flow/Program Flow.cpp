#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void challenge() {
	char selection;
	vector<int> numbers{};

	do {
		cout << endl << endl << "--------------------------------" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "F - Find a number" << endl;
		cout << "C - Clear the numbers" << endl;
		cout << "Q - Quit" << endl << endl;
		cout << "Enter your choice: ";

		cin >> selection;

		cout << endl;

		if (selection == 'p' || selection == 'P') {
			if (numbers.size() == 0) {
				cout << "[] - the list is empty";
			}
			else {
				cout << "[ ";
				for (auto num : numbers) {
					cout << num << " ";
				}
				cout << "]";
			}
		}
		else if (selection == 'a' || selection == 'A') {
			int new_number;
			bool alreadyExist{ false };

			cout << "Type your number: ";
			cin >> new_number;

			for (auto num : numbers) {
				if (num == new_number) {
					alreadyExist = true;
				}
			}

			if (alreadyExist) {
				cout << "The number " << new_number << " has already been added to the list";
			}
			else {
				numbers.push_back(new_number);
				cout << new_number << " added";
			}
		}
		else if (selection == 'm' || selection == 'M') {
			if (numbers.size() == 0) {
				cout << "Unable to calculate the mean - no data";
			}
			else {
				double total{ 0.0 };

				for (auto num : numbers) {
					total += num;
				}

				cout << fixed << setprecision(2);
				cout << "The mean is: " << total / numbers.size();
			}
		}
		else if (selection == 's' || selection == 'S') {
			if (numbers.size() == 0) {
				cout << "Unable to determine the smallest number - no data";
			}
			else {
				int smallest_number{ numbers.at(0) };

				for (auto num : numbers) {
					if (num < smallest_number) {
						smallest_number = num;
					}
				}

				cout << "The smallest number is: " << smallest_number;
			}
		}
		else if (selection == 'l' || selection == 'L') {
			if (numbers.size() == 0) {
				cout << "Unable to determine the largest number - no data";
			}
			else {
				int largest_number{ numbers.at(0) };

				for (auto num : numbers) {
					if (num > largest_number) {
						largest_number = num;
					}
				}

				cout << "The largest number is: " << largest_number;
			}
		}
		else if (selection == 'f' || selection == 'F') {
			if (numbers.size() == 0) {
				cout << "Unable to do a search - no data";
			}
			else {
				bool found{ false };
				int search_number{ 0 };

				cout << "Type your number: ";
				cin >> search_number;

				for (auto num : numbers) {
					if (num == search_number) {
						found = true;
						break;
					}
				}

				cout << search_number << (found ? " was found" : " was not found");
			}
		}
		else if (selection == 'c' || selection == 'C') {
			numbers.clear();

			cout << "The list is cleared";
		}
		else if (selection == 'q' || selection == 'Q') {
			cout << "Goodbye..." << endl;
		}
		else {
			cout << "Unknown selection, please try again";
		}

	} while (selection != 'q' && selection != 'Q');
}

int main()
{
	/****************************************************
	* If, If/Else, Else if, ternary, switch, for loop
	****************************************************/

	// Same as other languages

	/****************************************************
	* Range based for loop (C++11 and more)
	****************************************************/

	// "for in" is "for :"
	// "auto" will determine automatically the type of the variable (can be replaced by the type explicitally).

	vector<int> scores{ 10, 20, 30 };

	for (auto score : scores) {
		cout << score << endl;
	}

	challenge();

	return 0;
}

