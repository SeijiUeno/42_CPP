/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:16:59 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 15:42:38 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void) {}
	
Harl::~Harl() {}

void	Harl::debug( void )
{
	std::cout << DEBUG << std::endl;
}

void	Harl::info( void )
{
	std::cout << INFO << std::endl;
}

void	Harl::warning( void )
{
	std::cout << WARNING << std::endl;
}

void	Harl::error( void )
{
	std::cout << "\033[1;31m" << ERROR << "\033[0m" << std::endl;
}

void	Harl::complain( std::string level )
{
	const std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	
	void				(Harl::*functions[])() = { &Harl::debug, &Harl::info,
							&Harl::warning, &Harl::error };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if(levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout 	<< "Not a valid level! : " << level << std::endl;
}