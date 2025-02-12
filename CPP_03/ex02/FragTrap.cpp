/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:10 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 19:22:24 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Unknown", HIT_POINTS, ENERGY_POINTS, ATTACK_DAMAGE)
{
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string name) : 
    ClapTrap(name, HIT_POINTS, ENERGY_POINTS, ATTACK_DAMAGE)
{
    std::cout << "FragTrap parameterized constructor called for " << _name << "\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << "\n";
}

FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source)
{
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& source)
{
    std::cout << "FragTrap assignment operator called\n";
    if (this != &source) {
        ClapTrap::operator=(source);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " is out of energy!\n";
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " damage!\n";
    _energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    if (_energyPoints == 0) {
        std::cout << _name << " is out of energy for high fives!\n";
        return;
    }
    std::cout << _name << " requests a positive high five!\n";
    _energyPoints--;
}