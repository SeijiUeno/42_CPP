/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:00 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 18:23:06 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <cstdlib>
# include <ctime>
# include <iostream> 

void        executeAction(ClapTrap& attacker, ClapTrap& defender, int action);
void        checkEnergyBoost(ClapTrap& fighter);

void displayBattleHeader(int round) {
    std::cout << "\n\x1b[36m===== ROUND " << round << " =====\x1b[0m\n";
}

void handleFighterTurn(ClapTrap& attacker, ClapTrap& defender) {
    if (attacker.isDead() || attacker.getEnergyPoints() == 0) return;

    int action = rand() % 5;
    executeAction(attacker, defender, action);
    checkEnergyBoost(attacker);
}

void executeAction(ClapTrap& attacker, ClapTrap& defender, int action) {
    switch(action) {
        case 0: case 4:
            attacker.doNothing();
            break;
        case 1:
            attacker.attack(defender.getName());
            defender.takeDamage(attacker.getAttackDamage());
            break;
        case 2: {
            int repair = rand() % 4 + 1;
            attacker.beRepaired(repair);
            break;
        }
        case 3: {
            int selfDamage = rand() % 3 + 1;
            attacker.takeDamage(selfDamage);
            break;
        }
    }
}

void checkEnergyBoost(ClapTrap& fighter)
{
	if (fighter.isDead())
		return;
    if ((rand() % 10 == 0) && (fighter.getEnergyPoints() < 10)) {
        fighter.setEnergyPoints(fighter.getEnergyPoints() + 2);
        std::cout << "⚡ " << fighter.getName() << " found energy (+2)\n";
    }
}

void displayBattleStatus(const ClapTrap fighters[2]) {
    std::cout << "\n\x1b[90m── BATTLE STATUS ──\x1b[0m\n";
    for (int i = 0; i < 2; i++) {
        std::cout << "[" << (fighters[i].isDead() ? "💀" : "🤖") << "] "
                  << fighters[i].getName() << " | HP: " << fighters[i].getHitPoints()
                  << " | Energy: " << fighters[i].getEnergyPoints() << "\n";
    }
}

void displayFinalResults(const ClapTrap fighters[2], int rounds) {
    std::cout << "\n\x1b[35m🏆 FINAL RESULTS 🏆\x1b[0m\n";
    if (rounds > 20) {
        std::cout << "⏰ TIME'S UP AFTER 20 ROUNDS!\n";
    }
    for (int i = 0; i < 2; i++) {
        std::cout << (fighters[i].isDead() ? "☠️  LOSER: " : "🔥 WINNER: ")
                  << fighters[i].getName() << "\n";
    }
}
