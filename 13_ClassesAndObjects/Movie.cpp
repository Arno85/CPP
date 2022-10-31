#include "Movie.h"
#include <iostream>

Movie::Movie(std::string n, std::string r, int w) : name{ n }, rating{ r }, watched{ w } { }

void Movie::increment_watched() {
	watched++;
}

void Movie::display() const {
	std::cout << "Name: " << name << " - Rating: " << rating << " - Watched: " << watched << " times." << std::endl;
}