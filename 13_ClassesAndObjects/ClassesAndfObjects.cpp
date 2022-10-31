#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
#include "Movies.h"

using namespace std;

void challenge();

class Player {
private:
	string name;
	int health;
	int xp;

public:
	Player(string n, int h, int x) {
		name = n;
		health = h;
		xp = x;
	}

	void talk(string text_to_say) {
		cout << name << " says " << text_to_say << endl;
	}

	bool is_dead() {
		if (health <= 0) {
			return true;
		}

		return false;
	};
};

class PlayerInitList {
private:
	string name;
	int health;
	int xp;

public:
	PlayerInitList(string name_val, int health_val, int xp_val)
		: name{ name_val }, health{ health_val }, xp{ xp_val } {}

	PlayerInitList(string name_val)
		: PlayerInitList(name_val, 100, 0) {}

	PlayerInitList()
		: PlayerInitList("None", 100, 0) {}

	// Copy constructor
	PlayerInitList(const PlayerInitList &src)
		: PlayerInitList(src.name, src.health, src.xp) {}


	void talk(string text_to_say) {
		cout << name << " says " << text_to_say << endl;
	}

	bool is_dead() {
		if (health <= 0) {
			return true;
		}

		return false;
	};
};

class PlayerCopyCtor {
private:
	string name;
	int health;
	int xp;

public:
	PlayerCopyCtor(string name_val = "None", int health_val = 100, int xp_val = 0)
		: name{ name_val }, health{ health_val }, xp{ xp_val } {
		cout << "Constructor for: " << name << endl;
	}

	// Copy constructor
	PlayerCopyCtor(const PlayerCopyCtor& source)
		: name{ source.name }, health{ source.health }, xp{ source.xp } {
		cout << "Copy constructor - made copy of: " << source.name << endl;
	}

	string getName() { return name; }
	int getHealth() { return health; }
	int getXp() { return xp; }

	~PlayerCopyCtor() {
		cout << "Destructor called for: " << name << endl;
	}
};

class Deep {
private:
	int* data;

public:
	Deep(int val) {
		data = new int;
		*data = val;
		display_data();
	}

	Deep(const Deep& source) {
		data = new int;
		*data = *source.data;
		display_data();
	}
	
	~Deep() {
		delete data;
	}

	void set_data(int val) {
		*data = val;
	}

	void display_data() {	
		cout << "Address: " << data << " - Value: " << *data << endl;
	}
};

class Move {
private: 
	int* data;

public:
	// Constructor
	Move(int d) {
		data = new int;
		*data = d;
		cout << "Constructor for: " << data << " - " << * data << endl;
	}

	// Copy Constructor
	Move(const Move& source) {
		data = new int;
		*data = *source.data;
		cout << "Copy constructor - deep copy for: " << data << " - " << *data << endl;
	}

	// Move Constructor
	Move(Move&& source) noexcept : data(source.data) {
		source.data = nullptr;
		cout << "Move constructor - moving resource: " << data << " - " << *data << endl;
	}

	// Destructor
	~Move() {
		if (data != nullptr) {
			cout << "Destructor freeing data for: " << data << " - " << *data << endl;
		}
		else {
			cout << "Destructor freeing data for: nullptr" << endl;
		}
		
		delete data;
	}

	// The const suffix tell the compiler that this method do not modify the data
	int get_data() const {
		return *data;
	}

	void set_data(int d) {
		*data = d;
	}
};

class ConstObject {
private:
	int data;
public: 

	ConstObject(int d): data{d} { }

	int get_data() const {
		// data = 500;			// Will throw an error because of the const attribute
		return data;
	}

	void set_data(int data) {
		this->data = data;
	}
};

class Static {
private:
	static int num_instanciations;
	int data;

public:

	Static(int d) : data{ d } {
		num_instanciations++;
	}

	~Static() {
		num_instanciations--;
	}

	static int get_num_instanciations() {
		return num_instanciations;
	}

	int get_data() const {
		return data;
	}
};

int Static::num_instanciations = 0;

struct Person {
	string name;
	string get_name() {
		return name;
	}
};

class Friend {
private:
	string name;
	friend void display_friend_name(Friend& f);

public: 
	Friend(string n): name{n} {}
};

void display_friend_name(Friend& f) {
	cout << "Name: " << f.name << endl;		// No need to set a public method to get name with friends
}

void display_player(PlayerCopyCtor p) {
	cout << "Name: " << p.getName() << endl;
	cout << "Health: " << p.getHealth() << endl;
	cout << "XP: " << p.getXp() << endl;
}

void display_deep(Deep d) {}

