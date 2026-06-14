/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:44:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/14 12:44:34 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : vector(other.vector), deque(other.deque)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vector = other.vector;
		deque = other.deque;
	}

	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);

		for (size_t j = 0; j < token.size(); j++)
		{
			if (!std::isdigit(token[j]))
				throw std::runtime_error("Error: invalid input: " + token);
		}

		int value;
		try
		{
			value = std::stoi(token);
		}
		catch (const std::exception& e)
		{
			throw std::runtime_error("Error: invalid input: " + token);
		}

		if (value < 0)
			throw std::runtime_error("Error: negative number: " + token);
		
		vector.push_back(value);
		deque.push_back(value);
	}

	if (vector.empty() || deque.empty())
		throw std::runtime_error("Error: empty container");
}

void PmergeMe::binaryInsertVector(std::vector<int> &vec, int value, int end)
{
	int left = 0;
	int right = end;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, value);
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> main;
	std::vector<int> pend;

	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			main.push_back(vec[i]);
			pend.push_back(vec[i + 1]);
		}
		else
		{
			main.push_back(vec[i + 1]);
			pend.push_back(vec[i]);
		}
	}

	bool hasNoPair = vec.size() % 2 != 0;
	int noPair = hasNoPair ? vec.back() : 0;

	sortVector(main);

	main.insert(main.begin(), pend[0]);

	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);
	while (jacobsthal.back() < (int)pend.size())
		jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);

	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t j = 0; j < jacobsthal.size(); j++)
	{
		int id = jacobsthal[j] - 1;
		if (id >= (int)pend.size())
			id = pend.size() - 1;

		for (int k = id; k >= 0; k--)
		{
			if (!inserted[k])
			{
				binaryInsertVector(main, pend[k], main.size());
				inserted[k] = true;
			}
		}
	}

	if (hasNoPair)
		binaryInsertVector(main, noPair, main.size());
	
	vec = main;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &deq, int value, int end)
{
    int left = 0;
    int right = end;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (deq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    deq.insert(deq.begin() + left, value);
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
    if (deq.size() <= 1)
        return;

    std::deque<int> main;
    std::deque<int> pend;

    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
        {
            main.push_back(deq[i]);
            pend.push_back(deq[i + 1]);
        }
        else
        {
            main.push_back(deq[i + 1]);
            pend.push_back(deq[i]);
        }
    }

    bool hasStraggler = deq.size() % 2 != 0;
    int straggler = hasStraggler ? deq.back() : 0;

    sortDeque(main);

    main.insert(main.begin(), pend[0]);

    std::deque<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < (int)pend.size())
        jacobsthal.push_back(jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2]);

    std::deque<bool> inserted(pend.size(), false);
    inserted[0] = true;

    for (size_t j = 0; j < jacobsthal.size(); j++)
    {
        int idx = jacobsthal[j] - 1;
        if (idx >= (int)pend.size())
            idx = pend.size() - 1;

        for (int k = idx; k >= 0; k--)
        {
            if (!inserted[k])
            {
                binaryInsertDeque(main, pend[k], main.size());
                inserted[k] = true;
            }
        }
    }

    if (hasStraggler)
        binaryInsertDeque(main, straggler, main.size());

    deq = main;
}

void PmergeMe::process(int argc, char **argv)
{
	parseInput(argc, argv);
	
	std::cout << "Before: ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	auto startVec = std::chrono::high_resolution_clock::now();
	sortVector(vector);
	auto endVec = std::chrono::high_resolution_clock::now();

	auto startDeq = std::chrono::high_resolution_clock::now();
	sortDeque(deque);
	auto endDeq = std::chrono::high_resolution_clock::now();

	std::cout << "After: ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	double vectorTime = std::chrono::duration<double, std::micro>(endVec - startVec).count();
double dequeTime = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vector.size()
				<< " elements with 'vector': " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size()
				<< " elements with 'deque': " << dequeTime << " us" << std::endl;
}
