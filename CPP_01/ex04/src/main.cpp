/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:16:56 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 13:34:01 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/NotASed.hpp"
# include <cstdlib>

static void logError(int error)
{
	switch (error)
	{
	case 1:
		std::cerr	<< "\033[1;31m" <<"Error: The search string (s1) cannot be empty."
					<< "\033[0m" << std::endl;
		break;
	case 2:
		std::cerr 	<< "\033[1;31m" <<"Error: The replacement string (s2) is empty." 
					<< "\033[0m" << std::endl;
		break;
	default:
		std::cerr 	<< "\033[1;31m" <<"Error: The FileName is empty." 
					<< "\033[0m" << std::endl;
		break;
	}
	exit(1);
}
	
int	main( int argc, char **argv )
{
	if (argc != 4)
	{
		std::cerr	<< "\033[1;31m" <<"Use: ./SedIsForLosers <filename> <Replace_Target> <Replace_Value>"
					<< "\033[0m" << std::endl;
		exit(1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty())
		logError(3);
	if (s1.empty())
		logError(1);
	if (s2.empty())
		logError(2);

	NotASed	NotASed(filename, s1, s2);
	return (0);
}