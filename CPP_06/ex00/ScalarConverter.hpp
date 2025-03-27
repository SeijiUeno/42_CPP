#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <climits>
#include <cctype>
#include <iomanip>

class ScalarConverter {
public:
	static void convert(const std::string &literal);
	~ScalarConverter();

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);

	static bool isPseudoLiteral(const std::string &s);
	static bool isDecimalNotation(const std::string &s);

	static void printChar(char c);
	static void printCharSafe(double d);
	static void printInt(int i);
	static void printIntSafe(double d);
	static void printFloat(float f);
	static void printDouble(double d);
	static void printImpossible(const std::string &label);
	static void printAllImpossible();
};

#endif
