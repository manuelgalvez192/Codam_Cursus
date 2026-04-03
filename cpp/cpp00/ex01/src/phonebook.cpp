/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:15:21 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/09/01 19:27:41 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PhoneBook.h"

PhoneBook::PhoneBook() :
	contactCount(0),
	oldestContactIndex(0) {}

void PhoneBook::addContact(Contact contact)
{
	if (contactCount < MAX_CONTACTS)
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
	else
	{
		contacts[oldestContactIndex] = contact;
		oldestContactIndex = (oldestContactIndex + 1) % MAX_CONTACTS;
	}
}

void PhoneBook::searchContacts()
{
	std::string index;

	if (contactCount == 0)
	{
		std::cout << " - No hay contactos agregados." << std::endl;
		return ;
	}

	displayContacts();
	
	std::cout << "Introduce el indice del contacto que quieres ver: ";
	std::cin >> index;
	std::cin.ignore();

	if(!isdigit(index[0]) || index.length() > 1 || index >= "8")
	{
		std::cout << "\n - Entrada invalida.\n\tPor favor, introduce un numero entre 0 y 7\n" << std::endl;
		searchContacts();
		return ;
	}

	displayContactDetails(atoi(index.c_str()));
}

void PhoneBook::displayContacts()
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatString(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatString(contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatString(contacts[i].getNickname()) << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index)
{
	std::cout << " * Detalles del contacto: " << index << std::endl;
	std::cout << " * First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << " * Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << " * Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << " * Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << " * Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::formatString(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void PhoneBook::exitPhoneBook()
{
	std::cout << "Chao Pescao!" << std::endl;
}
