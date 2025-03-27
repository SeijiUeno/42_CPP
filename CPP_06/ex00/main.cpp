#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

#define BOLD(text) "\033[1m" text "\033[0m"
#define GREEN(text) "\033[1;32m" text "\033[0m"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}

	std::string arg(argv[1]);
	if (arg == "TEST")
	{
		std::cout << BOLD(" ===== Convert Test \"A\" ===== ") << std::endl;
		ScalarConverter::convert("a");

		std::cout << BOLD(" ===== Convert Test \"42\" ===== ") << std::endl;
		ScalarConverter::convert("42");

		std::cout << BOLD(" ===== Convert Test \"42.0f\" ===== ") << std::endl;
		ScalarConverter::convert("42.0f");

		std::cout << BOLD(" ===== Convert Test \"42.0\" ===== ") << std::endl;
		ScalarConverter::convert("42.0");

		std::cout << BOLD(" ===== Convert Test \"nan\" ===== ") << std::endl;
		ScalarConverter::convert("nan");

		std::cout << BOLD(" ===== Convert Test \"non_numeric\" ===== ") << std::endl;
		ScalarConverter::convert("non_numeric");
	}
	else 
	{
		ScalarConverter::convert(arg);
	}
	return 0;
}
