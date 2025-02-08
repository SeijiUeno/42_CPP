/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:18:41 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/08 20:23:56 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) 
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Memmory adress held:\n";
	std::cout << "The string variable memory address:\n";
	std::cout << &string << "\n";
	std::cout << "The held stringPTR memory address :\n";
	std::cout << stringPTR << "\n";
	std::cout << "The held stringREF memory adress:\n";
	std::cout << &stringREF << "\n" <<std::endl;

	std::cout << "Values:\n";
	std::cout << "string:\n";
	std::cout << string << "\n";
	std::cout << "stringPTR:\n";
	std::cout << *stringPTR << "\n";
	std::cout << "stringREF:\n";
	std::cout << stringREF << std::endl;
	return (0);
}
