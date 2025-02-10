/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:02 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 09:52:16 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
		
	public:
		HumanB();
		HumanB(std::string name);
		HumanB(std::string name, Weapon& weapon);
		~HumanB();

		void 	setWeapon(Weapon& weapon);
		void	attack(void) const;
};

#endif