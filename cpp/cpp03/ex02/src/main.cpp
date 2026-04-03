/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:02:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/08 17:09:37 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FragTrap.h"

int main()
{
	std::cout << "# -- TESTING FRAG_TRAP -- #\n";
	
	FragTrap E;
	FragTrap F("BOT_F");
	FragTrap G;
	FragTrap H(F);
	
	std::cout << "~ - Object builted - ~\n";
	
	E.attack("an enemy");
	F.attack("another enemy");
	E.takeDamage(15);
	F.takeDamage(15);
	E.beRepaired(5);
	F.beRepaired(5);
	E.highFivesGuys();
	F.highFivesGuys();
	G = F;
	
	std::cout << "~ - All method tested - ~\n";
	
	return (0);
}