/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:02 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/11 09:59:14 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_fixed;
		static const int	_fractional = 8;
	public:
		Fixed();
		Fixed( Fixed const &source);
		~Fixed();
		
		Fixed& 	operator=( Fixed const& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif