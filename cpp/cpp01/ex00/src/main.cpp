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
	Zombie *zombie1 = newZombie("zombie1");
	zombie1->announce();
	delete zombie1;

	Zombie zombie2("Zombie2");
	
	randomChump("randomZombie");

	return 0;
}