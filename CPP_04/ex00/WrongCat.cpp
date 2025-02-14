/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:51 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:18:52 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal(source)
{
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& source)
{
    std::cout << "WrongCat assignment operator" << std::endl;
    if (this != &source)
        type = source.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "cat sound: Meoow!!" << std::endl;
}
