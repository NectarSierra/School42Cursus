/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:49:25 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/21 16:39:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
Cat::Cat	( void )
{
	std::cout << "[Cat] Default constructor called!" << std::endl;
	this->type = "Cat";
}

// Cat::Cat	( std::string type )
// {
// 	this->type = "Cat";
// }

Cat::Cat	( Cat &obj )
{
	std::cout << "[Cat] Copy constructor called!" << std::endl;
	*this = obj;
}

Cat::~Cat	( void )
{
	std::cout << "[Cat] Destructor called!" << std::endl;
}

// Overload operators;
const Cat& Cat::operator=	( const Cat &obj )
{
	std::cout << "[Cat] Destructor called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

// Membre functions;
void Cat::makeSound	( void ) const
{
	std::cout << "Meow!" << std::endl;
}