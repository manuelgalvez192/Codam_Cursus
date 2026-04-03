/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:19:59 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/09 21:10:51 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../header/Animal.h"
#include "../header/Dog.h"
#include "../header/Cat.h"

int main()
{
	std::cout << "\n----- ANIMALS -----\n" << std::endl;

    Brain NewBrain;
    NewBrain.setIdea(5, "I think");
    std::cout << "Idea 5 -> " << NewBrain.getIdea(5) << "\n";
    Cat cat;
    cat.getBrain()->setIdea(0, "I want fish");
    std::cout << "Cat's Brain Idea 0 -> " << cat.getBrain()->getIdea(0) << "\n";
    
    return 0;
}