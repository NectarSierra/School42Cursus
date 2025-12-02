/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:05:35 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/15 11:39:20 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
		// Constructor(void|const int|const float), copy constructor, destructor;
        Fixed               ( void );
        Fixed               ( Fixed &obj );
        ~Fixed              ( void );

        // Overload operator;
        Fixed&  operator=   ( Fixed& obj );
		
        // Member functions;
        int     getRawBits  ( void ) const;
        void    setRawBits  ( int const raw );
        float   toFloat     ( void ) const;
        int     toInt       ( void ) const;
};

#endif