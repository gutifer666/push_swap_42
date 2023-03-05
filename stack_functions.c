/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:46:01 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/05 12:51:59 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

node*	create_node(t_node **init, int num)
{
	t_node  *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

void	destroy_node(t_node *node)
{
	free(node);
}

void	prepend_node(t_list *list, int num)
{
	t_node  *node;

	node = create_node(num);
	if (list->head == NULL)
		list->head = node;
	else
	{
		node->next = list->head;
		list->head = node;
	}
}

void	append_node(t_list *list, int num)
{
	t_node  *node;
	t_node  *last;

	node = create_node(num);
	if (list->head == NULL)
		list->head = node;
	else
	{
		last = list->head;
		while (last->next != NULL)
			last = last->next;
		last->next = node;
	}
}

void	delete_first_node(t_list *list)
{
	t_node  *node;

	if (list->head != NULL)
	{
		node = list->head;
		list->head = list->head->next;
		destroy_node(node);
	}
}
// stack functions

void    push(t_list *list, int num)
{
	prepend_node(list, num);
}

node	*peek(t_list *list)
{
	return (list->head);
}

void    pop(t_list *list)
{
	delete_first_node(list);
}

int	 is_empty(t_list *list)
{
	if (list->head == NULL)
		return (1);
	return (0);
}
