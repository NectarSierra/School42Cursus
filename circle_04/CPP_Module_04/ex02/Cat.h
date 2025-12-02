/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:49:51 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 16:02:57 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Brain.h"
#include "Animal.h"

class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		Cat						( void );
		// Cat						( std::string type );
		Cat						( const Cat &obj );
		~Cat 					( void );
		
		// Overload operators;
		const Cat& operator=	( const Cat &obj );

		// Member functions;
		void makeSound			( void ) const;
		void apply_change ( std::string in ) const;
		void print_brain ( int j ) const;
};

#endif