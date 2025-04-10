/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:26 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:21:29 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"


AAnimal::AAnimal(void) : type("AAnimal")
{
    std::cout << "AAnimal: Default constructor." << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type)
{
    std::cout << "AAnimal: named constructor." << std::endl;
}
AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal: Destructor." << std::endl;
}

AAnimal::AAnimal(const AAnimal &source)
{
    std::cout << "AAnimal Copy constructor." << std::endl;
    *this = source;
}

AAnimal &AAnimal::operator=(const AAnimal &source)
{
    std::cout << "Copy assignment operator." << std::endl;
    if (this != &source)
        type = source.getType();

    return (*this);
}


std::string AAnimal::getType(void) const
{
    return this->type;
}

void AAnimal::setType(std::string newType)
{
    this->type = newType;
}
