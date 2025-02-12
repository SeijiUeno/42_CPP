/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:15:55 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 19:24:32 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name,
                  unsigned int hitPoints,
                  unsigned int energyPoints,
                  unsigned int attackDamage) :
    _name(name),
    _hitPoints(hitPoints),
    _energyPoints(energyPoints),
    _attackDamage(attackDamage)
{
    std::cout << "ClapTrap parameterized constructor (" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap() :
    _name("Unknown"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap named constructor (" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) :
    _name(source._name),
    _hitPoints(source._hitPoints),
    _energyPoints(source._energyPoints),
    _attackDamage(source._attackDamage)
{
    std::cout << "ClapTrap copy constructor (" << _name << ")" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor (" << _name << ")" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& source)
{
    std::cout << "ClapTrap assignment operator (" << _name << ")" << std::endl;
    if (this != &source) {
        _name = source._name;
        _hitPoints = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target
            << ", causing " << _attackDamage << " damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout << _name << " is already destroyed!" << std::endl;
        return;
    }
    
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << _name << " takes " << amount << " damage and is destroyed!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << _name << " takes " << amount << " damage! HP: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0) {
        std::cout << _name << " has no energy to repair!" << std::endl;
        return;
    }
    
    unsigned int effectiveRepair = amount;
    if (_hitPoints + amount > 10) {
        effectiveRepair = 10 - _hitPoints;
    }
    
    _hitPoints += effectiveRepair;
    _energyPoints--;
    std::cout << _name << " repairs " << effectiveRepair << " HP! Total HP: " << _hitPoints << std::endl;
}

// Getters
std::string ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }