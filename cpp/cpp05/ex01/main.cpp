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

#include "Form.h"
#include "Bureaucrat.h"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		
		Form form1("Form A", 1, 1);
		std::cout << form1 << std::endl;
		bob.signForm(form1);
		std::cout << form1 << std::endl;
		
		bob.incrementGrade();
		std::cout << bob << std::endl;

		bob.signForm(form1);
		std::cout << form1 << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
