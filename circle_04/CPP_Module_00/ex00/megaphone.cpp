/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:39:39 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/02 10:45:28 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void upper_argv(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i][j];
			j++;
		}
		i++;
		std::cout << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
  	if (argc == 1)
	  std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		upper_argv(argc, argv);
	return 0;
} 