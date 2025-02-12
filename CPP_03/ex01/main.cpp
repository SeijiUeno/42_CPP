/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:03 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 19:15:44 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

void testScavTrap() {
    std::cout << "\n\033[1;33m===== SCAVTRAP CONSTRUCTION TEST =====\033[0m\n";
    ScavTrap scav("Gatekeeper");
    
    std::cout << "\nInitial Status:\n"
              << "Name: " << scav.getName() << " (should be Gatekeeper)\n"
              << "HP: " << scav.getHitPoints() << " (should be 100)\n"
              << "EP: " << scav.getEnergyPoints() << " (should be 50)\n"
              << "AD: " << scav.getAttackDamage() << " (should be 20)\n";

    std::cout << "\n\033[1;33m===== ATTACK OVERRIDE TEST =====\033[0m\n";
    scav.attack("Intruder");

    std::cout << "\n\033[1;33m===== GUARD GATE TEST =====\033[0m\n";
    scav.guardGate();

    std::cout << "\n\033[1;33m===== ENERGY MANAGEMENT TEST =====\033[0m\n";
    for(int i = 0; i < 52; i++) {
        std::cout << "Action " << (i+1) << ": ";
        scav.attack("Target");
        if (i == 49) std::cout << " (Should fail after 50th attempt)";
    }

    std::cout << "\n\033[1;33m===== COPY OPERATIONS TEST =====\033[0m\n";
    ScavTrap copy(scav);
    ScavTrap assigned;
    assigned = scav;
    
    std::cout << "Original HP: " << scav.getHitPoints() << "\n"
              << "Copy HP: " << copy.getHitPoints() << " (should match)\n"
              << "Assigned HP: " << assigned.getHitPoints() << " (should match)\n";
}

int main() {
    testScavTrap();
    std::cout << "\n\033[1;32m[All ScavTrap Tests Completed]\033[0m\n";
    return 0;
}