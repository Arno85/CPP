#include <iostream>
#include <vector>

using namespace std;


void double_data(int* int_ptr) {
	*int_ptr *= 2;
}

int* largest_int(int* int_ptr1, int* int_ptr2) {
	if (*int_ptr1 > *int_ptr2) {
		return int_ptr1;
	}

	return int_ptr2;
}

int* apply_all(const int* const arr1, const size_t arr1_length, const int* const arr2, const size_t arr2_length) {
	int* arr3 = new int[arr1_length * arr2_length];
	int offset = 0;

	for (size_t i{ 0 }; i < arr2_length; i++) {
		for (size_t j{ 0 }; j < arr1_length; j++) {
			arr3[offset] = arr2[i] * arr1[j];
			offset++;
		}
	}

	return arr3;
}

void print_array(const int *const arr, size_t arr_length) {
	for (size_t i{ 0 }; i < arr_length; i++) {
		cout << arr[i] << ", ";
	}
}

int main()
{
	/********************************************************************************
	* Pointers
	* !!! Always initialize pointers !!!
	********************************************************************************/

	cout << "\n----------------- POINTERS --------------------\n";

	// Variables
	int num{ 10 };
	cout << "Value of num is: " << num << endl;             // Print value of num
	cout << "sizeof of num is: " << sizeof num << endl;     // Print memory size in bytes of num
	cout << "Address of num is: " << &num << endl << endl;  // Print memory address of num

	// Pointers
	int* p{ nullptr };

	cout << "Value of p is: " << p << endl;					// Print value of p (nullptr - which means point to nowhere)
	cout << "sizeof of p is: " << sizeof p << endl;			// Print memory size in bytes of a pointer (same for all types)
	cout << "Address of p is: " << &p << endl;				// Print memory address of p

	p = &num;

	cout << "Value of p is: " << p << endl;					// Print value of p (memory address of num)
	cout << "sizeof of p is: " << sizeof p << endl;			// Print memory size in bytes of a pointer (same for all types)
	cout << "Address of p is: " << &p << endl;				// Print memory address of p

	/********************************************************************************
	* Dereferencing a pointer
	********************************************************************************/

	cout << "\n----------------- DEFERENCING POINTERS --------------------\n";

	int score{ 100 };
	int* score_ptr{ &score };

	cout << *score_ptr << endl;								// * Dereference the pointer and give what it's pointing to (value of score)

	*score_ptr = 200;

	cout << *score_ptr << endl;
	cout << score << endl;

	/********************************************************************************
	* Dynamic Memory Allocation
	* Declare variable on the heap (at runtime) that the pointer is referencing to
	* The variable has no name, there's no way to acces it directly. If we lose the pointer we have a memory leak
	********************************************************************************/

	cout << "\n----------------- DYNAMIC MEMORY ALLOCATION --------------------\n";

	int* int_ptr{ nullptr };
	int_ptr = new int;

	cout << int_ptr << endl;								// Printy address of new int on the heap
	cout << *int_ptr << endl;								// Print value of new int (garbage data)

	*int_ptr = 100;

	cout << *int_ptr << endl;								// Print value of new int (initialized - 100)

	delete int_ptr;											// Free the allocated storage

	cout << "\n----------------- DYNAMIC MEMORY ALLOCATION (arrays) --------------------\n";

	double* temperature_ptr{ nullptr };
	size_t size{ 0 };

	cout << "How many temperatures?";
	cin >> size;

	temperature_ptr = new double[size];

	cout << temperature_ptr << endl;

	// temperature_ptr = nullptr							// If we reassigne the pointer, we lose the only access to the variable on the heap. We have a memory leak.

	delete[] temperature_ptr;

	/********************************************************************************
	* RELATIONSHIP BETWEEN ARRAYS AND POINTERS
	********************************************************************************/

	cout << "\n----------------- RELATIONSHIP BETWEEN ARRAYS AND POINTERS --------------------\n";

	int scores[]{ 100, 95, 89 };
	int* scores_ptr{ scores };													// No need to put & before the variable bnecause arrays are already an address of the first index

	cout << "Scores (1st index address): " << scores << endl;					// Print the address of the first index
	cout << "Scores (2nd index address): " << scores + 1 << endl;				// Print the address of the second index
	cout << "Scores (3th index address): " << scores + 2 << endl;				// Print the address of the third index

	cout << "\n----------------- Array subscript notation --------------------\n";
	cout << scores[0] << endl;
	cout << scores[1] << endl;
	cout << scores[2] << endl;

	cout << "\n----------------- Pointer subscript notation --------------------\n";
	cout << scores_ptr[0] << endl;
	cout << scores_ptr[1] << endl;
	cout << scores_ptr[2] << endl;

	cout << "\n----------------- Array offset notation --------------------\n";
	cout << *scores << endl;
	cout << *(scores + 1) << endl;
	cout << *(scores + 2) << endl;

	cout << "\n----------------- Pointer offset notation --------------------\n";
	cout << *scores_ptr << endl;
	cout << *(scores_ptr + 1) << endl;
	cout << *(scores_ptr + 2) << endl;

	/********************************************************************************
	* POINTER ARYTHMETIC
	********************************************************************************/

	cout << "\n----------------- POINTER ARYTHMETIC --------------------\n";

	int grade_scores[]{ 100, 95, 89, 68, -1 };
	int* grade_scores_ptr{ grade_scores };

	while (*grade_scores_ptr != -1) {
		cout << *grade_scores_ptr << ", ";
		grade_scores_ptr++;

		// OR cout << *grade_scores_ptr++ << ", ";
	}

	/********************************************************************************
	* CONST AND POINTERS
	********************************************************************************/

	//------ Pointers to constant

	int p2c_high_score{ 100 };
	int p2c_low_score{ 65 };
	const int* p2c_score_ptr{ &p2c_high_score };

	// *p2c_score_ptr = 86;									// Error! pointer to constants cannot change the value of the variable that we are referencing.
	p2c_score_ptr = &p2c_low_score;							// OK! We can however reassign the pointer to another variable.

	//------- constant pointer to constant

	int cp2c_high_score{ 100 };
	int cp2c_low_score{ 65 };
	const int* const cp2c_score_ptr{ &cp2c_high_score };

	// *cp2c_score_ptr = 86;								// Error!
	// cp2c_score_ptr = &cp2c_low_score;					// Error!

	/********************************************************************************
	* PASS POINTERS TO FUNCTIONS
	********************************************************************************/

	cout << "\n----------------- PASS POINTERS TO FUNCTIONS --------------------\n";

	int val{ 10 };
	int* val_ptr{ nullptr };

	cout << val << endl;
	double_data(&val);
	cout << val << endl;

	val_ptr = &val;
	double_data(val_ptr);
	cout << val << endl;

	/********************************************************************************
	* RETURNING POINTERS FROM FUNCTIONS
	********************************************************************************/

	cout << "\n----------------- RETURNING POINTERS FROM FUNCTIONS --------------------\n";

	int a{ 100 };
	int b{ 200 };

	int* largest_ptr{ nullptr };

	largest_ptr = largest_int(&a, &b);

	cout << *largest_ptr << endl;

	/********************************************************************************
	* REFERENCES
	********************************************************************************/

	cout << "\n----------------- REFERENCES --------------------\n";

	int number{ 100 };
	int& ref{ number };

	cout << number << " - " << &number << endl;
	cout << ref << " - " << &ref << endl;

	cout << "\n-------------------------------------\n";

	number = 200;
	cout << number << endl;
	cout << ref << endl;

	cout << "\n-------------------------------------\n";

	ref = 300;
	cout << number << endl;
	cout << ref << endl;

	cout << "\n-------------------------------------\n";

	vector<string> stooges{ "Larry", "Curly", "Moe" };

	for (auto stooge : stooges) {
		stooge = "Funny";
	}

	for (auto stooge : stooges) {
		cout << stooge << ", ";
	}

	cout << "\n-------------------------------------\n";

	for (auto& stooge : stooges) {
		stooge = "Funny";
	}

	for (auto const& stooge : stooges) {
		cout << stooge << ", ";
	}

	/********************************************************************************
	* CHALLENGE
	********************************************************************************/

	cout << "\n----------------- CHALLENGE --------------------\n";

	const size_t arr1_length{ 5 };
	const size_t arr2_length{ 3 };

	int arr1[]{ 1,2,3,4,5 };
	int arr2[]{ 10,20,30 };

	cout << "\nArray 1: ";
	print_array(arr1, arr1_length);

	cout << "\nArray 2: ";
	print_array(arr2, arr2_length);

	int* results = apply_all(arr1, 5, arr2, 3);

	cout << "\nResults: ";
	print_array(results, arr1_length * arr2_length);

	delete[] results;

	cout << "\n----------------- CHALLENGE --------------------\n";

	return 0;
}
