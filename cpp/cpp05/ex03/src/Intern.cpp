/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:04:54 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/03/19 21:04:54 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.h"

Intern::Intern()
{
	std::cout << "Intern created\n";
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

static AForm* CreatePardon(const std::string &target)
{
	std::cout << "Intern creates PresidentialPardonForm\n";
	return new PresidentialPardonForm(target);
}

static AForm* CreateRobotomy(const std::string &target)
{
	std::cout << "Intern creates RobotomyRequestForm\n";
	return new RobotomyRequestForm(target);
}

static AForm* CreateShrubbery(const std::string &target)
{
	std::cout << "Intern creates ShrubberyCreationForm\n";
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string FormName, const std::string Target)
{

    const std::string FormOption[] = 
    {
        "shrubberry request",
        "robotomy request",
        "presidential request"
    };

    AForm* (*functions[])(const std::string&) = 
    {
        CreateShrubbery, 
        CreateRobotomy, 
        CreatePardon
    };

    for(int i = 0; i < 3; i++)
    {
        if(FormName == FormOption[i])
            return(functions[i](Target));
    }
    return (NULL); 
}
