/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:53:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/08/25 00:53:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Harl.h"

int main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	Harl	angry_client;
	
	angry_client.complain(argv[1]);

	return(0);
}
