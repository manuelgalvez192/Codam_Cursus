/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:05:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/05 19:05:04 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"
#include <iostream>
#include <list>

void testSubject()
{
	std::cout << "=== Test: Subject Code ===\n" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

void testIterators(void)
{
	std::cout << "\n=== Test: Iterators (begin/end) ===\n" << std::endl;
	
	MutantStack<int> mstack;

	for (int i = 0; i < 10; ++i)
		mstack.push(i);

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;
}

void testReverseIterators(void)
{
	std::cout << "\n=== Test: Reverse Iterators (rbegin/rend) ===\n" << std::endl;
	
	MutantStack<int> mstack;

	for (int i = 0; i < 10; ++i)
		mstack.push(i);

	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << std::endl;
}

void testConstIterators(void)
{
	std::cout << "\n=== Test: Const Iterators (begin/end) ===\n" << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	const MutantStack<int>& constMstack = mstack;

	for (MutantStack<int>::const_iterator it = constMstack.begin(); it != constMstack.end(); ++it)
		std::cout << *it << std::endl;
}

void testComparisonWithList(void)
{
	std::cout << "\n=== Test: Comparison with std::list ===\n" << std::endl;

	MutantStack<int> mstack;
	std::list<int> lst;

	for (int i = 0; i < 10; ++i)
	{
		mstack.push(i);
		lst.push_back(i);
	}

	std::cout << "MutantStack contents:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nstd::list contents:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;
}

int main(void)
{
	testSubject();
	testIterators();
	testReverseIterators();
	testConstIterators();
	testComparisonWithList();

	return (0);
}