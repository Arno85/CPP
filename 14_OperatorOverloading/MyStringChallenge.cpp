#pragma warning(disable:4996)
#include "MyStringChallenge.h"
#include <iostream>

MyStringChallenge::MyStringChallenge() : str{ nullptr } {
	str = new char[1];
	*str = -'\0';
};

MyStringChallenge::MyStringChallenge(const char* s) : str{ nullptr } {
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[std::strlen(s) + 1];
		strcpy(str, s);
	}
};

MyStringChallenge::MyStringChallenge(MyStringChallenge& source) : str{ nullptr } {
	str = new char[std::strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyStringChallenge::MyStringChallenge(MyStringChallenge&& source) noexcept : str{ nullptr } {
	str = source.str;
	source.str = nullptr;
}

MyStringChallenge::~MyStringChallenge() {
	delete[] str;
}

bool MyStringChallenge::operator==(const MyStringChallenge& rhs) const {
	return std::strcmp(str, rhs.str) == 0;
}

bool MyStringChallenge::operator!=(const MyStringChallenge& rhs) const {
	return std::strcmp(str, rhs.str) != 0;
}

bool MyStringChallenge::operator<(const MyStringChallenge& rhs) const {
	return std::strcmp(str, rhs.str) < 0;
}

bool MyStringChallenge::operator>(const MyStringChallenge& rhs) const {
	return std::strcmp(str, rhs.str) > 0;
}

MyStringChallenge MyStringChallenge::operator++() const {
	char* buff = new char[std::strlen(str) + 1];
	strcpy(buff, str);

	for (size_t i{ 0 }; i < std::strlen(buff); i++) {
		buff[i] = std::toupper(buff[i]);
	}

	MyStringChallenge temp{ buff };

	delete[] buff;

	return temp;
}

MyStringChallenge MyStringChallenge::operator--() const {
	char* buff = new char[std::strlen(str) + 1];
	strcpy(buff, str);

	for (size_t i{ 0 }; i < std::strlen(buff); i++) {
		buff[i] = std::tolower(buff[i]);
	}

	MyStringChallenge temp{ buff };

	delete[] buff;

	return temp;
}

MyStringChallenge MyStringChallenge::operator+(const MyStringChallenge& rhs) const {
	char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
	strcpy(buff, str);
	strcat(buff, rhs.str);

	MyStringChallenge temp{ buff };

	delete[] buff;

	return temp;
}

MyStringChallenge MyStringChallenge::operator*(const int times) const {
	char* buff = new char[std::strlen(str) * times + 1];
	*buff = '\0';

	for (int i{ 0 }; i < times; i++) {
		strcat(buff, str);
	}

	MyStringChallenge temp{ buff };
	delete[] buff;

	return temp;
}

MyStringChallenge& MyStringChallenge::operator+=(const MyStringChallenge& rhs) {
	MyStringChallenge newString = MyStringChallenge::operator+(rhs);
	str = new char[std::strlen(newString.str) + 1];
	strcpy(str, newString.str);

	return *this;
}

MyStringChallenge& MyStringChallenge::operator*=(const int times) {
	MyStringChallenge newString = MyStringChallenge::operator*(times);
	str = new char[std::strlen(newString.str) + 1];
	strcpy(str, newString.str);

	return *this;
}

const char* MyStringChallenge::get_str() const {
	return str;
}

const size_t MyStringChallenge::get_length() const {
	return std::strlen(str);
}
