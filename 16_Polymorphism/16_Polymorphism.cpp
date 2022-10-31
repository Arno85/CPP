#include <iostream>

class Base {
public:
	void say_hello() const {
		std::cout << "Hello from Base class" << std::endl;
	}

	virtual void say_hello_with_polymorphism() const {
		std::cout << "Hello from Base class" << std::endl;
	}

	virtual void say_hello_not_overridable() const final {
		std::cout << "Hello from Base class" << std::endl;
	}

	virtual ~Base() {
		std::cout << "Destructor from Base class" << std::endl;
	}
};

class Derived final : public Base {
public:
	void say_hello() const {
		std::cout << "Hello from Derived class" << std::endl;
	}

	virtual void say_hello_with_polymorphism() const override {
		std::cout << "Hello from Derived class" << std::endl;
	}

	virtual ~Derived() {
		std::cout << "Destructor from Derived class" << std::endl;
	}
};

void greetings(const Base& obj) {
	std::cout << "Greetings - ";
	obj.say_hello();
}

void greetings_with_polymorphism(const Base& obj) {
	std::cout << "Greetings with Polymorphism - ";
	obj.say_hello_with_polymorphism();
}

class Shape {						// abstract class
public:
	virtual void draw() = 0;		// Pure virtual function
	virtual void rotate() = 0;		// Pure virtual function
	virtual ~Shape() {
		std::cout << "Destructor from Shape class" << std::endl;
	};
};

class ClosedShape : public Shape {	// abstract class
public: 
	virtual ~ClosedShape() {
		std::cout << "Destructor from ClosedShape class" << std::endl;
	}
};

class Circle : public ClosedShape {
public:
	virtual void draw() override {
		std::cout << "Draw circle" << std::endl;
	}

	virtual void rotate() override {
		std::cout << "Rotate circle" << std::endl;
	}

	virtual ~Circle() {
		std::cout << "Destructor from Circle class" << std::endl;
	}
};

int main()
{
	/*******************************************************************
	* POLYMORPHISM
	* Overriden methods are statically bound to the object type at compile time
	* With the use of the "virtual" keyword, those methods will be bound at runtime (bound dynamically).
	* It's not necessary to add the "virtual" keyword to the derived methods, they're will be virtual by default according to the parent, BUT it's a good practice to do so.
	* If a class has virtual methods, ALWAYS provide a virtual Destructor. If base class has a virtual destructor, all the derived class have to get one also.
	* The keyword "override" ensure that the overriden method is excatly the same as the original. The should put this keyword EVERYTIME we override a method.
	* The keyword "final", at a class level, ensure that the class cannot be derived, and at a method level, ensure that the method cannot be overriden.
	*******************************************************************/

	std::cout << "\n--------------------------------- POLYMORPHISM -----------------------------------------\n";

	Base b;
	b.say_hello();							// Say Hello from Base Class

	Derived d;
	d.say_hello();							// Say Hello from Derived Class

	greetings(d);							// Say Hello from Base Class
	greetings_with_polymorphism(d);			// Say Hello from Derived Class

	Base* ptr = new Derived();
	ptr->say_hello();						// Say Hello from Base Class
	ptr->say_hello_with_polymorphism();		// Say Hello from Derived Class

	Base* bptr = new Base();
	Base* dptr = new Derived();

	bptr->say_hello_with_polymorphism();	// Say Hello from Base Class
	dptr->say_hello_with_polymorphism();	// Say Hello from Derived Class

	delete bptr;
	delete dptr;							// If The Destructor is not virtual, it<s the Destructor from Base class that will be called

	/*******************************************************************
	* ABSTRACT CLASSES
	* By declaring pure virtual function (=0) in a class make it abstract.
	* If all the pure functions are not overriden in the derived class, it will make it abstract too.
	* There's no Interface in C++. Abstract classes with only pure functions are used as Interfaces. Often prefixed with "I_".
	*******************************************************************/

	std::cout << "\n--------------------------------- ABSTRACT CLASSES -----------------------------------------\n";

	Shape* s = new Circle();
	s->draw();
	s->rotate();

	delete s;

	std::cout << "\n---------------------------------------------------------------------------\n";

    return 0;
}
