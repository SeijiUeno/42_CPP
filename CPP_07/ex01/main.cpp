#include <iostream>
#include <string>
#include <cctype>
#include "Iter.hpp"

#define BOLD(text) "\033[1m" text "\033[0m"

template <typename T>
void print(const T &value) {
	std::cout << value << " ";
}

void doubleInt(int &x) {
	x *= 2;
}

void toUpper(std::string &s) {
	for (size_t i = 0; i < s.length(); ++i)
		s[i] = std::toupper(s[i]);
}

template <typename T>
void debugValue(const T &v) {
	std::cout << "[" << v << "] ";
}

int main() {
	std::cout << BOLD("\n=== ITER TESTS ===\n") << std::endl;

	std::cout << BOLD("\n=== Integer TESTS ===\n") << std::endl;
	int nums[] = {1, 2, 3, 4, 5};
	std::cout << BOLD("Initial int array:");
	iter(nums, 5, print<int>);
	std::cout << std::endl;

	std::cout << BOLD("After doubling:");
	iter(nums, 5, doubleInt);
	iter(nums, 5, print<int>);
	std::cout << std::endl;

	std::cout << BOLD("\n=== Strings TESTS ===\n") << std::endl;

	std::string words[] = {"hello", "world", "C++", "42"};
	std::cout << BOLD("\nOriginal strings:  ");
	iter(words, 4, print<std::string>);
	std::cout << std::endl;

	std::cout << BOLD("After toUpper():   ");
	iter(words, 4, toUpper);
	iter(words, 4, print<std::string>);
	std::cout << std::endl;

	std::cout << BOLD("\n=== Char Print TEST === \n") << std::endl;

	char letters[] = {'a', 'b', 'c', 'd'};
	std::cout << BOLD("\n Char array : ");
	iter(letters, 4, print<char>);
	std::cout << std::endl;

	std::cout << BOLD("\n=== Const Array TEST ===\n") << std::endl;
	int constNums1[] = {10, 20, 30};
	std::cout << BOLD("int array!:   ");
	iter(constNums1, 3, debugValue<const int>);
	std::cout << std::endl;

	std::cout << BOLD("\n=== CONST ARRAY TEST ===\n") << std::endl;

	const int constNums2[4] = {10, 20, 30, 40};
	std::cout << BOLD("Const int array: ");
	iter(constNums2, 4, debugValue<const int>);
	std::cout << std::endl;

	std::cout << BOLD("\n✅ All iter tests complete!\n") << std::endl;
	return 0;
}
