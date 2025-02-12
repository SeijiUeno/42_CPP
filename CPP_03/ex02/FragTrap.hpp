/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:13 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/12 19:22:31 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string name);
    ~FragTrap();
    FragTrap(const FragTrap& source);
    FragTrap& operator=(const FragTrap& source);

	void attack(const std::string& target);
    void highFivesGuys(void);

protected:
    static const int HIT_POINTS = 100;
    static const int ENERGY_POINTS = 100;
    static const int ATTACK_DAMAGE = 30;
};

#endif