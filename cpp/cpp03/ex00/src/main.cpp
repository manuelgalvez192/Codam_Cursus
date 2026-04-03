/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:02:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/04 21:05:54 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ClapTrap.h"

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
	
	return 0;
}