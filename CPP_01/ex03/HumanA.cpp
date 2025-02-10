/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:07 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 09:00:56 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string weapon) : _name("Foot Soldier"), _weapon(weapon) {}

HumanA::HumanA(std::string name, std::string weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(){}

void	HumanA::setWeapon(std::string weapon) { _weapon = weapon; }
void	HumanA::setName(std::string name) { _name = name; }
	
std::string	HumanA::getWeapon(void) const { return (_weapon); }
std::string	HumanA::getName(void) const { return (_name); }

void	HumanA::attack(void)
{
	std::cout << this->_name << "attacks with their" << this->_weapon << std::endl;
}