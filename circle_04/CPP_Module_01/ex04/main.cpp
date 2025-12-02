/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:20:16 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:35:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int ft_replace(char *filename, char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	if (std::string(str1).empty())
	{
		std::cerr << "Error str1 cannot be empty." << std::endl;
		return -1;
	}

	std::ifstream infile(filename);
	if (!infile)
	{
		std::cerr << "Error cannot open infile." << std::endl;
		return -1;
	}

	std::ofstream outfile((std::string(filename) + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error cannot create outfile." << std::endl;
		return -1;
	}

	std::string line;
	while (getline(infile, line))
	{
		while (line[i])
		{
			while (line[i+j] && line[i+j] == str1[j])
				j++;
			if (j == (int)std::string(str1).length())
			{
				outfile << str2;
				i += j;
			}
			else
			{
				outfile << line[i];
				i++;
			}
			j = 0;
		}
		i = 0;
		outfile << std::endl;
	}
	std::cout << "File sucessfuly created." << std::endl;
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error 3 arguments needed: <filepath> <str1> <str2>" << std::endl;
		return (-1);
	}
	return (ft_replace(argv[1],argv[2],argv[3]));
}