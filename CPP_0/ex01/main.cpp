/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:28:02 by sueno-te          #+#    #+#             */
/*   Updated: 2025/01/27 19:10:06 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <csignal>
#include <iostream>
#include "PhoneBook.hpp"

void	handleSignal(int signal) {
	(void)signal;
}

int	main()
{
    // Ignore signals
	std::signal(SIGINT, handleSignal);
	std::signal(SIGQUIT, handleSignal);

	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) 
		{
			std::cout << "\nGoodbye!\n";
			break ;
		}
		if (command == "ADD")
			phoneBook.phoneBook_ADD();
		else if (command == "SEARCH")
			phoneBook.phoneBook_SEARCH();
		else if (command == "EXIT")
			break ;
		else
		std::cout << "Invalid command. Please try again.\n";
	}
	return (0);
}
