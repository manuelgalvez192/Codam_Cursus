/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:58:09 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/10/19 15:58:09 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.h"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int convert) : value(convert << fractionalBits)
{
}

Fixed::Fixed(const float convert) : value(roundf(convert * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return temp;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->value = fixed.value;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	if (this->value > fixed.value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	if (this->value < fixed.value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	if (this->value >= fixed.value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	if (this->value <= fixed.value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	if (this->value == fixed.value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	if (this->value != fixed.value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;
    result.setRawBits(this->value + fixed.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;
    result.setRawBits(this->value - fixed.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result;
    int tmp = this->value * fixed.value;
    result.setRawBits(tmp >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result;
    int tmp = (this->value << fractionalBits) / fixed.value;
    result.setRawBits(tmp);
    return result;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	float val_return = (float)value / (1 << fractionalBits);
	return val_return;
}

int Fixed::toInt(void) const
{
	return this->value >> fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}