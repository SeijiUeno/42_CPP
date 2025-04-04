/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotASed.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:17:02 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 12:54:56 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class NotASed
{
	private:
	std::fstream  _input;
	std::fstream _output;
	
	void			_replacing( const std::string& s1, const std::string& s2);
	
	public:
	NotASed( const std::string& input_file, const std::string& s1, const std::string& s2);
	~NotASed( void );
};


#endif