/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:16:56 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 12:06:30 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/NotASed.hpp"

static void logError(const std::string& message)
{
    std::cerr << "\033[1;31m" << "Error: " << message << "\033[0m" << std::endl;
	return ;
}

int	main( int argc, char *argv[] )
{
	if (argc != 4)
	{
		logError("Use: ./SedIsForLosers <filename> <s1> <s2>");;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
   	logError("The search string (s1) cannot be empty.");
    return (1);
	}
	NotASeed	new_sed(filename, s1, s2);
	return (0);
}