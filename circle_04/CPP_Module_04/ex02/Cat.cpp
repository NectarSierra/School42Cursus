/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:49:25 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/21 16:39:07 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

// Constructor ( void | std::string ), Copy constructor, Destructor;
Cat::Cat	( void )
{
	std::cout << "[Cat] Default constructor called!" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

// Cat::Cat	( std::string type )
// {
// 	this->type = "Cat";
// }

Cat::Cat	( const Cat &obj )
{
	std::cout << "[Cat] Copy constructor called!" << std::endl;
	*this = obj;
}

Cat::~Cat	( void )
{
	std::cout << "[Cat] Destructor called!" << std::endl;
	delete this->brain;
}

// Overload operators;
const Cat& Cat::operator=	( const Cat &obj )
{
	std::cout << "[Cat] Overload operator= called!" << std::endl;
	this->type = obj.type;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

// Membre functions;
void Cat::makeSound	( void ) const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::apply_change( std::string in ) const
{
	std::cout << "[Cat] change_ideas called!" << std::endl;
	this->brain->change_ideas(in);
}

void Cat::print_brain( int j ) const
{
	this->brain->print_ideas(j);
}
