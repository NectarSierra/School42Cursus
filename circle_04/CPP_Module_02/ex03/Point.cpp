/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:24 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/16 12:13:52 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

Point::Point	( void ) : x(0), y(0)
{
	//std::cout << "Constructor called" << std::endl;
}

Point::Point	( const float x, const float y ) : x(x), y(y)
{
	//std::cout << "Constructor called" << std::endl;
}

Point::Point	( const Point &obj ) : x(obj.x), y(obj.y)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point::~Point	( void )
{
	//std::cout << "Destructor called" << std::endl;
}

// https://stackoverflow.com/questions/4136156/const-member-and-assignment-operator-how-to-avoid-the-undefined-behavior

const Point& Point::operator= ( const Point &obj )
{
	//std::cout << "Copy assignment operator overload" << std::endl;
	(void) obj;
    return *this;
}

// Member functions;

float Point::getX ( void )
{
	return (this->x.toFloat());
}

float Point::getY ( void )
{
	return (this->y.toFloat());
}