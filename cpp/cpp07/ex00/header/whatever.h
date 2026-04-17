/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:51:02 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/17 11:51:02 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	if (a == b)
	{
		std::cout << "Warning: Both values are equal. Returning the second value." << std::endl;
		return b;
	}

	return a < b ? a : b;
}

template <typename T>
T max(T a, T b)
{
	if (a == b)
	{
		std::cout << "Warning: Both values are equal. Returning the second value." << std::endl;
		return b;
	}

	return a > b ? a : b;
}