/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:00:37 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/13 17:00:37 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : stack(other.stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		stack = other.stack;
	}

	return *this;
}

RPN::~RPN()
{
}

void RPN::push(int value)
{
	stack.push(value);
}

int RPN::pop()
{
	if (stack.empty())
	{
		throw std::runtime_error("Error: Stack is empty");
	}

	int value = stack.top();
	stack.pop();
	return value;
}

void RPN::process(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands for operation");

			int b = pop();
			int a = pop();

			if (token == "+")
				push(a + b);
			else if (token == "-")
				push(a - b);
			else if (token == "*")
				push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				push(a / b);
			}
		}
		else
		{
			try
			{
				int value = std::stoi(token);
				push(value);
			}
			catch (const std::invalid_argument &)
			{
				throw std::runtime_error("Error: Invalid token '" + token + "'");
			}
		}
	}

	if (stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid expression");
	}

	std::cout << "Result: " << stack.top() << std::endl;
}
