/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:38:58 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/10 19:38:58 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.h"

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	return 0;
}
