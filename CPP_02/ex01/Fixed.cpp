/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:05 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 10:26:06 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "> Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "> Destructor" << std::endl;
}

Fixed::Fixed( const int number ) : _fixed( number << this->_fractional )
{
	std::cout << "> Int constructor called" << std::endl;
}

Fixed::Fixed( const float number ) : _fixed(roundf(number * (1 << this->_fractional)))
{
	std::cout << "> Float constructor" <<std::endl;
}

// copy
Fixed::Fixed( Fixed const & source )  : _fixed(source._fixed)
{
	std::cout << "> Copy constructor" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const & other )
{
	std::cout << "> assignment operator " << std::endl;
	
	if (this != &other)
		this->_fixed = other.getRawBits();
	return (*this);
}

// getter and setters
int		Fixed::getRawBits( void ) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

// overload
std::ostream&	operator<<( std::ostream & _cout, Fixed const & fixed)
{
	_cout << fixed._fixed;
	return (_cout);
}

// to type
int		Fixed::toInt( void ) const
{
	return (this->_fixed >> this->_fractional);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / ( 1 << this->_fractional ));
}