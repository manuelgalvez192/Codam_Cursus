/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:32:59 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/17 02:32:59 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PhoneBook.h"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while(true)
	{
		std::cout << "Introduce un comando (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			Contact contact;
			contact.setFirstName();
			contact.setLastName();
			contact.setNickname();
			contact.setPhoneNumber();
			contact.setDarkestSecret();
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
		{
			phoneBook.exitPhoneBook();
			break ;
		}
		else
			std::cout << " - Comando invalido. Por favor, usa ADD, SEARCH o EXIT." << std::endl;
	}
	return 0;
}
