/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:41:09 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/25 10:31:17 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	clear_stack(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	clear_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

int	check_duplicate_values(t_list *head)
{
	int		current_value;
	t_list	*comparison_node;

	while (head && head->next)
	{
		current_value = head->num;
		comparison_node = head;
		while (comparison_node->next)
		{
			comparison_node = comparison_node->next;
			if (comparison_node->num == current_value)
			{
				return (-1);
			}
		}
		head = head->next;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
