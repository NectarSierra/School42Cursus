/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:14:19 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/16 12:44:35 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    Point a(0.0f,0.0f);
    Point b(10.0f,30.0f);
    Point c(20.0f,0.0f);
    
    Point point(10.0f,15.0f);
    if (bsp(a,b,c,point))
        std::cout << "is in triangle" << std::endl;
    else
        std::cout << "is not in triangle" << std::endl;
    
    Point point2(30.0f,15.0f);
    if (bsp(a,b,c,point2))
        std::cout << "is in triangle" << std::endl;
    else
        std::cout << "is not in triangle" << std::endl;

    Point point3(10.0f,0.0f);
    if (bsp(a,b,c,point3))
        std::cout << "is in triangle" << std::endl;
    else
        std::cout << "is not in triangle" << std::endl;

    Point point4(10.0f,30.0f);
    if (bsp(a,b,c,point4))
        std::cout << "is in triangle" << std::endl;
    else
        std::cout << "is not in triangle" << std::endl;

    Point point5(0.01f,0.01f);
    if (bsp(a,b,c,point5))
        std::cout << "is in triangle" << std::endl;
    else
        std::cout << "is not in triangle" << std::endl;
    return 0;
}