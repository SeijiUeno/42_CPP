/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:26:18 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/07 17:48:23 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phoneBook.hpp"
# include <iostream>
# include <iomanip>
# include <limits>

static bool validatePhoneNumber(std::string& phoneNumber)
{
	if (!phoneNumber.empty())
		return(false);
	return(true);
}

std::string getValidPhoneNumber()
{
	std::string phoneNumber;

	while (true)
	{
		std::cout << "Input the phone number (only digits allowed): ";
		std::getline(std::cin, phoneNumber);
		if (validatePhoneNumber(phoneNumber)) {
			break;
		} else {
			std::cout << "Invalid phone number. Please enter a valid phone number with only digits.\n";
		}
	}
	return (phoneNumber);
}

static std::string	truncateString(const std::string& str, size_t maxLength)
{
	if (str.length() > maxLength) 
	{
		return (str.substr(0, maxLength - 1) + ".");
	}
	return (str);
}

static void displayContactTableHeader()
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "\n";
	std::cout	<< "--------------------------------------------\n";
}

static void displayContactTableRow(const Contact& contact, int index)
{
    std::cout	<< std::setw(10) << index << "|"
				<< std::setw(10) << truncateString(contact.getFirstName(), 10) << "|"
				<< std::setw(10) << truncateString(contact.getLastName(), 10) << "|"
				<< std::setw(10) << truncateString(contact.getNickName(), 10) << "\n";
}

// class 

PhoneBook::PhoneBook() : contactCount(0), contactOldest(0) {}

void	PhoneBook::phoneBook_ADD()
{
	std::string	nickName, firstName, lastName, phoneNumber, darkestSecret;

	std::cout << "Input the nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Input first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Input last name: ";
	std::getline(std::cin, lastName);
	
    while (true)
	{
        std::cout << "Input the phone number: ";
        std::getline(std::cin, phoneNumber);

        if (validatePhoneNumber(phoneNumber)) {
            break;
        } else {
            std::cout << "Invalid phone number. Please enter only digits.\n";
        }
    }
	
	std::cout << "Input the darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (nickName.empty() || firstName.empty() || lastName.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: All fields must be filled! The Contact has NOT BEEN ADDED.\n";
		return ;
	}

    Contact phoneBook_ADD(firstName, lastName, nickName, phoneNumber, darkestSecret);

    if (contactCount < 8) {
        contactList[contactCount] = phoneBook_ADD;
        contactCount++;
    } else {
        contactList[contactOldest] = phoneBook_ADD;
        contactOldest = (contactOldest + 1) % 8;
		std::cout << "Contact added successfully! - Warning: One Contact lost\n";
    }

    std::cout << "Contact added successfully!\n";
}

void PhoneBook::phoneBook_SEARCH() const
{
	std::string	temp;
	int			index;

	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return ;
	}
	displayContactTableHeader();

	for (int i = 0; i < contactCount; i++) {
		displayContactTableRow(contactList[i], i + 1);
	}

	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;
	if (std::cin.fail()) 
	{
		std::cout << "Invalid input. Please enter a valid index.\n";
		std::cin.clear();
		std::getline(std::cin, temp);
		return ;
	}
	std::getline(std::cin, temp);

	if (index >= 0 && index < contactCount)
		displayContact(index);
	else 
		std::cout << "Invalid index. Please enter a number between 0 and " << contactCount - 1 << ".\n";
}

void PhoneBook::displayContact(int index) const
{
	std::cout	<< "First Name: " << contactList[index].getFirstName() << "\n"
				<< "Last Name: " << contactList[index].getLastName() << "\n"
				<< "Nickname: " << contactList[index].getNickName() << "\n"
				<< "Phone Number: " << contactList[index].getPhoneNumber() << "\n"
				<< "Darkest Secret: " << contactList[index].getDarkestSecret() << "\n";
}
