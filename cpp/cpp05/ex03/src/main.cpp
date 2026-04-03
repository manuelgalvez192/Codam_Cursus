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

#include "../header/Bureaucrat.h"
#include "../header/AForm.h"
#include "../header/ShrubberyCreationForm.h"
#include "../header/RobotomyRequestForm.h"
#include "../header/PresidentialPardonForm.h"
#include "../header/Intern.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	(void)rrf;

	delete rrf;
	
	return 0;
}
