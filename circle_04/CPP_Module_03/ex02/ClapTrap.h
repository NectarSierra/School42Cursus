/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:08:42 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/23 12:38:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <climits>
#include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	Hit_points;
		unsigned int 	Energy_points;
		unsigned int	Attack_damage;
	public:
		// Constructor( std::string ), copy constructor, destructor;
		ClapTrap					( void );
		ClapTrap					( std::string name );
		ClapTrap					( const ClapTrap &obj );
		~ClapTrap					( void );
		
		// Overload Operators;
		const ClapTrap& operator= 	( const ClapTrap &obj );
		
		// Member Functions;
		void attack					( const std::string& target );
		void takeDamage				( unsigned int amount );
		void beRepaired				( unsigned int amount );
};

#endif