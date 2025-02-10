/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:04 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 09:00:37 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB() : _name("Foot Soldier"), _weapon(nullptr) {}

HumanB::HumanB(std::string name, std::string weapon) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB(){}

void	HumanB::setWeapon(std::string weapon) { _weapon = &weapon; }
void	HumanB::setName(std::string name) { _name = name; }
	
const std::string&	HumanB::getWeapon(void) const 
{ 
	static std::string emptyHands;
	
	emptyHands = "Right and left Fists"
	if (_weapon)
		return (*_weapon);
	else
		return (emptyHands);
}

std::string	HumanB::getName(void) const { return (_name); }

void	HumanB::attack(void)
{
	std::cout << this->_name << "attacks with their" << this_>_weapon << std::endl;
}
