/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:41 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 13:46:33 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>

int main(void)
{
    const Animal *ObjAnimal = new Animal();
    
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout <<cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    ObjAnimal->makeSound();

    delete ObjAnimal;
    delete cat;
    delete dog;
    
    std::cout << "=========== wrong animal ============" << std::endl;

    const WrongAnimal *ObjWAnimal = new WrongAnimal();
    
    const WrongAnimal *wrong_cat = new WrongCat();
    std::cout << wrong_cat->getType() << " " << std::endl;
    ObjWAnimal->makeSound();
    std::cout << " WrongCat Sound: " << std::endl;
    wrong_cat->makeSound();

    delete ObjWAnimal;
    delete wrong_cat;

    std::cout << "=========== wrong Cat ============" << std::endl;
  
    const WrongCat *Wwrong_cat = new WrongCat();
    std::cout << Wwrong_cat->getType() << " " << std::endl;
    std::cout << " WrongCat Sound: " << std::endl;
    Wwrong_cat->makeSound();

    delete Wwrong_cat;
}
