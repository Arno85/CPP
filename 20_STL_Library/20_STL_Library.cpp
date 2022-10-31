#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <list>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include "DequeChallenge.h"
#include "ListChallenge.h"
#include <set>
#include <stack>
#include <queue>

/*******************************************************************
* FUNCTION TEMPLATE
*******************************************************************/

template<typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template<typename T1, typename T2>
void display(T1 a, T2 b) {
	std::cout << a << " " << b << std::endl;
}

struct Person {
	std::string name;
	int age;

	bool operator<(const Person& rhs) const {
		return age < rhs.age;
	}
};

/*******************************************************************
* CLASS TEMPLATE
*******************************************************************/

template<typename T>
class Item {
private:
	std::string name;
	T value;
public:
	Item(std::string name, T value) : name{ name }, value{ value } {}

	std::string get_name() const {
		return name;
	}

	T get_value() const {
		return value;
	}
};

template<typename T1, typename T2>
struct My_Pair {
	T1 first;
	T2 second;
};

template<typename T, int N>
class Array {
	int size{ N };
	T values[N]{};

	friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr) {
		os << "[";
		for (const auto& val : arr.values) {
			os << val << " ";
		}
		os << "]" << std::endl;
		return os;
	}
public:
	Array() = default;

	Array(T init_val) {
		fill(init_val);
	}

	void fill(T val) {
		for (auto& item : values) {
			item = val;
		}
	}

	int get_size() const {
		return size;
	}

	T& operator[](int index) {
		return values[index];
	}
};

/*******************************************************************
* MAIN
*******************************************************************/

int main()
{
	std::cout << "\n============================================= STL LIBRARY =========================================================\n";

	/*******************************************************************
	* FUNCTION TEMPLATE
	*******************************************************************/

	std::cout << "\n--------------------------------- FUNCTION TEMPLATE -----------------------------------------\n";

	std::cout << min<int>(2, 3) << std::endl;
	std::cout << min(2, 3) << std::endl;
	std::cout << min('A', 'B') << std::endl;
	std::cout << min(12.5, 9.2) << std::endl;
	std::cout << min(Person{ "Bob", 56 }, Person{ "Jack", 32 }).name << std::endl;

	display(1000, "test");
	display(12.5, true);

	/*******************************************************************
	* CLASS TEMPLATE
	*******************************************************************/

	std::cout << "\n--------------------------------- CLASS TEMPLATE -----------------------------------------\n";

	Item<int> item1{ "Joe", 25 };
	std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

	Item<std::string> item2{ "Jack", "Sparrow" };
	std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

	Item<Item<std::string>> item3{ "Bob", { "C++", "Professor" } };
	std::cout << item3.get_name() << " " << item3.get_value().get_name() << " " << item3.get_value().get_value() << std::endl;

	My_Pair<std::string, int> my_pair1{ "Joe", 25 };
	std::cout << my_pair1.first << " " << my_pair1.second << std::endl;

	My_Pair<char, double> my_pair2{ 'J', 22.5 };
	std::cout << my_pair2.first << " " << my_pair2.second << std::endl;

	Array<int, 5> arr1;
	std::cout << "The size of arr1 is: " << arr1.get_size() << std::endl;
	std::cout << "Values of arr1: " << arr1 << std::endl;

	arr1.fill(10);
	std::cout << "Values of arr1: " << arr1 << std::endl;

	arr1[1] = 1000;
	arr1[3] = 2000;
	std::cout << "Values of arr1: " << arr1 << std::endl;

	Array<std::string, 20> arr2{ "Test" };
	std::cout << "The size of arr2 is: " << arr2.get_size() << std::endl;
	std::cout << "Values of arr2: " << arr2 << std::endl;

	/*******************************************************************
	* STL ITERATORS
	*******************************************************************/

	std::cout << "\n--------------------------------- STL ITERATORS -----------------------------------------\n";

	std::vector<int> nums1{ 1, 2, 3, 4, 5 };
	auto it = nums1.begin();					// or std::vector<int>::iterator it
	std::cout << *it << std::endl;

	it++;
	std::cout << *it << std::endl;

	it += 2;
	std::cout << *it << std::endl;

	it = nums1.end() - 1;
	std::cout << *it << std::endl;

	*it = 1000;
	std::cout << *it << std::endl;

	std::cout << '\n' << std::setw(30) << std::setfill('-') << '\n';

	auto it2 = nums1.cbegin();							// or std::vector<int>::const_iterator it2
	while (it2 != nums1.end()) {
		// *it2 = 0;									// Cannot change the value of what the pointer is pointing to when 
		std::cout << *it2 << "-";
		it2++;
	}

	std::cout << '\n' << std::setw(30) << std::setfill('-') << '\n';

	auto it3 = nums1.rbegin();							// or std::vector<int>::reverse_iterator it3
	while (it3 != nums1.rend()) {
		std::cout << *it3 << "-";
		it3++;
	}

	std::cout << '\n' << std::setw(30) << std::setfill('-') << '\n';

	auto start = nums1.cbegin() + 1;
	auto finish = nums1.end() - 2;
	while (start != finish) {
		std::cout << *start << "-";
		start++;
	}

	/*******************************************************************
	* STL ALGORITHM
	*******************************************************************/

	std::cout << "\n--------------------------------- STL ALGORITHM -----------------------------------------\n";

	std::cout << "\n--------------------------------- FIND -----------------------------------------\n";

	std::vector<int> vecFind{ 1, 2, 3, 4, 5 };
	auto loc = std::find(vecFind.begin(), vecFind.end(), 3);

	if (loc != vecFind.end()) {
		std::cout << "Found " << *loc << " in the list" << std::endl;
	}

	std::cout << "\n--------------------------------- COUNT -----------------------------------------\n";

	std::vector<int> vecCount{ 1, 2, 1, 3, 4, 1, 5, 1 };
	auto count = std::count(vecCount.begin(), vecCount.end(), 1);
	std::cout << "Found " << count << " x1 in the list" << std::endl;

	std::cout << "\n--------------------------------- COUNT IF -----------------------------------------\n";

	std::vector<int> vecCountIf{ 1, 2, 1, 3, 4, 1, 5, 100, 123 };
	auto evens = std::count_if(vecCountIf.begin(), vecCountIf.end(), [](int x) {
		return x % 2 == 0;
		});

	std::cout << "Found " << evens << " even numbers in the list" << std::endl;

	std::cout << "\n--------------------------------- REPLACE -----------------------------------------\n";

	std::vector<int> vecReplace{ 1, 2, 1, 3, 4, 1, 5, 1 };
	std::replace(vecReplace.begin(), vecReplace.end(), 1, 100);
	for (auto x : vecReplace) {
		std::cout << x << ";";
	}

	std::cout << "\n--------------------------------- ALL OF -----------------------------------------\n";

	std::vector<int> vecAllOf{ 1, 2, 1, 3, 4, 1, 5, 1 };
	bool resAllOf = std::all_of(vecAllOf.begin(), vecAllOf.end(), [](int x) { return x > 2; });		// Equivalent to array.every in JS
	std::cout << std::boolalpha << "Are all elements greater than 2? " << resAllOf << std::endl;

	std::cout << "\n--------------------------------- ANY OF -----------------------------------------\n";

	std::vector<int> vecAnyOf{ 1, 2, 1, 3, 4, 1, 5, 1 };
	bool resAnyOf = std::any_of(vecAnyOf.begin(), vecAnyOf.end(), [](int x) { return x > 2; });		// Equivalent to array.some in JS
	std::cout << std::boolalpha << "Are some elements greater than 2? " << resAnyOf << std::endl;

	std::cout << "\n--------------------------------- STRING TRANSFORM -----------------------------------------\n";

	std::string str{ "This is a test" };
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str << std::endl;

	/*******************************************************************
	* SEQUENCE CONTAINER - ARRAY
	* Fix size - contiguous in memory
	*******************************************************************/

	std::cout << "\n--------------------------------- SEQUENCE CONTAINER - ARRAY -----------------------------------------\n";

	std::array<int, 5> intArr{ 1,2,3,4,5 };
	std::cout << intArr.size() << std::endl;
	std::cout << intArr[1] << std::endl;
	std::cout << intArr.at(1) << std::endl;
	std::cout << intArr.front() << std::endl;
	std::cout << intArr.back() << std::endl;

	// arr1.swap(arr2)
	// arr1.empty()
	// arr1.max_size()
	// arr1.data()			// get raw array address

	/*******************************************************************
	* SEQUENCE CONTAINER - VECTOR
	* Dynamic size - contiguous in memory
	* insertion/deletion only at the back
	*******************************************************************/

	std::cout << "\n--------------------------------- SEQUENCE CONTAINER - VECTOR -----------------------------------------\n";

	std::vector<int> intVec{ 1,2,3,4,5 };
	intVec.pop_back();
	intVec.push_back(6);

	auto itVec = std::find(intVec.begin(), intVec.end(), 3);
	intVec.insert(itVec, 10);
	intVec.erase(intVec.begin(), intVec.begin() + 2);

	for (auto v : intVec) {
		std::cout << v << ";";
	}

	std::cout << "\nCapacity :" << intVec.capacity() << std::endl;

	intVec.shrink_to_fit();
	std::cout << "Capacity :" << intVec.capacity() << std::endl;

	intVec.reserve(20);
	std::cout << "Capacity :" << intVec.capacity() << std::endl;

	std::vector<int> intVec2{ 20,25, 30, 35 };
	std::copy(intVec2.begin(), intVec2.end(), std::back_inserter(intVec));
	std::copy_if(intVec2.begin(), intVec2.end(), std::back_inserter(intVec), [](int x) {return x % 2 == 0; });

	for (auto v : intVec) {
		std::cout << v << ";";
	}

	std::vector<int> intVec3{ 1,2,3,4,5};
	std::vector<int> intVec4{ 10,20,30,40,50 };
	std::vector<int> intVec5{};

	std::transform(intVec3.begin(), intVec3.end(), intVec4.begin(), std::back_inserter(intVec5), [](int xVec3, int xVec4) { return xVec3 * xVec4; });

	std::cout << "\n\n";

	for (auto v : intVec5) {
		std::cout << v << ";";
	}

	/*******************************************************************
	* SEQUENCE CONTAINER - DEQUE
	* Dynamic size - NOT contiguous in memory
	* insertion/deletion in front and back
	*******************************************************************/

	std::cout << "\n--------------------------------- SEQUENCE CONTAINER - DEQUE -----------------------------------------\n";

	std::deque<int> intDeque1 {2, 3, 4, 5};
	std::deque<int> intDeque2{ 999, 10,20,30,40,50 };

	intDeque1.push_front(1);
	intDeque2.pop_front();

	deque_challenge();

	/*******************************************************************
	* SEQUENCE CONTAINER - LIST
	* Dynamic size - NOT contiguous in memory
	* no direct element access ([0], .at(0)
	* rapid insertion/deletion anywhere in the list
	* forward_list is only one direction. There are no push_back, pop_back, reverse, ...
	*******************************************************************/

	std::cout << "\n--------------------------------- SEQUENCE CONTAINER - LIST -----------------------------------------\n";

	std::list<int> intList1{ 1, 2, 4, 5 };
	std::list<int> intList2{ 10,20,30,40,50 };

	intList1.push_front(0);
	intList2.push_back(60);

	auto itList = std::find(intList1.begin(), intList1.end(), 4);
	intList1.insert(itList, intList2.begin(), intList2.end());

	intList1.pop_front();

	intList1.resize(20);

	for (auto l : intList1) {
		std::cout << l << ";";
	}

	std::cout << "\n\n" << std::setfill(' ');

	// list_challenge();

	/*******************************************************************
	* ASSOCIATIVE CONTAINER - SET
	* "set" not allows duplicates and is ordered.
	* To order objects (or determine if already in set), we need to override the operator "<" on a property of the object
	* "unordered_set" is a set that not allows duplicates and is unordered.
	* "mutliset" is a set that allows duplicates and is ordered.
	* "unordered_multiset" is a set that allows duplicates and is unordered.
	*******************************************************************/

	std::cout << "\n--------------------------------- ASSOCIATIVE CONTAINER - SET -----------------------------------------\n";

	std::set<int> intSet1{ 1,8,1,3,6,3,5,4,4,4 };

	for (const auto i : intSet1) {
		std::cout << i << ";";
	}
	std::cout << "\n";

	intSet1.insert(7);
	auto result = intSet1.insert(1);														// Won't insert because 1 is already in set
	std::cout << *result.first << " - " << result.second << std::endl;						

	std::cout << "\nIs 2 in the set: " <<  intSet1.count(2) << std::endl;					// 0 or 1 if exist the set
	
	auto itSet = intSet1.find(4);
	if (itSet != intSet1.end()) {
		intSet1.erase(itSet);
	}

	/*******************************************************************
	* ASSOCIATIVE CONTAINER - MAP
	* "map" is a dictionary. Not allows duplicates and is ordered by key.
	* To order objects (or determine if already in set), we need to override the operator "<" on a property of the object
	* * "unordered_map" is a map that not allows duplicates and is unordered.
	* "mutlimap" is a map that allows duplicates and is ordered.
	* "unordered_multimap" is a map that allows duplicates and is unordered.
	*******************************************************************/

	std::cout << "\n--------------------------------- ASSOCIATIVE CONTAINER - MAP -----------------------------------------\n";

	std::map<std::string, int> intMap{ {"d", 4}, {"a", 1}, {"b", 2}};

	intMap.insert(std::pair<std::string, int>("z", 26));		// Insert new key-value
	intMap.insert(std::make_pair("j", 10));						// Insert new key-value
	intMap["c"] = 3;											// Insert new key-value

	intMap["a"] = 10;											// Update value

	auto itMap = intMap.find("b");
	if (itMap != intMap.end()) {
		intMap.erase(itMap);
	}

	intMap.count("a");											// If key exists

	for (const auto x : intMap) {
		std::cout << x.first << " - " << x.second << ";";
	}
	std::cout << "\n";

	/*******************************************************************
	* ADAPTER CONTAINER - STACK
	* LIFO data structure.
	* No iterators, no STL algorytms.
	* build on sequence containers that have push_back => vectors, deque and list. Elements are push at the back, pop at the back.
	* Deque is used by default
	*******************************************************************/

	std::cout << "\n--------------------------------- ADAPTER CONTAINER - STACK -----------------------------------------\n";

	std::stack<int> s1{ { 1, 2, 3, 4, 5 } };		// use deque
	std::stack<int, std::vector<int>> s2{};			// use vector
	std::stack<int, std::list<int>> s3{};			// use list
	std::stack<int, std::deque<int>> s4{};			// use deque

	std::cout << "Top of stack is: " << s1.top() << std::endl;
	s1.push(6);
	std::cout << "Top of stack is: " << s1.top() << std::endl;
	s1.pop();
	std::cout << "Top of stack is: " << s1.top() << std::endl;

	while (!s1.empty()) {
		std::cout << s1.top() << ";";
		s1.pop();
	}

	/*******************************************************************
	* ADAPTER CONTAINER - QUEUE
	* FIFO data structure
	* No iterators, no STL algorythms.
	* build on sequence containers that have push_back and push_front => deque and list. Elements are push at the back, pop at the front.
	* Deque is used by default
	*******************************************************************/

	std::cout << "\n--------------------------------- ADAPTER CONTAINER - QUEUE -----------------------------------------\n";

	std::queue<int> q1{ {1,2,3,4,5} };				// use deque
	std::queue<int, std::list<int>> q2{};			// use list
	std::queue<int, std::deque<int>> q3{};			// use deque

	std::cout << "Front of queue is: " << q1.front() << std::endl;
	std::cout << "Back of queue is: " << q1.back() << std::endl;

	q1.push(6);										// push_back
	q1.pop();										// pop_front

	std::cout << "Front of queue is: " << q1.front() << std::endl;
	std::cout << "Back of queue is: " << q1.back() << std::endl;

	/*******************************************************************
	* ADAPTER CONTAINER - PRIORITY QUEUE
	* heap data structure
	* No iterators, no STL algorythms.
	* build on vectors by default. Elements are push in sorted order, pop in sorted order (greatest int will be inserted in front and pop first).
	*******************************************************************/

	std::cout << "\n--------------------------------- ADAPTER CONTAINER - PRIORITY QUEUE -----------------------------------------\n";

	std::priority_queue<int> pq{};					// use vector
	pq.push(10);
	std::cout << "Top of priority queue is: " << pq.top() << std::endl;
	pq.push(20);
	std::cout << "Top of priority queue is: " << pq.top() << std::endl;
	pq.pop();
	pq.push(3);
	std::cout << "Top of priority queue is: " << pq.top() << std::endl;
	pq.push(4);
	std::cout << "Top of priority queue is: " << pq.top() << std::endl;

	while (!pq.empty()) {
		std::cout << pq.top() << ";";
		pq.pop();
	}

	std::cout << "\n============================================= STL LIBRARY =========================================================\n";

	return 0;
}
