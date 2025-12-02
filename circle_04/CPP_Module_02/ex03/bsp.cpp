/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:16 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/16 12:34:40 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

float sign(Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

	
    if (((d1 <= 0) || (d2 <= 0) || (d3 <= 0)) && ((d1 >= 0) || (d2 >= 0) || (d3 >= 0)))
		return (false);
	return (true);
}