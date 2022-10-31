#pragma once
class MyStringChallenge
{
private:
	char* str;
public:
	MyStringChallenge();
	MyStringChallenge(const char* s);
	MyStringChallenge(MyStringChallenge& source);
	MyStringChallenge(MyStringChallenge&& source) noexcept;
	~MyStringChallenge();

	bool operator==(const MyStringChallenge& rhs) const;
	bool operator!=(const MyStringChallenge& rhs) const;
	bool operator<(const MyStringChallenge& rhs) const;
	bool operator>(const MyStringChallenge& rhs) const;
	MyStringChallenge operator++() const;
	MyStringChallenge operator--() const;
	MyStringChallenge operator+(const MyStringChallenge& rhs) const;
	MyStringChallenge operator*(const int times) const;
	MyStringChallenge& operator+=(const MyStringChallenge& rhs);
	MyStringChallenge& operator*=(const int times);

	const char* get_str() const;
	const size_t get_length() const;
};

