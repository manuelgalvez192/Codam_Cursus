/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:22:11 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/17 01:22:11 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		void setFirstName();
		std::string getFirstName() const;
		void setLastName();
		std::string getLastName() const;
		void setNickname();
		std::string getNickname() const;
		void setPhoneNumber();
		std::string getPhoneNumber() const;
		void setDarkestSecret();
		std::string getDarkestSecret() const;
};
