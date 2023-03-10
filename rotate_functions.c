/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 07:57:49 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/10 08:18:30 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*
**  Rota la lista hacia arriba
*/
void	rotate(t_list **stack)
{
	t_list	*list_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	list_node = list_last(*stack);
	list_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	list_node->next->prev = list_node;
	list_node->next->next = NULL;
}

/*
**  Rota la lista A hacia arriba
*/
void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

/*
**  Rota la lista B hacia arriba
*/
void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

/*
**  Rota las dos listas hacia arriba
*/
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
