/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:19:59 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/11/08 19:55:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../header/Animal.h"
#include "../header/Dog.h"
#include "../header/Cat.h"
#include "../header/WrongAnimal.h"
#include "../header/WrongCat.h"

int main()
{
	std::cout << "\n----- ANIMALS -----\n" << std::endl;
	
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete i;
    delete j;

	std::cout << "\n----- WRONG ANIMALS -----\n" << std::endl;

	const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();
    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    b->makeSound();
    a->makeSound();
    
    delete a;
    delete b;
    
    return 0;
}