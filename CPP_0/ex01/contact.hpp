/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:29:43 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/07 16:14:13 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact 
{
	private:
		std::string nickName;
		std::string firstName;
		std::string lastName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		Contact(std::string nickName, std::string firstName, std::string lastName,
				std::string phoneNumber, std::string darkestSecret);
		// Getters
		std::string	getNickName() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		// Setters
		void setNickName(std::string nickName);
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
};

#endif