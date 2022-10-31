#pragma once
#include <string>
#include <iostream>

class Movie {
private:
	friend class Movies;
	std::string name;
	std::string rating;
	int watched;

public:
	Movie(std::string, std::string, int);
	void increment_watched();
	void display() const;
};