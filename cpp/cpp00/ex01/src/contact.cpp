/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:22:59 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/17 02:22:59 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Contact.h"

Contact::Contact() : 
	firstName(""),
	lastName(""),
	nickname(""),
	phoneNumber(""),
	darkestSecret("") {}

void Contact::setFirstName()
{
	std::cout << "Introduce el nombre: ";
	std::getline(std::cin, firstName);
	if (firstName.empty())
	{
		std::cout << " - El nombre no puede estar vacio." << std::endl;
		setFirstName();
	}
}

std::string Contact::getFirstName() const
{
	return firstName;
}

void Contact::setLastName()
{
	std::cout << "Introduce el apellido: ";
	std::getline(std::cin, lastName);
	if (lastName.empty())
	{
		std::cout << " - El apellido no puede estar vacio." << std::endl;
		setLastName();
	}
}

std::string Contact::getLastName() const
{
	return lastName;
}

void Contact::setNickname()
{
	std::cout << "Introduce el apodo: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << " - El apodo no puede estar vacio." << std::endl;
		setNickname();
	}
}

std::string Contact::getNickname() const
{
	return nickname;
}

void Contact::setPhoneNumber()
{
	std::cout << "Introduce el numero de telefono: ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty())
	{
		std::cout << " - El numero de telefono no puede estar vacio." << std::endl;
		setPhoneNumber();
	}
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			std::cout << " - El numero de telefono solo puede contener digitos." << std::endl;
			setPhoneNumber();
			return ;
		}
	}
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

void Contact::setDarkestSecret()
{
	std::cout << "Introduce el secreto mas oscuro: ";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
	{
		std::cout << " - El secreto no puede estar vacio." << std::endl;
		setDarkestSecret();
	}
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
