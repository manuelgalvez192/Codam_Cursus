/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:16:13 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/09/01 16:43:24 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Contact.h"

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		int contactCount;
		int oldestContactIndex;
	public:
		PhoneBook();
		void addContact(Contact contact);
		void searchContacts();
		void displayContacts();
		void displayContactDetails(int index);
		std::string formatString(const std::string &str) const;
		void exitPhoneBook();
};
