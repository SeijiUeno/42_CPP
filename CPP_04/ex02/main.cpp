/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:41 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:27:13 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void pure_virtual()
{
    AAnimal *cat = new Cat();
    cat->makeSound();
    delete cat;
}

void wrong_virtual()
{
    //AAnimal *wrong = new AAnimal();
}
int main(void)
{
    pure_virtual();
    wrong_virtual();
    
    return (0);
}
