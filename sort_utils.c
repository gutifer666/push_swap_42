/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:14:38 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/11 09:02:54 by frgutier         ###   ########.fr       */
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
	while ((*stack)->index != 0) // Este bucle es para que el primer elemento sea 0
	{
		rotate(stack);
		i++; // i es el número de veces que se ha rotado la lista
	}
	if (is_sorted(stack) == 1) // Comprueba si la lista está ordenada
	{
		if (i > (size / 2)) // Si i es mayor que la mitad de la lista, se rota al revés
		{
			if (size == 5 && i == 3) // Si la lista tiene 5 elementos y se ha rotado 3 veces, se rota 2 veces al revés porque es más eficiente que rotar 3 veces, es un caso especial
				ft_printf("rra\n");
			ft_printf("rra\n");
		}
		else // Si no, se rota normalmente
			while (i-- > 0) // Se rota tantas veces como i
				ft_printf("ra\n");
		return (1); // Devuelve 1 si la lista está ordenada
	}
	else // Si la lista no está ordenada, se rota al revés tantas veces como i
		while (i-- > 0) 
			reverse_rotate(stack);
	return (0); // Devuelve 0 si la lista no está ordenada
}
