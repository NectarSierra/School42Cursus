/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:14:19 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/22 09:14:04 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int main( void ) {
    Fixed a;
    Fixed b;
    Fixed c(0.545f);
    Fixed d(0.545f);
    Fixed e(0.543f);
    a = 10;
    b = 30;

    if (b > a)
        std::cout << b << " is bigger than " << a << std::endl << std::endl;
    if (a < b)
        std::cout << a << " is smaller than " << b << std::endl << std::endl;
    if (c <= b)
        std::cout << c << " is smaller or equal to " << b << std::endl << std::endl;
    if (b >= b)
        std::cout << b << " is bigger or equal to " << b << std::endl << std::endl;
    if (c == d)
        std::cout << c << " is strictly equal to " << d << std::endl << std::endl;
    if (c != e)
		std::cout << c << " is different from " << e << std::endl << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
    c = c + d;
    std::cout << c << std::endl;

    c = c - d;
    std::cout << c << std::endl;
    
    c = c * 10;
    std::cout << c << std::endl;

    c = c / 2;
    std::cout << c << std::endl << std::endl;


    Fixed x;
    Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );
	
    std::cout << x << std::endl;
    std::cout << ++x << std::endl;
    std::cout << x << std::endl;
    std::cout << x++ << std::endl;
    std::cout << x << std::endl;

    std::cout << y << std::endl;
	
    std::cout << Fixed::max( x, y ) << std::endl;
	std::cout << Fixed::min( x, y ) << std::endl;
    
    return 0;
}