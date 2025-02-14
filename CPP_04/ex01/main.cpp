/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:41 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:12:03 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
    std::cout <<  " ========== ARRAY TEST ============" << std::endl;
    Animal *animals[2];
    
    animals[0] = new Dog();
    animals[0]->makeSound();
    animals[1] = new Cat();
    animals[1]->makeSound();

    delete animals[0];
    delete animals[1];
    
    std::cout <<  " ========== CAT IDEAS ============" << std::endl;

    Animal *animal2;
    animal2 = new Cat();
    animal2->makeSound();
    if (Cat* cat = dynamic_cast<Cat*>(animal2))
        cat->printIdeas();
    delete animal2;
    
    std::cout <<  " ========== DOG IDEAS ==========="  << std::endl;
    Animal *animal;

    animal = new Dog();
    animal->makeSound();
    if (Dog* dog = dynamic_cast<Dog*>(animal))
        dog->printIdeas();
    delete animal;
}
