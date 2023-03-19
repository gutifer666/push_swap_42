/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:14:38 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/19 13:52:52 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/*
**  Comprueba si la lista está ordenada, devuelve 1 si lo está, -1 si no lo está
*/
int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

/*
**  Ordena la lista enlazada e imprime los comandos necesarios
*/
int	is_order(t_list **stack, int size)
{
	int	i;

	i = 0;
	while ((*stack)->index != 0)
	{
		rotate(stack);
		i++;
	}
	if (is_sorted(stack) == 1)
	{
		if (i > (size / 2))
		{
			if (size == 5 && i == 3)
				ft_printf("rra\n");
			ft_printf("rra\n");
		}
		else
			while (i-- > 0)
				ft_printf("ra\n");
		return (1);
	}
	else
		while (i-- > 0)
			reverse_rotate(stack);
	return (0);
}
