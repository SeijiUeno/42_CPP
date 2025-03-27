#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

bool ScalarConverter::isPseudoLiteral(const std::string &s) {
	return (
		s == "nan" || s == "nanf" ||
		s == "+inf" || s == "+inff" ||
		s == "-inf" || s == "-inff" ||
		s == "inf" || s == "inff"
	);
}

bool ScalarConverter::isDecimalNotation(const std::string &s) {
	if (s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		return false;
	return true;
}

void ScalarConverter::convert(const std::string &literal) {
	std::string numStr = literal;
	std::size_t len = literal.length();

	// (nan, inf)
	if (isPseudoLiteral(literal)) {
		double d = std::strtod(literal.c_str(), NULL);
		float f = static_cast<float>(d);
		printImpossible("char");
		printImpossible("int");
		printFloat(f);
		printDouble(d);
		return;
	}

	if (len == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		char c = literal[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		printChar(c);
		printInt(i);
		printFloat(f);
		printDouble(d);
		return;
	}

	if (!isDecimalNotation(literal)) {
		printAllImpossible();
		return;
	}

	if (numStr[len - 1] == 'f')
		numStr = numStr.substr(0, len - 1);

	errno = 0;
	char *endptr = NULL;
	double d = std::strtod(numStr.c_str(), &endptr);

	if (errno != 0 || endptr == numStr.c_str() || *endptr != '\0') {
		printAllImpossible();
		return;
	}

	float f = static_cast<float>(d);

	printCharSafe(d);
	printIntSafe(d);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::printImpossible(const std::string &label) {
	std::cout << label << ": impossible\n";
}

void ScalarConverter::printAllImpossible() {
	printImpossible("char");
	printImpossible("int");
	printImpossible("float");
	printImpossible("double");
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: '" << c << "'\n";
}

void ScalarConverter::printCharSafe(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || d < 0 || d > 127)
		std::cout << "impossible\n";
	else {
		char c = static_cast<char>(d);
		if (!std::isprint(c))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << c << "'\n";
	}
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << "\n";
}

void ScalarConverter::printIntSafe(double d) {
	std::cout << "int: ";
	if (std::isnan(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff\n" : "+inff\n");
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf\n" : "+inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << d << "\n";
}
