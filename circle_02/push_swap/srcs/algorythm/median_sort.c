/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:35:17 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 11:12:19 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_array_sorted(int *array, int number_of_arg)
{
	int	i;
	int	current;
	int	compared;

	i = 0;
	current = array[i];
	compared = array[i + 1];
	while (i + 1 < number_of_arg)
	{
		current = array[i];
		compared = array[i + 1];
		if (current < compared)
			return (0);
		i++;
	}
	return (1);
}

int	*set_array(t_listc *stack_a, int *bubble_array)
{
	int		i;
	t_listc	*current;

	current = stack_a->next;
	i = 0;
	while (current != stack_a)
	{
		bubble_array[i] = current->value;
		current = current->next;
		i++;
	}
	return (bubble_array);
}

/*
** [Get_median]: Is using bubble sort to sort the number we got, 
we then get to the number in the middle of those one to get the median.
*/

int	*bubblesort_array(t_listc *stack_a, int number_of_arg)
{
	int	*array;
	int	current;
	int	compared;
	int	i;

	array = malloc(number_of_arg * sizeof(int));
	set_array(stack_a, array);
	while (!is_array_sorted(array, number_of_arg))
	{
		i = 0;
		while (i + 1 < number_of_arg)
		{
			current = array[i];
			compared = array[i + 1];
			if (current < compared)
			{
				array[i] = compared;
				array[i + 1] = current;
			}
			i++;
		}
	}
	return (array);
}

/* 
** Median_sort, is pre sorting the stack_a into stack_b,
** this way, we're optimizing the next sorting algorythm.
*/

void	median_sort(t_listc *stack_a, t_listc *stack_b, int number_of_arg)
{
	int	i;
	int	*array_sorted;
	int	median;

	i = 0;
	array_sorted = bubblesort_array(stack_a, number_of_arg);
	median = array_sorted[number_of_arg / 2];
	free(array_sorted);
	push_n(stack_b, stack_a, 'b', 1);
	while (i < number_of_arg - 2)
	{
		if (stack_a->previous->value <= median)
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_b, 'b');
		}
		else
			push(stack_b, stack_a, 'b');
		i++;
	}
}
