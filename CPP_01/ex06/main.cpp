/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:17:36 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 16:25:28 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr	<< "Usage: ./harlFilter <warning_level>\n"
					<< "Warnings: <INFO>, <DEBUG>, <WARNING>, <ERRROR>" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
