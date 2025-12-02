/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:46:19 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:28:00 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
WrongAnimal::WrongAnimal	( void )
{
	std::cout << "[WrongAnimal] Default constructor called!" << std::endl;
	this->type = "";
}

WrongAnimal::WrongAnimal	( std::string type )
{
	std::cout << "[WrongAnimal] Default constructor called!" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal	( WrongAnimal &obj )
{
	std::cout << "[WrongAnimal] Copy constructor called!" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called!" << std::endl;
}

// Overload operators;
const WrongAnimal& WrongAnimal::operator= ( const WrongAnimal &obj )
{
	this->type = obj.type;
	return (*this);
}

// Membre functions;
void WrongAnimal::makeSound				( void ) const
{
	std::cout << "*Unidentified grawling*" << std::endl;
}

std::string WrongAnimal::getType			( void ) const
{
	return (this->type);
}