/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:26:23 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/07 16:16:58 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
	private:
		Contact contactList[8];
		int		contactCount;
		int		contactOldest;

		void	displayContact(int	index) const;

	public:
		PhoneBook();

		void	phoneBook_ADD();
		void	phoneBook_SEARCH() const;
};

#endif