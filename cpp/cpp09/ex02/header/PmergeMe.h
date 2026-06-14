/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:37:33 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/14 12:37:33 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <string>
#include <iomanip>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void process(int argc, char **argv);

	private:
		std::vector<int> vector;
		std::deque<int> deque;

		void sortVector(std::vector<int> &vec);
		void binaryInsertVector(std::vector<int> &vec, int value, int end);
		void sortDeque(std::deque<int> &deq);
		void binaryInsertDeque(std::deque<int> &deq, int value, int end);
		void parseInput(int argc, char **argv);
};

