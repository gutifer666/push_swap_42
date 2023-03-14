/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:17:20 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/14 09:11:54 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	sort_three_elements(t_list **stack)
{
	while (is_sorted(stack) != 1)
	{
		if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index < (*stack)->next->next->index))
			sa(stack);
		else if (((*stack)->index > ((*stack)->next->index))
			&& ((*stack)->index > (*stack)->next->next->index))
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_four_elements(t_list **a_stack, t_list **b_stack)
{
	if (is_order(a_stack, 4) == 1)
		return ;
	rotate_min_node_to_head(a_stack, 4);
	pb(a_stack, b_stack);
	reset_index(a_stack);
	sort_three_elements(a_stack);
	pa(a_stack, b_stack);
}

void	sort_five_elements(t_list **a_stack, t_list **b_stack)
{
	if (is_order(a_stack, 5) == 1)
		return ;
	rotate_min_node_to_head(a_stack, 5);
	pb(a_stack, b_stack);
	reset_index(a_stack);
	sort_four_elements(a_stack, b_stack);
	pa(a_stack, b_stack);
}

void	sort_small_stack(t_list **a_stack, t_list **b_stack)
{
	int	size;

	size = list_size(*a_stack);
	if (size == 3)
		sort_three_elements(a_stack);
	else if (size == 4)
		sort_four_elements(a_stack, b_stack);
	else
		sort_five_elements(a_stack, b_stack);
}
