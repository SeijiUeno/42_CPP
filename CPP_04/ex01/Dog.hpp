/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:39 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:18:30 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

class Dog: public Animal
{
    private:
        Brain *_brain;
    
    public:
        Dog();
        Dog(const Dog &source);
        virtual ~Dog(void);

        Dog &operator=(const Dog &source);
        void makeSound() const;
        void printIdeas() const;
};

#endif
