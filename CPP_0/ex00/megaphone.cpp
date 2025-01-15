/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:04:35 by sueno-te          #+#    #+#             */
/*   Updated: 2025/01/14 21:44:52 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>

void	print_input_uppercase(char *input);

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
			print_input_uppercase(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}

void    print_input_uppercase(char *input)
{
	int		i = -1;
	static bool	isFirstString = 1;

	if (input == NULL)
		return ;
	if (!isFirstString)
		std::cout << " ";
	else
		isFirstString = 0;
	while (input[++i] != '\0')
		std::cout << (char)toupper(input[i]);
}
