/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:38:13 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/03 18:38:13 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);

		template <typename InputIt>
		void addNumbers(InputIt first, InputIt last)
		{
			unsigned int distance = std::distance(first, last);
			if (numbers.size() + distance > N)
				throw std::runtime_error("Too many numbers to add");
			numbers.insert(numbers.end(), first, last);
		}

		int shortestSpan() const;
		int longestSpan() const;

	private:
		unsigned int N;
		std::vector<int> numbers;
};
