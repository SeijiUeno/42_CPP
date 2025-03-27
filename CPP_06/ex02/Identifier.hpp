#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include "Base.hpp"

#define BOLD(text) "\033[1m" text "\033[0m"

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
