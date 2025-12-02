/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:06:18 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/15 11:40:47 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

static int my_pow(int base, int exp)
{
	int result = base;
	int i;

	i = 0;
	while (i < exp-1)
	{
		result *= base;
		i++;
	}
	return (result);
}

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const int integer){
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = integer * my_pow(2, this->fractional_bits);
}

Fixed::Fixed(const float floating_point){
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(floating_point * my_pow(2, this->fractional_bits));
}

Fixed::Fixed(const Fixed &obj){
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed(){
	std::cout << "Destructor Called!" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	float value;
	
	value = (float)this->fixed_point / (float)my_pow(2, this->fractional_bits);

	return (value);
}

int Fixed::toInt( void ) const
{
	int value;
	
	value = this->fixed_point / my_pow(2, this->fractional_bits);

	return (value);
}

Fixed& Fixed::operator= (const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(obj.getRawBits());
	return (*this);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& obj)
{
    stream << (obj.toFloat());
	return stream;
}