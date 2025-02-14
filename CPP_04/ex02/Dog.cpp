/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:36 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:31:15 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include <iostream>

Dog::Dog(void): AAnimal("Dog"), _brain(new Brain())
{
    std::cout << "Dog : constructor!" << std::endl;
    for (int i = 0;  i < 100; i++)
         _brain->setIdea(i, "I want meat!");
}

Dog::~Dog(void)
{
    std::cout << "Dog : destructor!" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &source): AAnimal(source)
{
    std::cout << "Dog : Copy constructor called." << std::endl;
    _brain = new Brain(*source._brain);
}

Dog &Dog::operator=(const Dog &source)
{
    std::cout << "Dog: assignment operator called." << std::endl;
    if (this != &source)
    {
        type = source.type;
        _brain = new Brain(*source._brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout <<"Dog Makesound: Woof!" << std::endl;
}

void Dog::printIdeas() const
{
    _brain->showIdeas();
}

