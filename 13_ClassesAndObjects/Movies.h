#pragma once
#include <string>
#include <vector>
#include "Movie.h"

class Movies {
private:
	std::vector<Movie> movies;

public:
	Movies();
	void add_movie(std::string, std::string, int);
	void increment_watched(std::string);
	void display_movies() const;
	Movie* find_movie(std::string);
};