/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:04 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 10:04:27 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB() : _name("Foot Soldier"), _weapon(NULL) {}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon) {}

HumanB::~HumanB()
{
	std::cout << "HumanB: " << "\033[1;31m" << _name << "\033[0m"  << " is dead!";
	std::cout << std::endl;
}

void 	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << "\033[1;31m" << _name << "\033[0m";
	std::cout << " attacks with their " << _weapon->getType() << std::endl;
}
