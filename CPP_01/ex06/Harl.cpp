/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:17:53 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 16:33:09 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void) {}
	
Harl::~Harl() {}

void	Harl::debug( void )
{
	std::cout << "\033[1;34m" << DEBUG << "\033[0m" << std::endl;
}

void	Harl::info( void )
{
	std::cout <<  "\033[1;32m" << INFO << "\033[0m" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "\033[1;33m" << WARNING << "\033[0m" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "\033[1;31m" << ERROR << "\033[0m" << std::endl;
}

void	Harl::complain( std::string level )
{
	const	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index;

	for (index = 0; index < 4; index++)
	{
		if (levels[index] == level)
			break;
	}
	switch (index)
	{
	case 0: 
		debug();
		//should also print 1 2 3
	case 1: 
		info();
		//should also print 2 3
	case 2: 
		warning();
		//should also print 3
	case 3: 
		error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}