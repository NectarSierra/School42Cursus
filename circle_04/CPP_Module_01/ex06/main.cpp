/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:30:53 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 17:50:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main( int argc, char **argv )
{
	if (argc == 2)
	{
		Harl harl_obj;
		harl_obj.complain(argv[1]);
	}
	return 0;
}