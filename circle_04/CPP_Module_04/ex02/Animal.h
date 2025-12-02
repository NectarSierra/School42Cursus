/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:46:10 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/20 10:20:32 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		Animal						( void );
		Animal						( std::string type );
		Animal						( const Animal &obj );
		virtual ~Animal 			( void );
		
		// Overload operators;
		const Animal& operator=		( const Animal &obj );

		// Member functions;
		virtual void makeSound		( void ) const = 0;
		std::string getType			( void ) const;
		virtual void apply_change	( std::string in) const;
		virtual void print_brain	( int ) const;
};

#endif