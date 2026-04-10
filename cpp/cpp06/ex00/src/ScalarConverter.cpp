/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:03:35 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/04/03 17:03:35 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.h"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

static bool isSpecialLiteral(const std::string& literal)
{
	return literal == "nan" || literal == "nanf" ||
		   literal == "+inf" || literal == "+inff" ||
		   literal == "-inf" || literal == "-inff";
}

static bool isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

static bool isInt(const std::string& literal)
{
	size_t i = 0;
	int digitCount = 0;

	if (literal.length() == 0)
		return false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	while(i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		digitCount++;
		i++;
	}
	return digitCount > 0;
}

static bool isFloat(const std::string& literal)
{
	size_t i = 0;
    bool hasDecimalPoint = false;
    size_t len = literal.length();

    if (len == 0)
        return false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;

    if (i >= len)
        return false;

    size_t digitCount = 0;
    while (i < len - 1)
    {
        if (literal[i] == '.')
        {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        }
        else if (std::isdigit(literal[i]))
            digitCount++;
        else
            return false;
        i++;
    }

    return (literal[len - 1] == 'f' && digitCount > 0);
}

static bool isDouble(const std::string& literal)
{
	size_t i = 0;
	bool hasDecimalPoint = false;
	size_t len = literal.length();

	if (len == 0)
		return false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	if (i >= len)
		return false;

	size_t digitCount = 0;
	while (i < len)
	{
		if (literal[i] == '.')
		{
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		}
		else if (std::isdigit(literal[i]))
			digitCount++;
		else
			return false;
		i++;
	}

	return digitCount > 0;
}

static void convertSpecialLiteral(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static void convertChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void convertInt(int value)
{
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

static void convertFloat(float value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (value < 0 || value > 127)
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(static_cast<int>(value)))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
	}

	if (value == static_cast<float>(static_cast<int>(value)))
        std::cout << "float: " << value << ".0f" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;

    double d = static_cast<double>(value);
	
    if (d == static_cast<double>(static_cast<int>(d)))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void convertDouble(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (value < 0 || value > 127)
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(static_cast<int>(value)))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
	}

	float f = static_cast<float>(value);
	if (std::fmod(f, 1.0f) == 0.0f)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (std::fmod(value, 1.0) == 0.0)
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isSpecialLiteral(literal))
		convertSpecialLiteral(literal);
	else if (isChar(literal))
		convertChar(literal[0]);
	else if (isInt(literal))
	{
		try
		{
			convertInt(std::stoi(literal));
		}
		catch(std::exception& e)
		{
			std::cout << "Invalid literal" << std::endl;
		}
	}
	else if (isFloat(literal))
		convertFloat(std::stof(literal));
	else if (isDouble(literal))
		convertDouble(std::stod(literal));
	else
		std::cout << "Invalid literal: " << literal << std::endl;
}
