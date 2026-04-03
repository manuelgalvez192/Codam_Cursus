/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:26:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/08/04 16:26:26 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.h"

int main()
{
	Zombie *horde = zombieHorde(15, "Zombie");

	for (int i = 0; i < 15; i++)
	{
		horde[i].announce();
	}

	delete[] horde;

	return 0;
}