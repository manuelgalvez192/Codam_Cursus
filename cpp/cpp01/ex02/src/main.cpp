/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:52:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/08/04 17:52:04 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string *stringPtr = &name;
	std::string &stringRef = name;

	std::cout << "The memory address of the string variable: " << &name << std::endl;
	std::cout << "The memory address held by stringPtr: " << stringPtr << std::endl;
	std::cout << "The memory address held by stringRef: " << &stringRef << std::endl;

	std::cout << "The value of the string variable: " << name << std::endl;
	std::cout << "The value pointed to by stringPtr: " << *stringPtr << std::endl;
	std::cout << "The value pointed to by stringRef: " << stringRef << std::endl;

}