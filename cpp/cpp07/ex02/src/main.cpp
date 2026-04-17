/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:37:22 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/17 13:37:22 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"
#include <iostream>

int main()
{
	// default constructor
	std::cout << "=== Default constructor ===" << std::endl;
	Array<int> defaultArr;
	std::cout << "Size: " << defaultArr.size() << std::endl;

	// size constructor
	std::cout << "\n=== Size constructor ===" << std::endl;
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i;

	std::cout << "Array contents: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// copy constructor
	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> copyArr(arr);
	std::cout << "Copy array: ";
	for (unsigned int i = 0; i < copyArr.size(); i++)
		std::cout << copyArr[i] << " ";
	std::cout << std::endl;

	copyArr[0] = 99;
	std::cout << "After modifying copy[0] to 99:" << std::endl;
	std::cout << "Original: " << arr[0] << ", Copy: " << copyArr[0] << std::endl;

	// Asign operator
	std::cout << "\n=== Asign operator ===" << std::endl;
	Array<int> assignArr(3);
	assignArr[0] = 11;
	assignArr[1] = 12;
	assignArr[2] = 13;
	std::cout << "Array before assignment: ";
	for (unsigned int i = 0; i < assignArr.size(); i++)
		std::cout << assignArr[i] << " ";
	std::cout << std::endl;

	assignArr = arr;
	std::cout << "Array after assignment: ";
	for (unsigned int i = 0; i < assignArr.size(); i++)
		std::cout << assignArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Exception test (index out of range) ===" << std::endl;
	try
	{
		std::cout << arr[10] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
