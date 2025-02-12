/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:05 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 10:16:46 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) { std::cout << "> Default constructor called" << std::endl; }

Fixed::Fixed( Fixed const &source) : _fixed(source._fixed)
{
	std::cout << "> Copy constructor called!" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=( Fixed const & other)
{
	std::cout << "> Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixed = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "> getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "> setRawBits member function called" << std::endl;
    this->_fixed = raw;
}
