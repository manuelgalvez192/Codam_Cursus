/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:07:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/17 12:07:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"
#include <iostream>

template <typename T>
void printInt(T i)
{
	std::cout << i << std::endl;
}

template <typename T>
void printConst(T const &x)
{
	std::cout << "[const] " << x << std::endl;
}

template <typename T>
void printNonConst(T &x)
{
	std::cout << "[non-const] " << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	x++;
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(array) / sizeof(array[0]);
	iter(array, length, printInt<int>);
	iter(array, length, printConst<int>);
	iter(array, length, printNonConst<int>);
	iter(array, length, increment<int>);
	iter(array, length, printInt<int>);
	return 0;
}
