/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:03:52 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 11:17:57 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	count_args(t_listc *stack)
{
	int		counter;
	t_listc	*current;

	counter = 0;
	current = stack->next;
	while (current != stack)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}

void	initialize_sort(t_listc *stack_a, t_listc *stack_b)
{
	int	number_of_arg;

	number_of_arg = count_args(stack_a);
	if (number_of_arg > 6)
	{
		if (!is_sorted(stack_a))
		{
			median_sort(stack_a, stack_b, number_of_arg);
			turk_sort(stack_a, stack_b, number_of_arg);
		}
	}
	if (number_of_arg > 3 && number_of_arg <= 6)
		if (!is_sorted(stack_a))
			sort_small(stack_a, stack_b, number_of_arg);
	if (number_of_arg == 3)
		sort_3(stack_a);
	if (number_of_arg == 2)
		if (!is_sorted(stack_a))
			swap(stack_a, 'a');
}

int	main(int argc, char **argv)
{
	t_listc	*stack_a;
	t_listc	*stack_b;

	stack_a = create_cirlist();
	stack_b = create_cirlist();
	if (argc > 1)
	{
		if (args_to_int(argc, argv, &stack_a, &stack_b) == -1)
			return (-1);
		if (check_for_dup(stack_a, stack_b) == -1)
			return (-1);
		initialize_sort(stack_a, stack_b);
	}
	list_clean_both(stack_a, stack_b);
	return (0);
}
