/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:04:19 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:30:35 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	list_delete(t_listc *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	list_cleanup(t_listc *lst)
{
	t_listc	*temp;
	t_listc	*current;

	current = lst->next;
	if (!lst)
		return ;
	while (current != lst)
	{
		temp = current->next;
		list_delete(current);
		current = temp;
	}
	free(lst);
	lst = 0;
}

void	list_clean_both(t_listc *stack_a, t_listc *stack_b)
{
	list_cleanup(stack_a);
	list_cleanup(stack_b);
}
