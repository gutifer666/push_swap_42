/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:20:22 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/14 09:31:27 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/*
**  Añade un elemento al principio de la lista
*/
void	list_prepend(t_list **stack, t_list *news)
{
	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	(*stack)->prev = news;
	news->next = *stack;
	*stack = news;
	news->prev = NULL;
}

/*
**  Añade un elemento al final de la lista
*/
void	list_append(t_list **stack, t_list *news)
{
	t_list	*tmp;

	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = news;
	news->prev = tmp;
}

/*
**  Crea un nuevo elemento de la lista
*/
t_list	*new_node(int num)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->num = num;
	stack->index = -1;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

/*
**  Devuelve el último elemento de la lista
*/
t_list	*list_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	list_size(t_list *stack)
{
	int		i;
	t_list	*list;

	list = stack;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
