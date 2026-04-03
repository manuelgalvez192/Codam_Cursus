/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:02:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/04 21:06:09 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScavTrap.h"

int main()
{
	std::cout << "# -- TESTING CLAP_TRAP -- #\n";
	ClapTrap A;
	ClapTrap B("BOT_B");
	ClapTrap C;
	ClapTrap D(B);
	std::cout << "~ - Object builted - ~\n";
	A.attack("an enemy");
	B.attack("another enemy");
	A.takeDamage(15);
	B.takeDamage(15);
	A.beRepaired(5);
	B.beRepaired(5);
	D.attack("another another enemy");
	C = B;
	std::cout << "~ - All method tested - ~\n";
	
	std::cout << "# -- TESTING SCAV_TRAP -- #\n";
	ScavTrap E;
	ScavTrap F("BOT_F");
	ScavTrap G;
	ScavTrap H(F);
	std::cout << "~ - Object builted - ~\n";
	E.attack("an enemy");
	F.attack("another enemy");
	E.takeDamage(15);
	F.takeDamage(15);
	E.beRepaired(5);
	F.beRepaired(5);
	E.guardGate();
	F.guardGate();
	G = F;
	std::cout << "~ - All method tested - ~\n";
	return (0);
}