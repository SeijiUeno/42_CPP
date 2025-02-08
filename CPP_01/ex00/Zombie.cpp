/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:17:39 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/08 19:04:58 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie() : _name("foo") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
