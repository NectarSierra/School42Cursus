/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:39:35 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:34:45 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../push_swap.h"

/* In case of an [int overflow / not int] 
this function display an error and return -1*/

int	args_to_int_error(char **pre_arg, int j)
{
	char	*red;

	red = "\033[31m";
	write(2, red, 5);
	write(2, "Error - Argument is not an int!\n", 33);
	write(2, "\033[0m", 5);
	while (pre_arg[j])
		free(pre_arg[j++]);
	free(pre_arg);
	return (-1);
}

/* Transform and move every number from argv to stack_a using atoi & split 
in the process to remove whitespace */

int	args_to_int(int argc, char **argv, t_listc **stack_a, t_listc **stack_b)
{
	char	**pre_arg;
	int		i;
	int		j;

	i = 0;
	while (i < (argc - 1))
	{
		pre_arg = ft_split(argv[i + 1], ' ');
		j = 0;
		while (pre_arg[j])
		{
			if (char_to_int_overflow(pre_arg[j]) == -1)
			{
				list_clean_both(*stack_a, *stack_b);
				return (args_to_int_error(pre_arg, j));
			}
			push_to_start(*stack_a, ft_atoi(pre_arg[j]));
			free(pre_arg[j++]);
		}
		free(pre_arg);
		i++;
	}
	return (0);
}

/* This function checks for duplicates if one is found 
it display an error and return -1*/

int	check_for_dup(t_listc *stack_a, t_listc *stack_b)
{
	t_listc	*current;
	t_listc	*compared;
	char	*red;

	red = "\033[31m";
	current = stack_a->next;
	while (current != stack_a)
	{
		compared = current->next;
		while (compared != stack_a)
		{
			if (current->value == compared->value)
			{
				write(2, red, 5);
				write(2, "Error - Duplicates\n", 20);
				write(2, "\033[0m", 5);
				list_clean_both(stack_a, stack_b);
				return (-1);
			}
			compared = compared->next;
		}
		current = current->next;
	}
	return (0);
}
