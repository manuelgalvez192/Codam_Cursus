/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:31:29 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/11 17:31:29 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		exchangeRates = other.exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::LoadData(const std::string& inputFile)
{
	std::ifstream file(inputFile);
	if (!file.is_open())
	{
		throw std::runtime_error("Error: Could not open file: " + inputFile);
	}

	std::string saveLine;
	std::getline(file, saveLine);

	while (std::getline(file, saveLine))
	{
		std::istringstream iss(saveLine);
		std::string date;
		std::string rateStr;

		if (!std::getline(iss, date,  ',') || !std::getline(iss, rateStr))
		{
			std::cerr << "Error: Invalid line: " << saveLine << std::endl;
			continue;
		}
	
		date.erase(date.find_last_not_of(" ") + 1);
		rateStr.erase(0, rateStr.find_first_not_of(" "));

		try
		{
			exchangeRates[date] = std::stod(rateStr);
		} catch (const std::exception&) {
			std::cerr << "Error: Invalid rate number: " << rateStr << std::endl;
		}
	}
}

void BitcoinExchange::ProcessInput(const std::string& inputFile)
{
	std::ifstream file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file: " + inputFile);

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr))
		{
			std::cerr << "Error: Invalid line: " << line << std::endl;
			continue;
		}

		date.erase(date.find_last_not_of(" ") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" "));

		double value;
		try
		{
			value = std::stod(valueStr);
		} catch (const std::exception&)
		{
			std::cerr << "Error: Invalid value number: " << valueStr << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: Negative number not allowed: " << value << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: Number too large" << std::endl;
			continue;
		}

		std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);
		if (it == exchangeRates.end() || it->first != date)
		{
			if (it == exchangeRates.begin())
			{
				std::cerr << "Error: No exchange rate available for date: " << date << std::endl;
				continue;
			}
			--it;
		}

		double rate = it->second;
		double result = value * rate;

		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
	}
}