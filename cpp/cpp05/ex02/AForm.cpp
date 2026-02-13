/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:58:16 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/02/13 11:58:16 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"

AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150),
	gradeToExecute(150)
{

}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
	name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{

}

const std::string &AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();

	this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "Form need to be sign first";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form: " << form.getName() << ", Signed?: " << form.getIsSigned()
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute() << std::endl;
	
	return out;
}
