/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:44 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 16:21:42 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
    std::cout << "Brain: constructor!" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "idea -> Default.";
}

Brain::Brain(const Brain &source)
{
    std::cout << "Brain : copy constructor." << std::endl;
    for (int i = 0; i < 100; i++)
            _ideas[i] = source._ideas[i];
}

Brain &Brain::operator=(const Brain &source)
{
    std::cout << "Brain : assignment operator." << std::endl;
    if (this != &source)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = source._ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return _ideas[index];
    else
    {
        std::cout << "Error: Invalid index." << std::endl;
        return ("");
    }
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
    else
    {
        std::cout << "Error: Invalid index." << std::endl;
        return ;
    }
}


void Brain::showIdeas() const
{
    for (int i = 0; i < 100; i++)
        std::cout << "Index : " << i + 1 << "  " << _ideas[i] << std::endl;
}


Brain::~Brain(void)
{
    std::cout << "Brain: destructor!!" << std::endl;
}
