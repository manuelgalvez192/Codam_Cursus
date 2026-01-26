/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:20:54 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/01/26 21:20:54 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw std::out_of_range("Grade too high");
	if (grade > 150)
		throw std:out_of_range("Grade too low");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != other)
	{
		this->grade = other.grade;
	}

	return *this;
}

Bureuacrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat__getGrade() const
{
	return this->grade;
}

void Bureuacrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw std::out_of_range("Grade too high");

	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw std::out_of_range("Grade too low");

	this->grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
