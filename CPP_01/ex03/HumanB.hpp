/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:02 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 08:47:57 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

class HumanB
{
	private:
		std::string* _weapon;
		std::string _name;
		
	public:
		HumanB(std::string name);
		HumanB(std::string name, std::string weapon);
		~HumanB();

		void	setWeapon(std::string& weapon);
		void	setName(std::string name);
		
		std::string&	getWeapon(void) const;
		std::string&	getName(void) const;

		void	attack(void) const;
};

#endif