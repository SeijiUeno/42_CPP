/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:44 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 13:34:01 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) : type(source.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& source)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &source)
        type = source.type;
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::setType(const std::string& type)
{
    this->type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Base WrongAnimal: WrongAnimal sound!" << std::endl;
}
