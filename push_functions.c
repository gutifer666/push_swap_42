/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:09:39 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/10 07:51:53 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*
**  Mueve el primer elemento de una lista a otra
*/
static void	push(t_list **a_stack, t_list **b_stack)
{
	t_list	*tmp;

	if (!b_stack)
		return ;
	tmp = (*b_stack)->next;
	list_prepend(a_stack, *b_stack);
	*b_stack = tmp;
	if (*b_stack)
		(*b_stack)->prev = NULL;
}

/*
**  Mueve el primer elemento de la lista B a la lista A
*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

/*
**  Mueve el primer elemento de la lista A a la lista B
*/
void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
