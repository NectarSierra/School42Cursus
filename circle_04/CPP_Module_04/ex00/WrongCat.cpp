/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:49:25 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/21 16:39:39 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
WrongCat::WrongCat	( void )
{
	std::cout << "[WrongCat] Default constructor called!" << std::endl;
	this->type = "WrongCat";
}

// WrongCat::WrongCat	( std::string type )
// {
// 	this->type = "WrongCat";
// }

WrongCat::WrongCat	( WrongCat &obj )
{
	std::cout << "[WrongCat] Copy constructor called!" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat	( void )
{
	std::cout << "[WrongCat] Destructor called!" << std::endl;
}

// Overload operators;
const WrongCat& WrongCat::operator=	( const WrongCat &obj )
{
	std::cout << "[WrongCat] Destructor called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

// Membre functions;
void WrongCat::makeSound				( void ) const
{
	std::cout << "Meow!" << std::endl;
}