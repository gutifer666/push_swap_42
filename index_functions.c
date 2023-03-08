/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:11:28 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/08 09:48:53 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/*
**  Devuelve el nodo con el índice más bajo
*/
static	t_list	*get_min_node(t_list **stack)
{
	t_list	*tmp;
	t_list	*min_node;
	int		min;

	if (!(*stack))
		return (NULL);
	min = 0;
	min_node = NULL;
	tmp = *stack;
	while (tmp)
	{
		if ((tmp->index == -1)
			&& (!min || tmp->num < min_node->num))
		{
			min_node = tmp;
			min = 1;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

void	assign_ascending_index(t_list **stack)
{
	t_list	*list;
	int		index;

	index = 0;
	list = get_min_node(stack);
	while (list)
	{
		list->index = index++;
		list = get_min_node(stack);
	}	
}