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
		Zombie();
		Zombie(const std::string &name);
		~Zombie();
		void announce(void);
		void setName(const std::string &name);

	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);
