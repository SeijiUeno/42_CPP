/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:17:47 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/08 19:10:43 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie	foo;
	Zombie*	allocated_zombie = newZombie("foo");

	foo.announce();
	allocated_zombie->announce();
	delete (allocated_zombie);
	return (0);	
}
