/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:31:14 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/10 08:39:39 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*
**  Rota la lista hacia abajo
*/
void	reverse_rotate(t_list **stack)
{
	t_list	*list_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	list_node = list_last(*stack);
	list_node->prev->next = NULL;
	list_node->prev = NULL;
	list_node->next = *stack;
	(*stack)->prev = list_node;
	*stack = (*stack)->prev;
}

/*
**  Rota la lista A hacia abajo
*/
void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

/*
**  Rota la lista B hacia abajo
*/
void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

/*
**  Rota las dos listas hacia abajo
*/
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
