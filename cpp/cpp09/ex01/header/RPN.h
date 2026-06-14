/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:00:39 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/13 17:00:39 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void process(const std::string &expression);

	private:
		std::stack<int> stack;

		void push(int value);
		int pop();
};
