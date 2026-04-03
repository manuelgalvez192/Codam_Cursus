/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:02:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/11 16:50:29 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DiamondTrap.h"

int main()
{
	std::cout << "# -- TESTING DIAMOND_TRAP -- #\n";
	DiamondTrap M;
	DiamondTrap N("BOT_N");
	DiamondTrap O;
	DiamondTrap P(N);
	
	std::cout << "\n - Object builted - \n";
	
	M.attack("a enemy");
	N.attack("a enemy2");
	M.takeDamage(15);
	N.takeDamage(15);
	M.beRepaired(5);
	N.beRepaired(5);
	M.highFivesGuys();
	N.highFivesGuys();
	M.guardGate();
	N.guardGate();
	M.whoAmI();
	N.whoAmI();
	O = N;
	
	std::cout << "\n - All method tested - \n";
	
	return (0);
}