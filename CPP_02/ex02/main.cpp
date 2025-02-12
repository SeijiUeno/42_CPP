#include "Fixed.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>

void set_separator(std::string name)
{
    std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;
    std::cout << "\n -> " << name << std::endl;
}

void testConstructors()
{
    set_separator("testConstructors");
    Fixed a;
    assert(a.getRawBits() == 0);
    
    Fixed b(10);
    assert(b.toInt() == 10);
    assert(b.toFloat() == 10.0f);

    Fixed c(42.42f);
    assert(static_cast<int>(c.toFloat() * 100) == 4242);

    Fixed d(b);
    assert(d.toInt() == 10);
    std::cout << "\n[PASS] testConstructors" << std::endl;
}

void testAssignment()
{
    set_separator("testAssignment");
    Fixed a;
    Fixed b(10);

    a = b;
    assert(a.toInt() == 10);
    std::cout << "\n[PASS] testAssignment" << std::endl;
}

void testGetSetRawBits()
{
    set_separator("testGetSetRawBits");
    Fixed a;
    a.setRawBits(1024);
    assert(a.getRawBits() == 1024);
    std::cout << "\n[PASS] testGetSetRawBits" << std::endl;
}

void testArithmeticOperators()
{
    set_separator("testArithmeticOperators");
    Fixed a(2);
    Fixed b(3);

    Fixed c = a + b;
    assert(c.toInt() == 5);

    Fixed d = b - a;
    assert(d.toInt() == 1);

    Fixed e = a * b;
    assert(e.toInt() == 6);

    Fixed f = b / a;
    assert(f.toInt() == 1);
    std::cout << "\n[PASS] testArithmeticOperators" << std::endl;
}

void testComparisonOperators()
{
    set_separator("testComparisonOperators");
    Fixed a(2);
    Fixed b(3);

    assert(a < b);
    assert(b > a);
    assert(a <= b);
    assert(b >= a);
    assert(a != b);

    Fixed c(2);
    assert(a == c);
    std::cout << "\n[PASS] testComparisonOperators" << std::endl;
}

void testIncrementDecrementOperators()
{
    set_separator("testIncrementDecrementOperators");
    Fixed a(2);
    std::cout << "\nInitial value of a: " << a.toInt() << std::endl;

    ++a;
    std::cout << "prefix increment: " << a.toInt() << std::endl;
    assert(a.toInt() == 3);

    --a;
    std::cout << "prefix decrement: " << a.toInt() << std::endl;
    assert(a.toInt() == 2);

    Fixed temp = a++;
    std::cout << "postfix increment: " << a.toInt() << " (returned: " << temp.toInt() << ")" << std::endl;
    assert(a.toInt() == 3);
    assert(temp.toInt() == 2);

    temp = a--;
    std::cout << "postfix decrement: " << a.toInt() << " (returned: " << temp.toInt() << ")" << std::endl;
    assert(a.toInt() == 2);
    assert(temp.toInt() == 3);

    std::cout << "\n[PASS] testIncrementDecrementOperators" << std::endl;
}

void testMinMaxFunctions()
{
    set_separator("testMinMaxFunctions");
    Fixed a(2);
    Fixed b(3);

    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == b); 

    const Fixed c(2);
    const Fixed d(3);

    assert(Fixed::min(c, d) == c);
    assert(Fixed::max(c, d) == d);
    std::cout << "\n[PASS] testMinMaxFunctions" << std::endl;
}

int main()
{
    testConstructors();
    testAssignment();
    testGetSetRawBits();
    testArithmeticOperators();
    testComparisonOperators();
    testIncrementDecrementOperators();
    testMinMaxFunctions();

    std::cout << "\n✅ tests passed!" << std::endl;
    return 0;
}
