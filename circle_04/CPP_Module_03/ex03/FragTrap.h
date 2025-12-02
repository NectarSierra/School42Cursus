/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:26:36 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/24 10:29:52 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap
{
	public:
		// Constructor( void | std::string ), copy constructor, destructor;
		FragTrap					( void );
		FragTrap					( std::string name );
		FragTrap					( const FragTrap &obj );
		~FragTrap					( void );
		
		// Overload Operators;
		const FragTrap& operator= 	( const FragTrap &obj );
		
		// Member Functions;
		void attack					( const std::string& target );
		void highFivesGuys			( void );
};

#endif