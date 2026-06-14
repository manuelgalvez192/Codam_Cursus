/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 13:30:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/14 13:30:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmergeMe;
        pmergeMe.process(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
