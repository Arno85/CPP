#include <iostream>
#include <vector>

using namespace std;

void challenge() {
	vector<int> vector1{};
	vector<int> vector2{};

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "====== Vector 1 =======" << endl;
	cout << "The first element of vector1 is: " << vector1.at(0) << endl;
	cout << "The second element of vector1 is: " << vector1.at(1) << endl;
	cout << "The size of vector1 is: " << vector1.size() << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << "====== Vector 2 =======" << endl;
	cout << "The first element of vector2 is: " << vector2.at(0) << endl;
	cout << "The second element of vector2 is: " << vector2.at(1) << endl;
	cout << "The size of vector2 is: " << vector2.size() << endl;

	vector<vector<int>> vector_2d{};

	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	cout << "====== Vector 2D before =======" << endl;
	cout << "The first index of the first element of vector_2d is: " << vector_2d.at(0).at(0) << endl;
	cout << "The second index of the first element of vector1 is: " << vector_2d.at(0).at(1) << endl;
	cout << "The first index of the second element of vector2 is: " << vector_2d.at(1).at(0) << endl;
	cout << "The second index of the second element of vector2 is: " << vector_2d.at(1).at(1) << endl;

	vector1.at(0) = 1000;

	cout << "====== Vector 2D after =======" << endl;
	cout << "The first index of the first element of vector_2d is: " << vector_2d.at(0).at(0) << endl;
	cout << "The second index of the first element of vector1 is: " << vector_2d.at(0).at(1) << endl;
	cout << "The first index of the second element of vector2 is: " << vector_2d.at(1).at(0) << endl;
	cout << "The second index of the second element of vector2 is: " << vector_2d.at(1).at(1) << endl;
	cout << "The first element of vector1 is: " << vector1.at(0) << endl;
}

int main()
{
	/****************************************************
	* Arrays
	****************************************************/

	char vowelsArr[]{ 'a', 'e', 'i', 'o', 'u', 'y' };

	cout << endl << "======== Arrays ========" << endl;
	cout << "The first vowel is : " << vowelsArr[0] << endl;
	cout << "The last vowel is : " << vowelsArr[5] << endl;

	/*
	* IMPORTANT:
	* C++ arrays are efficient because their names represents the location in memory of the first element of the array (index 0).
	* To get other indexes, it will perform a calculation from the first index + the offset.
	* So they are no "out of bound" in C++. If the index is out of bound,it will still perform the calculation and give what is stored at this location in memory.
	*/

	cout << "The vowel at the out of bound index is: " << vowelsArr[56] << endl;


	/*
	* IMPORTANT:
	* Initialize arrays to avoid to have garbage memory values
	*/

	int uninitialized_array[5]; // Not initialized
	int initialized_array[5]{}; // Initialized


	/****************************************************
	* Multidimensional Arrays
	****************************************************/

	int movie_ratingArr[3][4]
	{
		{0, 2, 5, 1},
		{1, 4, 1, 0},
		{0, 4, 0, 1},
	};

	/****************************************************
	* Vectors
	****************************************************/

	vector<char> vowelsVec{ 'a', 'e', 'i', 'o', 'u' };

	cout << endl << "======== Vectors ========" << endl;
	cout << "The first vowel is : " << vowelsVec[0] << endl;
	cout << "The last vowel is : " << vowelsVec.at(4) << endl;

	// cout << "The last vowel is : " << vowelsVec.at(5) << endl; -- Will throw an exception out of range

	vowelsVec.push_back('y'); // append

	cout << "There are " << vowelsVec.size() << " vowels in the alphabet" << endl; // length/count

	/****************************************************
	* Multidimensional Vectors
	****************************************************/

	vector<vector<int>> movie_ratingVec
	{
		{0, 2, 5, 1},
		{1, 4, 1, 0},
		{0, 4, 0, 1},
	};

	challenge();

	return 0;
}