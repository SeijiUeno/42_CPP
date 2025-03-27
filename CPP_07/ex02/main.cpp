#include <iostream>
#include <string>
#include "Array.hpp"

#define BOLD(text) "\033[1m" text "\033[0m"

int main() {
	std::cout << BOLD("Default:") << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	std::cout << BOLD("\nConstruction with size 5:") << std::endl;
	Array<int> nums(5);
	for (unsigned int i = 0; i < nums.size(); ++i)
		nums[i] = i * 10;

	for (unsigned int i = 0; i < nums.size(); ++i)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD("\nCopy constructor:") << std::endl;
	Array<int> copy(nums);
	copy[0] = 999;
	std::cout << "Original[0]: " << nums[0] << std::endl;
	std::cout << "Copy[0]:	 " << copy[0] << std::endl;

	std::cout << BOLD("\nAssignment operator:") << std::endl;
	Array<int> assigned;
	assigned = nums;
	assigned[1] = 888;
	std::cout << "Original[1]: " << nums[1] << std::endl;
	std::cout << "Assigned[1]: " << assigned[1] << std::endl;

	std::cout << BOLD("\nBounds checking test:") << std::endl;
	try {
		std::cout << nums[10] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
