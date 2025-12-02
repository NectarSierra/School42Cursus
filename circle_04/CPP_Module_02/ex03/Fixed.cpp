/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:06:18 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/15 12:49:35 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

static int my_pow(int base, int exp)
{
	int result = base;
	int i = 0;

	while (i++ < exp-1)
		result *= base;
	return (result);
}

// Constructor(void|const int|const float), copy constructor, destructor;

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed( const int integer ){
	//std::cout << "Int constructor called" << std::endl;
	this->fixed_point = integer * my_pow(2, this->fractional_bits);
}

Fixed::Fixed( const float floating_point ){
	//std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(floating_point * my_pow(2, this->fractional_bits));
}

Fixed::Fixed( const Fixed &obj ){
	//std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed( void ){
	//std::cout << "Destructor Called!" << std::endl;
}

// Overload Operators;

Fixed& Fixed::operator=(const Fixed& obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(obj.getRawBits());
	return (*this);
};

int  Fixed::operator>( const Fixed& obj )
{
	if (this->fixed_point > obj.fixed_point)
		return (1);
	return (0);
}

int  Fixed::operator<( const Fixed& obj )
{
	if (this->fixed_point < obj.fixed_point)
		return (1);
	return (0);
}

int  Fixed::operator>=( const Fixed& obj )
{
	if (this->fixed_point >= obj.fixed_point)
		return (1);
	return (0);
}

int  Fixed::operator<=( const Fixed& obj )
{
	if (this->fixed_point <= obj.fixed_point)
		return (1);
	return (0);
}

int  Fixed::operator==( const Fixed& obj )
{
	if (this->getRawBits() == obj.getRawBits())
		return (1);
	return (0);
}

int  Fixed::operator!=( const Fixed& obj )
{
	if (this->getRawBits() != obj.getRawBits())
		return (1);
	return (0);
}

Fixed&  Fixed::operator+( const Fixed& obj )
{
	this->setRawBits(this->fixed_point + obj.fixed_point);
	return (*this);
}

Fixed&  Fixed::operator-( const Fixed& obj )
{
	this->setRawBits(this->fixed_point - obj.fixed_point);
	return (*this);
}

Fixed&  Fixed::operator*( const Fixed& obj )
{
	this->setRawBits((this->fixed_point * obj.fixed_point) / my_pow(2, this->fractional_bits));
	return (*this);
}

Fixed&  Fixed::operator/( const Fixed& obj )
{
	if (obj.fixed_point == 0)
		return (std::cout << "Error: Cannot divide by 0" << std::endl, *this);
	this->setRawBits((this->fixed_point / obj.fixed_point) * my_pow(2, this->fractional_bits));
	return (*this);
}

Fixed&  Fixed::operator++( void )
{
	this->setRawBits(this->fixed_point + 1);
	return (*this);
}

Fixed   Fixed::operator++( int )
{
	Fixed temp = *this;
	this->setRawBits(this->fixed_point + 1);
	return (temp);
}

Fixed&  Fixed::operator--( void )
{
	this->setRawBits(this->fixed_point - 1);
	return (*this);
}

Fixed   Fixed::operator--( int )
{
	Fixed temp = *this;
	this->setRawBits(this->fixed_point - 1);
	return (temp);
}

// Member Functions;

Fixed& Fixed::min( Fixed& A, Fixed& B )
{
	if (A.fixed_point < B.fixed_point)
		return (A);
	return (B);
}

const Fixed&  Fixed::min( const Fixed& A, const Fixed& B )
{
	if (A.fixed_point < B.fixed_point)
		return (A);
	return (B);
}

Fixed&  Fixed::max( Fixed& A, Fixed& B)
{
	if (A.fixed_point > B.fixed_point)
		return (A);
	return (B);
}

const Fixed&  Fixed::max( const Fixed& A, const Fixed& B )
{
	if (A.fixed_point > B.fixed_point)
		return (A);
	return (B);
}

std::ostream& operator<<( std::ostream& stream, const Fixed& obj )
{
    stream << (obj.toFloat());
	return stream;
}

int Fixed::getRawBits( void ) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
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