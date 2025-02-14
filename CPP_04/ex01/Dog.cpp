/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:36 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:21:10 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include <iostream>

Dog::Dog(void): Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog : constructor!" << std::endl;
    for (int i = 0;  i < 100; i++)
         _brain->setIdea(i, "I love meat! and Treats!");
}

Dog::~Dog(void)
{
    std::cout << "Dog : destructor!" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &source): Animal(source)
{
    std::cout << "Dog : Copy constructor." << std::endl;
    _brain = new Brain(*source._brain);
}

Dog &Dog::operator=(const Dog &source)
{
    std::cout << "Dog: assignment operator." << std::endl;
    if (this != &source)
    {
        type = source.type;
        _brain = new Brain(*source._brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout <<"Dog Makesound: Wooof!!" << std::endl;
}

void Dog::printIdeas() const
{
    _brain->showIdeas();
}

