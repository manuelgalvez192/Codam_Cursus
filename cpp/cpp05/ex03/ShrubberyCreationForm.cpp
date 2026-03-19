/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:14:58 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/02/13 12:14:58 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("Default Target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outFile((target + "_shrubbery").c_str());
	if (!outFile)
	{
		std::cerr << "Error: " << target + "_shrubbery could not be created." << std::endl;
		return ;
	}

	outFile << "    oxoxoo    ooxoo  \n";
    outFile << " ooxoxo oo  oxoxooo  \n";
    outFile << "oooo xxoxoo ooo ooox \n";
    outFile << "oxo o oxoxo  xoxxoxo \n";
    outFile << "  oxo xooxoooo o ooo \n";
    outFile << "    ooo\\oo\\  /o/o  \n";
    outFile << "        \\  \\/ /    \n";
    outFile << "         |   /       \n";
    outFile << "         |  |        \n";
    outFile << "         |  |        \n";
    outFile << "         |  |        \n";
    outFile << "         |  |        \n";
    outFile << "  ______/____\\____  \n";
    outFile.close();
}