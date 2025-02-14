/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:33 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:30:53 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
private:
    Brain* _brain;

public:
    Cat();
    Cat(const Cat& source);
    virtual ~Cat();

    Cat& operator=(const Cat& source);

    void makeSound() const;
    void printIdeas() const;
};

#endif
