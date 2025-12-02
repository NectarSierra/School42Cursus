/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:50:01 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/21 16:39:27 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
Dog::Dog	( void )
{
	std::cout << "[Dog] Default constructor called!" << std::endl;
	this->type = "Dog";
}

// Dog::Dog	( std::string type )
// {
// 	this->type = "Dog";
// }

Dog::Dog	( Dog &obj )
{
	std::cout << "[Dog] Copy constructor called!" << std::endl;
	*this = obj;
}

Dog::~Dog	( void )
{
	std::cout << "[Dog] Destructor called!" << std::endl;
}

// Overload operators;
const Dog& Dog::operator=	( const Dog &obj )
{
	std::cout << "[Dog] Overload operator= called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

// Membre functions;
void Dog::makeSound	( void ) const
{
	std::cout << "Woof!" << std::endl;
}