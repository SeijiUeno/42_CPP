#include "Identifier.hpp"
#include <iostream>

int main() 
{
	Base* basePtr = generate();

	identify(basePtr);

	identify(*basePtr);

	delete basePtr;

	return 0;
}
