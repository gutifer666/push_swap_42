/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:36:57 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/11 08:25:59 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

static	void	clear_stack(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	clear_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

static	int	init_stack(t_list **a_stack)
{
	list_append(a_stack, new_node(7));
	list_append(a_stack, new_node(3));
	list_append(a_stack, new_node(2));
	return (1);
}

static	int	content(t_list *stack)
{
	return (stack->num);
}

static	int	index(t_list *stack)
{
	return (stack->index);
}

static	void	print_stack(t_list *stack)
{
	if (!stack)
		return ;
	printf("%d -> %d\n", content(stack), index(stack));
	print_stack(stack->next);
	printf("\n");
}

int	main(void)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	init_stack(&a_stack);
	assign_ascending_index(&a_stack);
	ft_printf("Stack A\n");
	print_stack(a_stack);
	sort_three_elements(&a_stack);
	ft_printf("Stack A\n");
	print_stack(a_stack);
	
	clear_stack(&a_stack);
	clear_stack(&b_stack);
	system("leaks push_swap");
	return (0);
}
