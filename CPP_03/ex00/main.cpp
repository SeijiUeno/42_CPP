/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:00 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 18:26:30 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream> 
#include "ClapTrap.hpp"

ClapTrap*   initializeFighters();
void        displayBattleHeader(int round);
void        handleFighterTurn(ClapTrap& attacker, ClapTrap& defender);
void        displayBattleStatus(const ClapTrap fighters[2]);
void        displayFinalResults(const ClapTrap fighters[2], int rounds);
void        cleanupFighters(ClapTrap* fighters);

// Main Battle
void chaoticBattle()
{
    std::cout << "\n💥🤖⚔️ CHAOTIC BATTLE ARENA ⚔️🤖💥\n\n";
    srand(time(0));

    ClapTrap* fighters = initializeFighters();
    if (!fighters) {
        std::cerr << "🔥 Failed to initialize fighters!\n";
        return;
    }
    
    int round = 1;
    const int MAX_ROUNDS = 20;

    while (round <= MAX_ROUNDS && 
          !fighters[0].isDead() &&
          !fighters[1].isDead() &&
          (fighters[0].getEnergyPoints() > 0 || fighters[1].getEnergyPoints() > 0))
    {
        
        displayBattleHeader(round);
        
        for (int i = 0; i < 2; i++) {
            handleFighterTurn(fighters[i], fighters[(i+1)%2]);
        }

        displayBattleStatus(fighters);
        round++;
    }

    displayFinalResults(fighters, round);
    cleanupFighters(fighters);
}

ClapTrap* initializeFighters() {
    void* arena = operator new[](2 * sizeof(ClapTrap));
    if (!arena) return 0;
    
    ClapTrap* fighters = static_cast<ClapTrap*>(arena);
    
    new (&fighters[0]) ClapTrap("#DeepSeek#");
    new (&fighters[1]) ClapTrap("#OpenAi#");
    
    if (fighters[0].getHitPoints() == 0 || fighters[1].getHitPoints() == 0) {
        cleanupFighters(fighters);
        return 0;
    }
    
    fighters[0].setAttackDamage(rand() % 5 + 1);
    fighters[1].setAttackDamage(rand() % 5 + 1);
    
    return (fighters);
}

void cleanupFighters(ClapTrap* fighters)
{
    std::cout << "" << std::endl;
    
    fighters[0].~ClapTrap();
    fighters[1].~ClapTrap();
    
    operator delete[](fighters);
}

int main() {
    chaoticBattle();
    return 0;
}