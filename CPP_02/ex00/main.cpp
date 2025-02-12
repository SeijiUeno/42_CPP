/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:07 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 08:34:10 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

int	main( void )
{
	Fixed a;
	a.setRawBits(42);
	Fixed b( a );
	Fixed c;
	
	c = b;
	
	std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
		std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;
	a.setRawBits(7);
	b.setRawBits (77);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}