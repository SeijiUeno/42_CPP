/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:02 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 10:34:58 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_fixed;
	static const int	_fractional = 8;

public:
	Fixed(void);
	~Fixed( void );
	
	Fixed(const int number);
	Fixed(const float number) ;
	
	Fixed(Fixed const & source);
	Fixed&	operator=(Fixed const & other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	int		toInt( void ) const;
	float	toFloat( void ) const;	
};

std::ostream&	operator<<( std::ostream & _cout, Fixed const & fixed);

#endif