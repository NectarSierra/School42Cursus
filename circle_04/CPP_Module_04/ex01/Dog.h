/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:48:21 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 16:03:37 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Brain.h"
#include "Animal.h"

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		Dog						( void );
		// Dog						( std::string type );
		Dog						( const Dog &obj );
		~Dog 					( void );
		
		// Overload operators;
		const Dog& operator=	( const Dog &obj );

		// Member functions;
		void makeSound			( void ) const;
		void apply_change 		( std::string in ) const;
		void print_brain ( int ) const;
};

#endif