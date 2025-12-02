/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:49:51 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:25:39 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal
{
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		Cat						( void );
		// Cat						( std::string type );
		Cat						( Cat &obj );
		~Cat 					( void );
		
		// Overload operators;
		const Cat& operator=	( const Cat &obj );

		// Member functions;
		void makeSound	( void ) const;
};

#endif