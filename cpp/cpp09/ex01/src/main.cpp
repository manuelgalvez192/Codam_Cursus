/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:31:31 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/11 17:31:31 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"

int main(int argc, char* argv[])
{
	RPN rpn;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}

	try
	{
		rpn.process(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
