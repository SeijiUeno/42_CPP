/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:53:29 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/14 12:44:19 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& source);
		virtual ~Animal();

		Animal& 		operator=(const Animal & source);
		std::string		getType() const;

		void setType(std:: string newType);
		virtual void	makeSound() const;

};

#endif

