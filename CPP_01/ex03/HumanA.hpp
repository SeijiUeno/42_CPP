/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:10 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 09:45:18 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA 
{
	private:
		std::string _name;
		Weapon& _weapon;
		
	public:
		HumanA(Weapon& Weapon);
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack(void) const;
};

#endif