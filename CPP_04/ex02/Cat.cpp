/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:31 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:21:59 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) 
{
    std::cout << "Cat constructor called" << std::endl;
    for (int i = 0;  i < 100; i++)
        _brain->setIdea(i, "I will Dominate the word, i'm a king");
}

Cat::Cat(const Cat& source) : AAnimal(source), _brain(new Brain(*source._brain))
{
    std::cout << "Cat copy constructor" << std::endl;
    _brain = new Brain(*source._brain);
}

Cat::~Cat() 
{
    std::cout << "Cat destructor" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(const Cat& source) 
{
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &source) 
    {
        type = source.type;
        _brain = new Brain(*source._brain);
    }
    return (*this);
}

void Cat::makeSound() const 
{
    std::cout << "Cat sound: Meoow!!" << std::endl;
}

void Cat::printIdeas() const
{
    _brain->showIdeas();
}
