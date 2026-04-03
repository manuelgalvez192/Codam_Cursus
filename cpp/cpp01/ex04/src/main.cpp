/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:25:51 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/08/22 01:25:51 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>

std::string replace_ocurrences(std::string input_data, const std::string &compare_string, const std::string &replace_string)
{
	size_t pos = 0;
	size_t found;
	std::string result;
	while ((found = input_data.find(compare_string, pos)) != std::string::npos)
	{
		result.append(input_data, pos, found - pos);
		result += replace_string;
		pos = found + compare_string.length();
	}
	result += input_data.substr(pos);
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Need only 3 arguments: filename, s1, s2" << std::endl;
		return 1;
	}

	char *new_file_name;
	std::string input_data;
	std::string compare_string = argv[2];
	std::string replace_string = argv[3];
	std::ifstream infile(argv[1]);

	if (infile.is_open())
	{
		new_file_name = strcat(argv[1], ".replace");
		std::ofstream outfile(new_file_name);
		while(std::getline(infile, input_data))
		{
			input_data = replace_ocurrences(input_data, compare_string, replace_string);
			outfile << input_data << std::endl;
		}
	}
	else
	{
		std::cout << "Error opening file: " << argv[1] << std::endl;
		return 1;
	}
	return 0;
}