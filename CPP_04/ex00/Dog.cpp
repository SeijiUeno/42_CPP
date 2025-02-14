/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:36 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 13:20:42 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& source) : Animal(source)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& source)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &source)
        type = source.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog sound: Wooof!" << std::endl;
}
