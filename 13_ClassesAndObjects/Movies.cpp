#include "Movies.h"
#include <iostream>

Movies::Movies() {
	movies = {};
}

void Movies::add_movie(std::string name, std::string rating, int watched) {
	Movie* movieFound = Movies::find_movie(name);

	if (movieFound != nullptr) {
		std::cout << name << " already exists." << std::endl;
		return;
	}

	movies.push_back(Movie{ name, rating, watched });
	std::cout << name << " added to the list." << std::endl;
}

void Movies::increment_watched(std::string name) {
	Movie* movieFound = Movies::find_movie(name);

	if (movieFound == nullptr) {
		std::cout << name << " not found in the list." << std::endl;
		return;
	}

	movieFound->increment_watched();

	std::cout << name << " watched incremented." << std::endl;
}

void Movies::display_movies() const {
	if (movies.size() == 0) {
		std::cout << "Sorry, you have no movies in your list." << std::endl;
	}

	for (const auto &movie : movies) {
		movie.display();
	}
}

Movie* Movies::find_movie(std::string movieName) {
	auto it = std::find_if(movies.begin(), movies.end(), [&movieName](const Movie& movie) { return movie.name == movieName;  });

	if (it != movies.end()) {
		auto index = std::distance(movies.begin(), it);
		return &movies[index];
	}

	return nullptr;
}