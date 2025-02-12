/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:15:58 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 18:42:39 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& src);
    ~ClapTrap();
    
    ClapTrap& operator=(const ClapTrap& source);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void doNothing() const;

    // Getters
    const std::string& getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    bool isDead() const;

    // Setters
    void setAttackDamage(unsigned int damage);
    void setEnergyPoints(unsigned int energy);

    static const int MAX_HIT_POINTS = 10;

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
    bool _isDead;
};

#endif