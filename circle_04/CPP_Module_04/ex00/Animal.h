/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:46:10 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:24:42 by nsaillez         ###   ########.fr       */
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
		Animal						( Animal &obj );
		virtual ~Animal 			( void );
		
		// Overload operators;
		const Animal& operator=		( const Animal &obj );

		// Member functions;
		virtual void makeSound		( void ) const;
		std::string getType			( void ) const;
};

#endif