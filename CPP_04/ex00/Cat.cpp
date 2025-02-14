/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:31 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:17:56 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat& source) : Animal(source)
{
    std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& source)
{
    std::cout << "Cat assignment operator " << std::endl;
    if (this != &source)
        type = source.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "cat sound: Meoow!!" << std::endl;
}
