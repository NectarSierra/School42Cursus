/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:34:06 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 16:02:37 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain( void );
		Brain( const Brain &obj);
		~Brain( void );
		
		const Brain& operator= (const Brain &obj);

		void print_ideas( int );
		void change_ideas( std::string );
};

#endif