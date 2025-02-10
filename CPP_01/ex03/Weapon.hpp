/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:27:54 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/08 20:34:40 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon()
{
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		
		const std::string&	getType(void) const;
		void				setType(std::string type);
};

#endif