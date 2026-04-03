/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:58:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/10/19 15:58:15 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const int convert);
		Fixed(const float convert);
		Fixed(const Fixed &fixed);
		~Fixed();
		
		Fixed &operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int value;
		static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed &other);