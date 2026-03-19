/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:50:14 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/02/13 12:50:14 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("Default Target")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::cout << "Bbzbzbzzz..... Noises... Noises...\n" << std::endl;
	if(std::rand() % 2)
		std::cout << target << " has been robotomized successfully!\n" << std::endl;
	else
		std::cout << "Failed to robotomize " << target << ".\n" << std::endl;
}
