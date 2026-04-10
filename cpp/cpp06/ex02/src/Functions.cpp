/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:12:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/10 19:12:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.h"
#include "A.h"
#include "B.h"
#include "C.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			std::cout << "Error generating random number" << std::endl;
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Identified B" << std::endl;
		}
		catch (std::bad_cast &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Identified C" << std::endl;
			}
			catch (std::bad_cast &e)
			{
				std::cout << "Error" << std::endl;
			}
		}
	}
}
