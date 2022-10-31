#include <iostream>
#include <cstring>
#include "MyString.h"
#include "MyStringChallenge.h"

int main()
{
	MyString a{ "Hello" };
	MyString b;
	MyString c;

	b = a;

	c = MyString{ "Hola" };

	std::cout << std::boolalpha;
	std::cout << "Is A equl to C: " << (a == c) << std::endl;
	std::cout << "Is A equl to B: " << (a == b) << std::endl;
	std::cout << (a + " - " + c).get_str() << std::endl;
	std::cout << (-a).get_str() << std::endl;

	/*std::cout << "Enter 3 names: " << std::endl;
	std::cin >> a >> b >> c;
	std::cout << "The 3 names are: " << a << ", " << b << ", " << c << std::endl;*/

	/********************************************************************************
	* CHALLENGE
	********************************************************************************/

	std::cout << "\n----------------------------CHALLENGE------------------------------\n";

	MyStringChallenge m1{ "Hello" };
	MyStringChallenge m2{ m1 };
	MyStringChallenge m3{ "World" };

	std::cout << std::boolalpha;
	std::cout << "m1: " << m1.get_str() << std::endl;
	std::cout << "m2: " << m2.get_str() << std::endl;
	std::cout << "m3: " << m3.get_str() << std::endl;

	std::cout << "m1 == m2: " << (m1 == m2) << std::endl;
	std::cout << "m1 == m3: " << (m1 == m3) << std::endl;

	std::cout << "m1 < m3: " << (m1 < m3) << std::endl;
	std::cout << "m3 > m2: " << (m3 > m2) << std::endl;
	std::cout << "m3 < m1: " << (m3 < m1) << std::endl;

	std::cout << "m1 != m2: " << (m1 != m2) << std::endl;
	std::cout << "m2 != m3: " << (m2 != m3) << std::endl;

	std::cout << "m1 uppercase: " << (++m1).get_str() << std::endl;
	std::cout << "m3 lowercase: " << (--m3).get_str() << std::endl;

	std::cout << "m1 + m3: " << (m1 + " " + m3 + "!").get_str() << std::endl;

	std::cout << "m1 * 3: " << (m1 * 3).get_str() << std::endl;

	std::cout << "m1 += m3: " << (m1 += m3).get_str() << std::endl;
	std::cout << "m1 *= 3: " << (m1 *= 3).get_str() << std::endl;

	return 0;
}

