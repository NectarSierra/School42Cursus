/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:50:01 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/21 16:39:12 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
Dog::Dog	( void )
{
	std::cout << "[Dog] Default constructor called!" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

// Dog::Dog	( std::string type )
// {
// 	this->type = "Dog";
// }

Dog::Dog	( const Dog &obj )
{
	std::cout << "[Dog] Copy constructor called!" << std::endl;
	*this = obj;
}

Dog::~Dog	( void )
{
	std::cout << "[Dog] Destructor called!" << std::endl;
	delete this->brain;
}

// Overload operators;
const Dog& Dog::operator=	( const Dog &obj )
{
	std::cout << "[Dog] Destructor called!" << std::endl;
	this->type = obj.type;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

// Membre functions;
void Dog::makeSound	( void ) const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::apply_change( std::string in ) const
{
	std::cout << "[Dog] change_ideas called!" << std::endl;
	this->brain->change_ideas(in);
}

void Dog::print_brain( int j ) const
{
	this->brain->print_ideas(j);
}