/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:03 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 19:24:24 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void header(const std::string& text)
{
    std::cout << "\n\033[1;35m-------- " << text << " ---------033[0m\n";
}

void scavTrapTests()
{
    header("SCAVTRAP CONSTRUCTION/DESTRUCTION");
    {
        ScavTrap scav("Gatekeeper");
        std::cout << "\nExpected construction order:\n"
                  << "1. ClapTrap constructor\n"
                  << "2. ScavTrap constructor\n\n";
    }
    std::cout << "\nExpected destruction order:\n"
              << "1. ScavTrap destructor\n"
              << "2. ClapTrap destructor\n";

    header("SCAVTRAP FUNCTIONALITY");
    ScavTrap scav("Guardian");
    
    
    std::cout << "\n[Attack Test]\n";
    scav.attack("Intruder");
    
    std::cout << "\n[Guard Gate Test]\n";
    scav.guardGate();

    std::cout << "\n[Energy Depletion Test]\n";
    for(int i = 0; i < 52; i++) {
        std::cout << "Action " << (i+1) << ": ";
        scav.attack("Target");
        if (i == 49) std::cout << " (50th attempt)\n";
    }

    header("SCAVTRAP COPY TESTS");
    ScavTrap original("Original");
    ScavTrap copy(original);
    ScavTrap assigned;
    assigned = original;

    std::cout << "\nOriginal name: " << original.getName() << "\n";
    std::cout << "Copy name: " << copy.getName() << "\n";
    std::cout << "Assigned name: " << assigned.getName() << "\n";
}

void fragTrapTests()
{
    header("FRAGTRAP CONSTRUCTION/DESTRUCTION");
    {
        FragTrap frag("HighFiveMaster");
        std::cout << "\nExpected construction order:\n"
                  << "1. ClapTrap constructor\n"
                  << "2. FragTrap constructor\n\n";
    }
    std::cout << "\nExpected destruction order:\n"
              << "1. FragTrap destructor\n"
              << "2. ClapTrap destructor\n";

    header("FRAGTRAP");
    FragTrap frag("HappyBot");
    
    std::cout << "\n[Attack Test]\n";
    frag.attack("Enemy");
    
    std::cout << "\n[High Five Test]\n";
    frag.highFivesGuys();

    std::cout << "\n[Energy Depletion Test]\n";
    for(int i = 0; i < 102; i++) 
    {
        std::cout << "Action " << (i+1) << ": ";
        frag.highFivesGuys();
        if (i == 99) std::cout << " (100th)\n";
    }

    header("FRAGTRAP COPY TESTS");
    FragTrap original("OriginalFrag");
    FragTrap copy(original);
    FragTrap assigned;
    assigned = original;

    std::cout << "\nOriginal Frag name: " << original.getName() << "\n";
    std::cout << "Copy Frag name: " << copy.getName() << "\n";
    std::cout << "Assigned Frag name: " << assigned.getName() << "\n";
}

int main()
{
    std::cout << "\033[1;33m=== STARTING COMPREHENSIVE TESTS ===\033[0m\n";
    
    scavTrapTests();
    fragTrapTests();

    std::cout << "\n\033[1;33m=== ALL TESTS COMPLETED ===\033[0m\n";
    return 0;
}