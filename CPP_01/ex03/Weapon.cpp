/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:27:57 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 09:03:18 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon() : _type("BrokenDreams") {};

Weapon::Weapon(std::string type) : _type(type) {};

Weapon::~Weapon()
{
	if (this->type == "BrokenDreams")
		std::cout << this->_type << "Is Reborn and found!" << std::endl;
	else
		std::cout << this->_type << "Is Broken and Lost!" << std::endl;	
};

const std::string& Weapon::getType (void) const 
{
	return (this->_type)
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

