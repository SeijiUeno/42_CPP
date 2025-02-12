/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:05 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 19:21:51 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : 
    ClapTrap("Default", 100, 50, 20) {
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : 
    ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source) {
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& source) {
    if (this != &source) {
        ClapTrap::operator=(source);
    }
    std::cout << "ScavTrap assignment operator called\n";
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << _name << " entered Gatekeeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " is too exhausted!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target
              << " (" << _attackDamage << " damage!)" << std::endl;
    _energyPoints--;
}