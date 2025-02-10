/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:18:41 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/08 20:26:54 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib> 

Zombie* zombieHorde(int N, std::string name);

int main(int argc, char** argv) 
{
	if (argc != 2)
	{
		std::cerr << "Use: ./Moar-brainz <number_of_zombies>" << std::endl;
		return (1);
	}
	int N = std::atoi(argv[1]);
	if(!N)
	{
		std::cerr << "Use: ./Moar-brainz <number_of_zombies>" << std::endl;
		return (1);
	}
	if (N <= 2)
	{
		std::cerr << "Hint: A horde must have more than 2 zombies.\nOtherwise is not a HORDE\n(A horde has a number of zombies)" << std::endl;
		return (1);
	}
	Zombie* horde = zombieHorde(N, "HordeZombie");
	if (!horde)
	{
		std::cerr << "Allocation Failure." << std::endl;
		return (1);
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	
	return (0);
}
