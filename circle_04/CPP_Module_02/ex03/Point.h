/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:26 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/22 09:38:54 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		// Constructor(void|const int|const float), copy constructor, destructor;
		Point	( void );
		Point	( const float x, const float y );
		Point	( const Point &obj );
		~Point	( void );
		
		// // Overload Operators;
		const Point& operator= ( const Point &obj );
		
		// // Member Functions;
		float getX( void );
		float getY( void );
		
};

#endif