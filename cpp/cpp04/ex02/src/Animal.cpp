/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:21:53 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/09 21:12:24 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.h"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.getType())
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.getType();
	}
	
	std::cout << "Animal assignment operator" << std::endl;
	
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
	