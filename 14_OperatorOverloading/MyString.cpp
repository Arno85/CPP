#pragma warning(disable:4996)
#include <cstring>
#include <iostream>
#include "MyString.h"

MyString::MyString() : str{ nullptr } {
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char* s) : str{ nullptr } {
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[std::strlen(s) + 1];
		strcpy(str, s);
	}
}

MyString::MyString(const MyString& source) : str{ nullptr } {
	str = new char[std::strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyString::~MyString() {
	delete[] str;
}

MyString& MyString::operator=(const MyString& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete[] str;

	str = new char[std::strlen(rhs.str) + 1];
	strcpy(str, rhs.str);

	return *this;
}

MyString& MyString::operator=(MyString&& rhs) noexcept {
	if (this == &rhs) {
		return *this;
	}

	delete[] str;

	str = rhs.str;
	rhs.str = nullptr;

	return *this;
}

bool MyString::operator==(const MyString& rhs) const {
	return std::strcmp(str, rhs.str) == 0;
}

MyString MyString::operator-() const {
	char* buff = new char[std::strlen(str) + 1];
	std:strcpy(buff, str);

	for (size_t i = 0; i < std::strlen(buff); i++) {
		buff[i] = std::tolower(buff[i]);
	}

	MyString temp{ buff };

	delete[] buff;

	return temp;
}

MyString MyString::operator+(const MyString& rhs) const {
	char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
std:strcpy(buff, str);
	strcat(buff, rhs.str);

	MyString temp{ buff };

	delete[] buff;

	return temp;
}

void MyString::display() const {
	std::cout << str << " : " << get_length() << std::endl;
}

size_t MyString::get_length() const {
	return std::strlen(str);
}

const char* MyString::get_str() const {
	return str;
}

// FRIENDS
std::ostream& operator<<(std::ostream& os, const MyString& rhs) {
	os << rhs.str;

	return os;
}

std::istream& operator>>(std::istream& is, MyString& rhs) {
	char* buff = new char[1000];

	is >> buff;

	rhs = MyString{ buff };

	delete[] buff;

	return is;
}
