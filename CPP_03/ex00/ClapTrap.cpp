/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:15:55 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 18:22:48 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() 
    : _name("Default"), _hitPoints(10), _energyPoints(10), 
      _attackDamage(0), _isDead(false) {
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10),
      _attackDamage(0), _isDead(false) {
    std::cout << "ClapTrap " << _name << " created!\n";
}

ClapTrap::ClapTrap(const ClapTrap& src) 
    : _name(src._name), _hitPoints(src._hitPoints),
      _energyPoints(src._energyPoints), _attackDamage(src._attackDamage),
      _isDead(src._isDead) {
    std::cout << "ClapTrap copy created: " << _name << "\n";
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& source)
{
    if (this != &source) {
        _name = source._name;
        _hitPoints = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
        _isDead = source._isDead;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_isDead) {
        std::cout << "💀 " << _name << " can't attack (dead)\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "😴 " << _name << " has no energy to attack\n";
        return;
    }
    std::cout << "⚔️ " << _name << " attacks " << target 
              << " (" << _attackDamage << " damage)\n";
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_isDead) {
        std::cout << "💀 " << _name << " is already dead!\n";
        return;
    }
    std::cout << "💥 " << _name << " takes " << amount << " damage\n";
    
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        _isDead = true;
        std::cout << "💀 " << _name << " died!\n";
    } else {
        _hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_isDead) {
        std::cout << "💀 " << _name << " can't repair (dead)\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "😴 " << _name << " has no energy to repair\n";
        return;
    }
    
    unsigned int maxHeal = MAX_HIT_POINTS - _hitPoints;
    unsigned int healed = (amount > maxHeal) ? maxHeal : amount;
    
    if (healed > 0) {
        _hitPoints += healed;
        std::cout << "🛠️ " << _name << " repaired " << healed 
                  << " HP (" << _hitPoints << "/10)\n";
    } else {
        std::cout << "🔒 " << _name << " at full HP\n";
    }
    _energyPoints--;
}

void ClapTrap::doNothing() const {
    if (_isDead) return;
    std::cout << "🌀 " << _name << " does nothing\n";
}

// Getters
const std::string& ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
bool ClapTrap::isDead() const { return _isDead; }

// Setters
void ClapTrap::setAttackDamage(unsigned int damage) { 
    _attackDamage = damage; 
}

void ClapTrap::setEnergyPoints(unsigned int energy) 
{ 
    _energyPoints = (energy > 10) ? 10 : energy; 
}