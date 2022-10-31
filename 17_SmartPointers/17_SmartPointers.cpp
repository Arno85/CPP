#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
	int data;
public:
	Test() : data{ 0 } {
		std::cout << "Test constructor (" << data << ")" << std::endl;
	}

	Test(int data) : data{ data } {
		std::cout << "Test constructor (" << data << ")" << std::endl;
	}

	int get_data() {
		return data;
	}

	~Test() {
		std::cout << "Test destructor (" << data << ")" << std::endl;
	}
};

void my_deleter(Test* ptr) {
	std::cout << "[TEST] - Using my custom function deleter" << std::endl;
	delete ptr;
}

/*******************************************************************
* WEAK POINTERS CLASSES
*******************************************************************/

class B;

class A {
private:
	std::shared_ptr<B> b_ptr;
public:
	A() { std::cout << "A constructor" << std::endl; }
	~A() { std::cout << "A destructor" << std::endl; }
	void set_B(std::shared_ptr<B>& b) { b_ptr = b; }
};

class B {
private:
	// std::shared_ptr<A> a_ptr;							// We have a circular reference if we use shared pointer. The destrcutors are never called and we have memory leak.
	std::weak_ptr<A> a_ptr;									// weak pointer solve that.	
public:
	B() { std::cout << "B constructor" << std::endl; }
	~B() { std::cout << "B destructor" << std::endl; }
	void set_A(std::shared_ptr<A>& a) { a_ptr = a; }
};

/*******************************************************************
* Challenge functions prototypes
*******************************************************************/
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>>& vec, int n);
void display(const std::vector<std::shared_ptr<Test>>& vec);

int main()
{
	/*******************************************************************
	* UNIQUE POINTERS
	*******************************************************************/

	std::cout << "\n--------------------------------- UNIQUE POINTERS -----------------------------------------\n";

	//Test* t1 = new Test{ 1000 };
	//delete t1;

	std::unique_ptr<Test> t1{ new Test{1000} };					// First way to initialize

	std::unique_ptr<Test> t2 = std::make_unique<Test>(2000);	// Second way to initialize

	std::unique_ptr<Test> t3;
	// t3 = t1													// You can't assign or copy unique pointers
	t3 = std::move(t1);											// but you can move them.

	if (!t1) {													// Test for nullptr
		std::cout << "t1 has been moved, it's now equal to nullptr" << std::endl;
	}

	std::cout << t3.get() << std::endl;
	t3.reset();													// reset to nullptr
	std::cout << t3.get() << std::endl;

	/*******************************************************************
	* SHARED POINTERS
	*******************************************************************/

	std::cout << "\n--------------------------------- SHARED POINTERS -----------------------------------------\n";

	std::shared_ptr<Test> st1 = std::make_shared<Test>(100);
	std::shared_ptr<Test> st2{ st1 };								// You can copy or assigned shared pointers
	std::shared_ptr<Test> st3;
	st3 = st2;

	std::cout << std::boolalpha;
	std::cout << "st2 == st1: " << (st2 == st1) << std::endl;

	std::cout << st1.use_count() << std::endl;

	/*******************************************************************
	* WEAK POINTERS
	* weak pointers are always created from shared pointers
	*******************************************************************/

	std::cout << "\n--------------------------------- WEAK POINTERS -----------------------------------------\n";

	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();

	a->set_B(b);
	b->set_A(a);

	/*******************************************************************
	* CUSTOM DELETERS
	*******************************************************************/

	std::cout << "\n--------------------------------- CUSTOM DELETERS -----------------------------------------\n";

	std::shared_ptr<Test> test1{ new Test{500}, my_deleter };					// We have to use new, we can't use make shared if we add a custom deleter

	std::shared_ptr<Test> test2c(new Test{ 600 }, [](Test* ptr) {
		std::cout << "[TEST] - Using my custom lambda deleter" << std::endl;	// 2nd way using Lambda expression
		delete ptr;
		});

	/*******************************************************************
	* CHALLENGE
	*******************************************************************/

	std::cout << "\n--------------------------------- CHALLENGE -----------------------------------------\n";

	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter?";
	int num;
	std::cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);

	std::cout << "\n---------------------------------------------------------------------------\n";

	return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int n) {
	int data_point;

	for (int i{ 0 }; i < n; i++) {
		std::cout << "Enter data point [" << i + 1 << "] : ";
		std::cin >> data_point;

		vec.push_back(std::make_shared<Test>(data_point));
	}
}

void display(const std::vector<std::shared_ptr<Test>>& vec) {
	std::cout << "\nDisplaying vector data\n";
	std::cout << "===============================\n";

	for (const auto& shared_ptr : vec) {
		std::cout << shared_ptr->get_data() << std::endl;
	}

	std::cout << "===============================\n";
}