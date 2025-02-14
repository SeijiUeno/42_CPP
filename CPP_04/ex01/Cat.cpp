/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:31 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:18:30 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), _brain(new Brain()) 
{
    std::cout << "Cat constructor called" << std::endl;
    for (int i = 0;  i < 100; i++)
        _brain->setIdea(i, "I want fish!");
}

Cat::Cat(const Cat& source) : Animal(source), _brain(new Brain(*source._brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*source._brain);
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(const Cat& source) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &source) 
    {
        type = source.type;
        _brain = new Brain(*source._brain);
    }
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Cat sound: Meow!" << std::endl;
}

void Cat::printIdeas() const
{
    _brain->showIdeas();
}
