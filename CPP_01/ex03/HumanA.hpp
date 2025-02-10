/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:10 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 09:04:19 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>

class HumanA 
{
	private:
		std::string _name;
		Weapon& _weapon;
		
	public:
		HumanA(Weapon weapon);
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	setWeapon(std::string weapon);
		void	setName(std::string name);
		
		std::string	getWeapon(void) const;
		std::string	getName(void) const;

		void	attack(void) const;
};

#endif