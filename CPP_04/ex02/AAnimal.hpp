/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:26 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:27:53 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal 
{
protected:
    std::string type;
    
public:
    AAnimal();
    AAnimal(const AAnimal& source);
    AAnimal(const std::string& type);
    virtual ~AAnimal();
    
    AAnimal& operator=(const AAnimal& source);
    std::string getType() const;
    void setType(std:: string newType);
    
    virtual void makeSound() const = 0;
};

#endif
