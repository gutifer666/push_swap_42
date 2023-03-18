/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:39:45 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/09 10:03:02 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/*
**  Intercambia los dos primeros elementos de la lista
*/
static	void	swap(t_list **stack)
{
	int	index;
	int	num;

	if (!(*stack)->next)
		return ;
	num = (*stack)->next->num;
	index = (*stack)->next->index;
	(*stack)->next->num = (*stack)->num;
	(*stack)->next->index = (*stack)->index;
	(*stack)->num = num;
	(*stack)->index = index;
}

/*
**  Intercambia los dos primeros elementos de la lista A
*/
void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

/*
**  Intercambia los dos primeros elementos de la lista B
*/
void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

/*
**  Intercambia los dos primeros elementos de las dos listas
*/
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
