#include "Identifier.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate() {
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	int r = std::rand() % 3;
	switch (r) {
		case 0:
			std::cout << "[generate()] -> A\n";
			return new A;
		case 1:
			std::cout << "[generate()] -> B\n";
			return new B;
		default:
			std::cout << "[generate()] -> C\n";
			return new C;
	}
}
	
void identify(Base* p) 
{
	if (dynamic_cast<A*>(p))
		std::cout << "identify(*) :" << BOLD("A") << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identify(*) : " << BOLD("B") << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identify(*) : " << BOLD("C") << std::endl;
	else
		std::cout << "identify(*) : " <<  BOLD("Unknown type ") << std::endl;
}

void identify(Base &p) {
	try {
	A &a = dynamic_cast<A&>(p);
	(void)a;
	std::cout << "identify(&) : " << BOLD("A") << std::endl;
	return;
	} catch (const std::exception &e)
	{
	}

	try {
	B &b = dynamic_cast<B&>(p);
	(void)b;
	std::cout << "identify(&) : " << BOLD("B") << std::endl;
	return;
	} catch (const std::exception &e)
	{
	}

	try {
	C &c = dynamic_cast<C&>(p);
	(void)c;
	std::cout << "identify(&) : " << BOLD("C") << std::endl;
	return;
	} catch (const std::exception &e)
	{
	}
	
	std::cout << "identify(*) : " BOLD("Unknown type") << std::endl;
}
