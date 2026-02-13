/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:41:08 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/01/28 18:40:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{

	std::srand(std::time(NULL));

	try
	{
		std::cout << "----------  Shrubbery Request Form ----------\n" << std::endl;

		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm form;

		//form.execute(bob); // This will throw an exception because the form is not signed yet

		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form);
		std::cout << form << std::endl;

		bob.executeForm(form);

		std::cout << "----------  END Shrubbery ----------\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "----------  Robotomy Request Form ----------\n" << std::endl;
		Bureaucrat alice("Alice", 41);
		RobotomyRequestForm form("Target1");

		//form.execute(alice); // This will throw an exception because the form is not signed yet

		std::cout << alice << std::endl;
		std::cout << form << std::endl;

		alice.signForm(form);
		std::cout << form << std::endl;

		alice.executeForm(form);

		std::cout << "----------  END Robotomy ----------\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "----------  Presidential Pardon Form ----------\n" << std::endl;
		Bureaucrat charlie("Charlie", 15);
		PresidentialPardonForm form;

		//form.execute(charlie); // This will throw an exception because the form is not signed yet

		std::cout << charlie << std::endl;
		std::cout << form << std::endl;

		charlie.signForm(form);
		std::cout << form << std::endl;

		charlie.executeForm(form);

		std::cout << "----------  END Presidential ----------\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
