#include "DequeChallenge.h"

bool is_palindrome(const std::string& s)
{
	std::deque<char> deque1{};
	std::deque<char> deque2{};

	for (const char x : s) {
		if (std::isalpha(x)) {
			deque1.push_back(std::tolower(x));
			deque2.push_front(std::tolower(x));
		}
	}

	if (deque1 == deque2) {
		return true;
	}

	return false;
}

int deque_challenge()
{
	std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for (const auto& s : test_strings) {
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
	}
	std::cout << std::endl;

	return 0;
}