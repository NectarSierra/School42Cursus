/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:46:19 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:24:25 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
Animal::Animal	( void )
{
	std::cout << "[Animal] Default constructor called!" << std::endl;
	this->type = "";
}

Animal::Animal	( std::string type )
{
	std::cout << "[Animal] Default constructor called!" << std::endl;
	this->type = type;
}

Animal::Animal	( Animal &obj )
{
	std::cout << "[Animal] Copy constructor called!" << std::endl;
	*this = obj;
}

Animal::~Animal	()
{
	std::cout << "[Animal] Destructor called!" << std::endl;
}

// Overload operators;
const Animal& Animal::operator= ( const Animal &obj )
{
	this->type = obj.type;
	return (*this);
}

// Membre functions;
void Animal::makeSound	( void ) const
{
	std::cout << "*Unidentified grawling*" << std::endl;
}

std::string Animal::getType			( void ) const
{
	return (this->type);
}