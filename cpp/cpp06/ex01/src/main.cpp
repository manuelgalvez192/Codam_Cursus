/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:56:37 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/10 18:56:37 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <iostream>

int main()
{
	Data data;
	data.name = "Manu";
	data.age = 25;
	uintptr_t raw;

	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

	raw = Serializer::serialize(&data);

	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;
	std::cout << "Data:" << std::endl;
	std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

	data = *Serializer::deserialize(raw);

	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

	return 0;
}
