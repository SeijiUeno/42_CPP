/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:17:21 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 16:33:10 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>
# include <string>

# define DEBUG "[DEBUG]\nI love having extra bacon for my " \
	"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"

# define INFO "[INFO]\nI cannot believe adding extra bacon costs more " \
	"money. You didn’t put enough bacon in my burger! " \
	"If you did, I wouldn’t be asking for more!"

# define WARNING "[WARNING]\nI think I deserve to have some extra " \
	"bacon for free. I’ve been coming for years whereas you started " \
	"working here since last month."

# define ERROR "[ERROR]\nThis is unacceptable! " \
	"I want to speak to the manager now."

class Harl
{
	private:
		typedef void (Harl::*function_ptr)();

		void	debug();
		void	info();
		void	warning();
		void	error();
	
	public:
		Harl();
		~Harl();
		
		void	complain(std::string level);
};

#endif