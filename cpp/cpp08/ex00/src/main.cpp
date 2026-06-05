/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:34:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/03 18:34:04 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <list>
#include <iostream>
#include <deque>

void vector()
{
	std::cout << "\n=== Test: Vector ===" << std::endl;
	
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void list()
{
	std::cout << "\n=== Test: List ===" << std::endl;
	
	std::list<int> l;
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	try
	{
		std::list<int>::iterator it = easyfind(l, 5);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void deque()
{
	std::cout << "\n=== Test: Deque ===" << std::endl;
	
	std::deque<int> d;
	d.push_back(7);
	d.push_back(7);
	d.push_back(7);

	try
	{
		std::deque<int>::iterator it = easyfind(d, 7);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void emptyContainer()
{
	std::cout << "\n=== Test: Empty Container ===" << std::endl;
	
	std::vector<int> v;

	try
	{
		std::vector<int>::iterator it = easyfind(v, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void notFound()
{
	std::cout << "\n=== Test: Value Not Found ===" << std::endl;
	
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 4);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	vector();
	list();
	deque();
	emptyContainer();
	notFound();

	return 0;
}
