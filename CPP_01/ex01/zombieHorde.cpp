/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:18:50 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/08 20:26:51 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0 || N > 1024)
		return (NULL);
	Zombie	*zombieHorde = new Zombie[N];
	while (N)
	{
		zombieHorde[--N].setName(name);
	}
	return (zombieHorde);
}