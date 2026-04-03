/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:37:09 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/08/05 21:37:09 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Weapon.h"

Weapon::Weapon(std::string type) :
	type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType()
{
	return this->type;
}
void Weapon::setType(std::string type)
{
	this->type = type;
}
