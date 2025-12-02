/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:20:09 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 16:58:56 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main( void )
{
	Harl ok;
	ok.complain("DEBU");
	std::cout << std::endl;
	ok.complain("DEBUG");
	ok.complain("INFO");
	ok.complain("WARNING");
	ok.complain("ERROR");
	return (0);
}