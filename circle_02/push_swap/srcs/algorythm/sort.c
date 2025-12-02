/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:03:31 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:49:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Get the highest value inside the stack and return it's element */

t_listc	*get_min(t_listc *stack)
{
	t_listc	*min;
	t_listc	*compared;

	min = stack->next;
	compared = min->next;
	while (compared != stack)
	{
		if (compared->value < min->value)
			min = compared;
		compared = compared->next;
	}
	return (min);
}

/* Get the highest value inside the stack and return it's element */

t_listc	*get_max(t_listc *stack)
{
	t_listc	*max;
	t_listc	*compared;

	max = stack->next;
	compared = max->next;
	while (compared != stack)
	{
		if (compared->value > max->value)
			max = compared;
		compared = compared->next;
	}
	return (max);
}

/* Return the best way to rotate to get to the "element_searched" if 
(return is < 0)it's reverse_rotation and (return > 0) rotation */

int	get_cheapest_rota(t_listc *stack, t_listc *element_searched)
{
	t_listc	*current;
	int		position_r;
	int		position_rr;

	position_r = 0;
	position_rr = -1;
	current = stack->previous;
	while (current != element_searched)
	{
		position_r++;
		current = current->previous;
	}
	current = stack->next;
	while (current != element_searched)
	{
		position_rr--;
		current = current->next;
	}
	if (-position_rr < position_r)
		return (position_rr);
	return (position_r);
}

/*
 *  Try to find the above number of the value received if no above found we 
 return the pos of the min since we're putting the max behind the min
 *  (basic exemple for 10): 4 1 0 | 15 14 11 (10)
 *  (if no above found for 10 exemple): 5 4 3 1 0 | (10)
 */

int	get_above_rota(t_listc *stack, t_listc *element)
{
	t_listc	*current;
	t_listc	*above;
	t_listc	*max;

	max = get_max(stack);
	if (max->value < element->value)
		return (get_cheapest_rota(stack, get_min(stack)));
	current = stack->previous;
	above = current;
	while (current != stack)
	{
		if (current->value > element->value && current->value < above->value)
			above = current;
		else if (above->value < element->value)
			above = current;
		current = current->previous;
	}
	return (get_cheapest_rota(stack, above));
}
