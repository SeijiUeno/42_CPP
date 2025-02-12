/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:09:30 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 09:23:21 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

int main( void )
{
	
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );

std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;
std::cout << "a is " << a.toFloat() << " as float" << std::endl;
std::cout << "b is " << b.toFloat() << " as float" << std::endl;
std::cout << "c is " << c.toFloat() << " as float" << std::endl;
std::cout << "d is " << d.toFloat() << " as float" << std::endl;
std::cout << std::setw(42) << std::setfill('-') << "" << std::endl;

// b.setRawBits(15); 

return 0;
}