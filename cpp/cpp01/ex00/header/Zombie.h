/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:26:28 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/08/04 16:26:28 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(const std::string &name);
		~Zombie();
		void announce(void);

	private:
		std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );
