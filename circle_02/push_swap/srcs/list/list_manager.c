/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:35:36 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:29:31 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_listc	*create_cirlist(void)
{
	t_listc	*root;

	root = malloc(sizeof(t_listc));
	if (root != NULL)
	{
		root->previous = root;
		root->next = root;
		root->value = 0;
		root->cost_stack_a = 0;
		root->cost_stack_b = 0;
		root->total_cost = 0;
	}
	return (root);
}

void	add_new_node_after(t_listc *node, int val)
{
	t_listc	*new_node;

	new_node = malloc(sizeof(t_listc));
	if (!new_node)
		return ;
	new_node->value = val;
	new_node->cost_stack_a = 0;
	new_node->cost_stack_b = 0;
	new_node->total_cost = 0;
	new_node->previous = node;
	new_node->next = node->next;
	node->next->previous = new_node;
	node->next = new_node;
}

void	add_new_node_before(t_listc *node, int val)
{
	t_listc	*new_node;

	new_node = malloc(sizeof(t_listc));
	if (!new_node)
		return ;
	new_node->value = val;
	new_node->cost_stack_a = 0;
	new_node->cost_stack_b = 0;
	new_node->total_cost = 0;
	new_node->previous = node->previous;
	new_node->next = node;
	node->previous->next = new_node;
	node->previous = new_node;
}

void	push_to_end(t_listc *root, int val)
{
	add_new_node_before(root, val);
}

void	push_to_start(t_listc *root, int val)
{
	add_new_node_after(root, val);
}
