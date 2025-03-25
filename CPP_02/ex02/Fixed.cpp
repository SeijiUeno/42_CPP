/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:05 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 10:35:56 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int number) : _fixed(number << this->_fractional) {}

Fixed::Fixed(const float number) : _fixed(roundf(number * (1 << this->_fractional))) {}

// copy 
Fixed::Fixed(Fixed const &source) : _fixed(source._fixed) {}

Fixed &Fixed::operator=(Fixed const &other) 
{
    if (this != &other) {
        this->_fixed = other.getRawBits();
    }
    return (*this);
}

// getter and setters
int Fixed::getRawBits(void) const 
{
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw) 
{
    this->_fixed = raw;
}

// overload
std::ostream&	operator<<( std::ostream & _cout, Fixed const & fixed)
{
	_cout << fixed.toFloat();
	return (_cout);
}

// to operators ------------------------------------------------------------------------ 
	
int Fixed::toInt(void) const 
{
    return (this->_fixed >> this->_fractional);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_fixed) / (1 << this->_fractional));
}

// # Comparison Operators ----------------------------------------------------------------------

bool Fixed::operator>(Fixed const &other) const 
{
    return (this->_fixed > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const 
{
    return (this->_fixed < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const 
{
    return (this->_fixed >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const 
{
    return (this->_fixed <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const 
{
    return (this->_fixed == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const 
{
    return (this->_fixed != other.getRawBits());
}

// # ArithmeticOperators ------------------------------------------------------------------------

Fixed Fixed::operator+(Fixed const &other) const 
{
    return (Fixed(this->toFloat() + other.toFloat()));;
}

Fixed Fixed::operator-(Fixed const &other) const 
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(Fixed const &other) const 
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(Fixed const &other) const 
{
    if (other.getRawBits() == 0) 
    {
        throw std::runtime_error("Error: Division by zero!!");
    }
    return Fixed(this->toFloat() / other.toFloat());
}


// # Increment Decrement Operators! ---------------------------------------------------

Fixed &Fixed::operator++() 
{
    this->_fixed += (1 << _fractional);
    return *this;
}

Fixed &Fixed::operator--() 
{
    this->_fixed -= (1 << _fractional);
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed tmp(*this);
    this->_fixed += (1 << _fractional);
    return tmp;
}

Fixed Fixed::operator--(int) 
{
    Fixed tmp(*this);
    this->_fixed -= (1 << _fractional);
    return tmp;
}

//# MinMaxFunctions! -------------------------------------------------------------------

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) 
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) 
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}