/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:49:51 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:28:33 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		WrongCat						( void );
		// WrongCat						( std::string type );
		WrongCat						( WrongCat &obj );
		~WrongCat 					( void );
		
		// Overload operators;
		const WrongCat& operator=	( const WrongCat &obj );

		// Member functions;
		void makeSound				( void ) const;
};

#endif