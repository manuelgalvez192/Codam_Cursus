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

#include "Span.h"
#include <numeric>

void testSubject()
{
	std::cout << "\n=== Test: Basic (Subject Code) ===\n";

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testAddNumberOverFlow()
{
	std::cout << "\n=== Test: Add Number Overflow ===\n";

	Span sp = Span(3);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);

	try
	{
		sp.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception: " << e.what() << std::endl;
	}
}

void testNotEnoughNumbersShortest()
{
	std::cout << "\n=== Test: Not Enough Numbers for Shortest Span ===\n";

	Span sp = Span(3);
	sp.addNumber(1);

	try
	{
		sp.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception: " << e.what() << std::endl;
	}
}

void testNotEnoughNumbersLongest()
{
	std::cout << "\n=== Test: Not Enough Numbers for Longest Span ===\n";

	Span sp = Span(3);
	sp.addNumber(1);

	try
	{
		sp.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception: " << e.what() << std::endl;
	}
}

void testAddSortedNumbersRange()
{
	std::cout << "\n=== Test: Add Sorted Numbers Range ===\n";

	Span sp = Span(5);
	std::vector<int> sortedNumbers = {1, 2, 3, 4, 5};
	sp.addNumbers(sortedNumbers.begin(), sortedNumbers.end());

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testAddNumbersRangeOverflow()
{
	std::cout << "\n=== Test: Add Numbers Range Overflow ===\n";

	Span sp = Span(5);
	std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

	try
	{
		sp.addNumbers(numbers.begin(), numbers.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected exception: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment()
{
	std::cout << "\n=== Test: Copy Constructor and Assignment Operator ===\n";

	Span sp1 = Span(5);
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);

	Span sp2(sp1); // Copy constructor
	Span sp3(2); // Create an empty Span with different size
	sp3 = sp1; // Assignment operator

	std::cout << "sp1 Shortest Span: " << sp1.shortestSpan() << std::endl;
	std::cout << "sp2 Shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "sp3 Shortest Span: " << sp3.shortestSpan() << std::endl;
}

void testLargeSpan()
{
	std::cout << "\n=== Test: Large Span ===\n";

	Span sp = Span(10000);
	
	std::vector<int> values(10000);
	std::iota(values.begin(), values.end(), 0); //fill the range with consecutive values

	sp.addNumbers(values.begin(), values.end());

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

int main()
{
	srand(time(NULL));

	testSubject();
	testAddNumberOverFlow();
	testNotEnoughNumbersShortest();
	testNotEnoughNumbersLongest();
	testAddSortedNumbersRange();
	testAddNumbersRangeOverflow();
	testCopyAndAssignment();
	testLargeSpan();

	return (0);
}