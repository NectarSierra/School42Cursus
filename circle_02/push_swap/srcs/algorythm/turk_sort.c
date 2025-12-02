/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:58 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:43:44 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Compare all total_cost inside stack_b to 
find the cheapest way to push it to stack_a */

t_listc	*get_cheapest_cost(t_listc *stack_b)
{
	t_listc	*current;
	t_listc	*cheapest;

	current = stack_b->previous;
	cheapest = current;
	while (current != stack_b)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->previous;
	}
	return (cheapest);
}

/* Sum of the amount of move to do in stack_a 
and stack_b to push the stack_b element to stack_a */

int	sum_cost(int cost_stack_a, int cost_stack_b)
{
	int	result;

	if (cost_stack_a < 0)
		result = (-cost_stack_a);
	else
		result = cost_stack_a;
	if (cost_stack_b < 0)
		result += (-cost_stack_b);
	else
		result += cost_stack_b;
	return (result);
}

/* 
**	This function calculate the amount of move to get 
**  each element of stack_b to the right place into stack_a,
**  so for each element we know the amount of move we need 
**  to do in stack_a & stack_b and we sum it up to get the cost
*/

void	calculate_cost(t_listc *stack_a, t_listc *stack_b)
{
	int		cost_stack_a;
	int		cost_stack_b;
	t_listc	*current;

	current = stack_b->previous;
	while (current != stack_b)
	{
		cost_stack_a = get_above_rota(stack_a, current);
		cost_stack_b = get_cheapest_rota(stack_b, current);
		current->cost_stack_a = cost_stack_a;
		current->cost_stack_b = cost_stack_b;
		current->total_cost = sum_cost(cost_stack_a, cost_stack_b);
		current = current->previous;
	}
}

/*
**	Perform calculation for each element of stack B for being moved
**	at the right place (under their above number) inside A
**	Take the lowest cost, perform the rotation needed and push it.
**	Repeat till stack B empty.
*/

void	turk_sort(t_listc *stack_a, t_listc *stack_b, int number_of_arg)
{
	int		left_element;
	t_listc	*element;

	left_element = number_of_arg;
	while (left_element > 0)
	{
		calculate_cost(stack_a, stack_b);
		element = get_cheapest_cost(stack_b);
		apply_rotation(stack_a, stack_b, element);
		push(stack_a, stack_b, 'a');
		left_element--;
	}
	last_rotation(stack_a);
}
