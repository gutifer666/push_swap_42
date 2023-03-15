/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:20:25 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/15 08:15:43 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

/*
** Devuelve el número máximo de bits necesarios 
** para representar el valor máximo de un conjunto de nodos en una lista
*/
static	int	get_max_bit_length(t_list **stack)
{
	t_list	*list;
	int		max_value;
	int		max_bit_length;

	list = *stack;
	max_value = list->index;
	max_bit_length = 0;
	while (list)
	{
		if (list->index > max_value)
			max_value = list->index;
		list = list->next;
	}
	while ((max_value >> max_bit_length) != 0)
		max_bit_length++;
	return (max_bit_length);
}

/*
El algoritmo funciona separando los números en la lista en dígitos individuales
y ordenándolos según cada dígito. En esta implementación, se itera a través 
de cada bit en los números, desde el bit más bajo hasta el más alto.
En cada iteración, se itera a través de cada número en la lista y se comprueba 
el valor del bit en esa posición. Si el bit es 0, se empuja el número a otra 
lista enlazada (b_stack) usando la función pb. Si el bit es 1, 
se rota la lista original enlazada (a_stack) usando la función ra.
Después de ordenar por un bit, se mueven los elementos de la lista enlazada 
b_stack a la lista original enlazada a_stack utilizando la función pa. 
Luego, se procede a ordenar por el siguiente bit hasta que se hayan ordenado
todos los bits.
*/
void	radix_sort(t_list **a_stack, t_list **b_stack)
{
	t_list	*list;
	int		i;
	int		j;
	int		size;
	int		max_bit_length;

	list = *a_stack;
	size = list_size(*a_stack);
	max_bit_length = get_max_bit_length(a_stack);
	i = -1;
	while (++i < max_bit_length)
	{
		j = -1;
		while (++j < size)
		{
			list = *a_stack;
			if (((list->index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(a_stack);
		}
		while (list_size(*b_stack) != 0)
			pa(a_stack, b_stack);
	}
}
