/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:04:56 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/03/19 21:04:56 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(const std::string FormName, const std::string Target);
};
