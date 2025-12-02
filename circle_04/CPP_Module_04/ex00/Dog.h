/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:48:21 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:26:16 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		Dog						( void );
		// Dog						( std::string type );
		Dog						( Dog &obj );
		~Dog 					( void );
		
		// Overload operators;
		const Dog& operator=	( const Dog &obj );

		// Membre functions;
		void makeSound			( void ) const;
};

#endif