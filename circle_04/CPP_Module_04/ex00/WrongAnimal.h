/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:46:10 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 13:36:02 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		// Constructor ( void | std::string ), Copy constructor, Destructor;
		WrongAnimal						( void );
		WrongAnimal						( std::string type );
		WrongAnimal						( WrongAnimal &obj );
		virtual ~WrongAnimal 					( void );
		
		// Overload operators;
		const WrongAnimal& operator=		( const WrongAnimal &obj );

		// Member functions;
		void makeSound				( void ) const;
		std::string getType			( void ) const;
};

#endif