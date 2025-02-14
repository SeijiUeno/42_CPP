/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:26 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 13:28:48 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
    std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
    std::cout << "Animal: " << this->type << " default constructor called." << std::endl;
} 

Animal::Animal(const Animal& source) : type(source.type) 
{
    std::cout << "Animal: copy constructor called" << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal: destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& source) 
{
    if (this != &source)
        type = source.type;
    std::cout << "Animal: copy assignment operator called" << std::endl;
    return (*this);
}

std::string Animal::getType() const 
{
    return (type);
}

void Animal::setType(std::string newType)
{
    this->type = newType;
}

void Animal::makeSound() const 
{
    std::cout << "Base class Sound: Animal!" << std::endl;
}