int main()
{
	Player arno{ "Arno", 100, 1 };
	arno.talk("I'm gonna put some dirt in your eyes");

	Player* enemy = new Player("Bully Maguire", 100, 15);
	enemy->talk("That's a cute outfit! Did your husband give it to you?");

	delete enemy;

	Account arno_account;
	arno_account.set_name("Arno's account");
	arno_account.set_balance(0);
	arno_account.deposit(1000);
	cout << arno_account.get_name() << " - $" << (arno_account.get_balance()) << endl;
	cout << (arno_account.withdraw(500) ? "Withdrawal OK" : "No sufficient funds") << endl;
	cout << arno_account.get_name() << " - $" << (arno_account.get_balance()) << endl;
	cout << (arno_account.withdraw(1200) ? "Withdrawal OK" : "No sufficient funds") << endl;

	/********************************************************************************
	* CONSTRUCTOR INITIALIZATION LIST AND DELEGATING CONSTRUCTOR
	* delegate to another constructor only works in initialization list, not in the body of the constructor.
	********************************************************************************/

	cout << "\n----------------- CONSTRUCTOR INITIALIZATION LIST AND DELEGATING CONSTRUCTOR --------------------\n";

	PlayerInitList playerInitList{ "Player", 100, 50 };
	playerInitList.talk("Look at little Goblin Junior. Gonna cry?");

	/********************************************************************************
	* COPY CONSTRUCTOR
	* !!! Default is shallow copy !!!
	* Always use deep copy when object has raw pointers properties
	********************************************************************************/

	cout << "\n----------------- COPY CONSTRUCTOR --------------------\n";

	PlayerCopyCtor playerCopyctor{};						// Orginal object

	PlayerCopyCtor new_playerCopyctor{playerCopyctor};		// Copy by creating a new object

	display_player(playerCopyctor);							// Another copy by passing argument by value

	// 3 differents objects - Destructor is called 3 times.

	cout << "\n----------------- DEEP COPY CONSTRUCTOR --------------------\n";

	Deep deep (100);
	display_deep(deep);

	Deep deep2(deep);

	deep.set_data(1000);

	deep.display_data();
	deep2.display_data();

	/********************************************************************************
	* MOVE CONSTRUCTOR
	********************************************************************************/

	cout << "\n----------------- MOVE CONSTRUCTOR --------------------\n";

	vector<Move> vec;

	vec.push_back(Move(10));
	vec.push_back(Move(20));
	vec.push_back(Move(30));
	vec.push_back(Move(40));
	vec.push_back(Move(50));
	vec.push_back(Move(60));
	vec.push_back(Move(70));
	vec.push_back(Move(80));

	cout << "VECTOR[0]: " << vec[0].get_data() << endl;

	/********************************************************************************
	* CONST OBJECT
	* add const after the method name tell the compiler that this method won't modify anything
	* Rule of thumb is, all getter should be a const
	********************************************************************************/

	cout << "\n----------------- CONST OBJECT --------------------\n";
	ConstObject constobject1{100};
	constobject1.set_data(1000);
	cout << constobject1.get_data() << endl;

	const ConstObject constobject2{ 500 };
	// constobject2.set_data(1000);				// Will throw an error
	cout << constobject2.get_data() << endl;	// OK

	/********************************************************************************
	* STATIC MEMBERS
	********************************************************************************/

	cout << "\n----------------- STATIC MEMBERS --------------------\n";
	Static static1{ 100 };
	cout << static1.get_num_instanciations() << endl;

	Static static2{ 500 };
	cout << static1.get_num_instanciations() << endl;

	{
		Static static3{ 1000 };
		cout << static1.get_num_instanciations() << endl;
	}
	cout << static1.get_num_instanciations() << endl;

	/********************************************************************************
	* STRUCT
	* Struct in C++ are almost the same as classes. The only difference is the members are public by default. In classes they are private by default.
	* The Guideline is we use struct if we have passive data with public access without methods.
	********************************************************************************/

	cout << "\n----------------- STRUCT --------------------\n";

	Person person;
	person.name = "Arno";
	cout << person.get_name() << endl;

	/********************************************************************************
	* FRIEND OF A CLASS
	* friends can access public or private members
	* Friendship must be granted, not taken. Delared explicitly with the friend keyword.
	* Friendship is not symetric. if A is friend of B, B is not a friend of A.
	* Frienship is not transitive. if A is friend of B and B is a friend of C, A is not a friend of C.
	********************************************************************************/

	cout << "\n----------------- FRIEND OF A CLASS --------------------\n";

	Friend frd{"Noar"};
	display_friend_name(frd);

	cout << "\n----------------- CHALLENGE --------------------\n";

	challenge();

	cout << "\n---------------------------------------------------\n";

	return 0;
}

void challenge() {
	Movies movies;
	movies.display_movies();

	movies.add_movie("Fight Club", "R", 15);
	movies.add_movie("Back To The Future", "PG", 52);
	movies.add_movie("Jurassic Park", "PG-13", 23);
	movies.add_movie("Fight Club", "R", 15);

	movies.display_movies();

	movies.increment_watched("No Name");
	movies.increment_watched("Fight Club");

	movies.display_movies();
}
