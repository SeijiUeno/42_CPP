/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:04:35 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/07 17:40:57 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>

void	print_input_uppercase(char *input, bool first);

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
	{
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
	}
	else
	{
		while (++i < argc)
			print_input_uppercase(argv[i], i);
		std::cout << std::endl;
	}
	return (0);
}

void    print_input_uppercase(char *input, bool first)
{
	if (input == NULL)
		return ;
	if (!first == 1)
		std::cout << " ";
	for (int i = 0; input[i] != '\0'; i++)
		std::cout << (char)toupper(input[i]);
}
