/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:05:35 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/15 11:40:50 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 fixed_point;
        static const int    fractional_bits = 8;
    public:
		// Constructor(void|const int|const float), copy constructor, destructor;
        Fixed               ();
        Fixed               (const int);
        Fixed               (const float);
        Fixed               (const Fixed &obj);
        ~Fixed              ();

        // Overload operator;
        Fixed&  operator=   (const Fixed& obj);
		
        // Member functions;
        int     getRawBits  ( void ) const;
        void    setRawBits  ( int const raw );
        float   toFloat     ( void ) const;
        int     toInt       ( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& obj);

#endif