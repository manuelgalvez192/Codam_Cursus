/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:34:02 by mgalvez-          #+#    #+#             */
/*   Updated: 2026/06/03 18:34:02 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
typename T::iterator easyfind(const T& container, int value);

#include "easyfind.tpp"
