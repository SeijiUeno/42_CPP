/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:43:49 by sueno-te          #+#    #+#             */
/*   Updated: 2025/01/27 18:54:17 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string nickName, std::string firstName, std::string lastName,
				std::string phoneNumber, std::string darkestSecret)
				: nickName(nickName), firstName(firstName), lastName(lastName),
     			phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

// Getters
std::string Contact::getNickName() const { return (nickName); }
std::string Contact::getFirstName() const { return (firstName); }
std::string Contact::getLastName() const { return (lastName); }
std::string Contact::getPhoneNumber() const { return (phoneNumber); }
std::string Contact::getDarkestSecret() const { return (darkestSecret); }

// Setters
void Contact::setNickName(std::string nickName) { this->nickName = nickName; }
void Contact::setFirstName(std::string firstName) { this->firstName = firstName; }
void Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void Contact::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }