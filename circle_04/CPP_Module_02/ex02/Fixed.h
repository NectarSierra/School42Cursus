/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:05:35 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/15 11:41:52 by nsaillez         ###   ########.fr       */
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
		Fixed								( void );
		Fixed								( const int );
		Fixed								( const float );
		Fixed								( const Fixed &obj );
		~Fixed								( void );
		
		// Overload Operators;
		Fixed&					operator=   (const Fixed& obj);
		int						operator>   ( const Fixed& obj );
		int						operator<   ( const Fixed& obj );
		int						operator>=  ( const Fixed& obj );
		int						operator<=  ( const Fixed& obj );
		int						operator==  ( const Fixed& obj );
		int						operator!=  ( const Fixed& obj );
		Fixed&					operator+   ( const Fixed& obj );
		Fixed&					operator-   ( const Fixed& obj );
		Fixed&					operator*   ( const Fixed& obj );
		Fixed&					operator/   ( const Fixed& obj );
		Fixed&					operator++  ( void );
		Fixed					operator++  ( int );
		Fixed&					operator--  ( void );
		Fixed					operator-- 	( int );
		
		// Member Functions;
		static	Fixed&			min 		(Fixed& A, Fixed& B);
		static	const Fixed&	min			(const Fixed& A, const Fixed& B);
		static	Fixed&			max 		(Fixed& A, Fixed& B);
		static	const Fixed&	max 		(const Fixed& A, const Fixed& B);
		int						getRawBits  ( void ) const;
		void					setRawBits  ( int const raw );
		float					toFloat     ( void ) const;
		int						toInt       ( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& obj);

#endif