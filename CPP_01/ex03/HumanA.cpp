/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:07 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 10:04:02 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(Weapon& weapon) : _name("Foot Soldier"), _weapon(weapon) {}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA()
{
	std::cout << "HumanA: " << "\033[1;31m" << _name << "\033[0m"  << " is dead!";
	std::cout << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << "\033[1;31m" << _name << "\033[0m";
	std::cout << " attacks with their " << _weapon.getType() << std::endl;
}