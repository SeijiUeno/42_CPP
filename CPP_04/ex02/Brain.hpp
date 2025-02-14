/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:29 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 15:18:30 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    protected:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain &source);
        ~Brain();

        Brain &operator=(const Brain &source);
        std::string getIdea(int index) const;
    
        void setIdea(int index, const std::string &idea);
        void showIdeas() const;
};

#endif
