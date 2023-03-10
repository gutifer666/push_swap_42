/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:36:57 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/10 08:23:07 by frgutier         ###   ########.fr       */
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
	for (int i = 3; i > 0; i--)
	{
		list_append(a_stack, new_node(i));
	}
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
	ft_printf("Stack B\n");
	print_stack(b_stack);
	pb(&a_stack, &b_stack);
	ft_printf("Stack A\n");
	reset_index(&a_stack);
	print_stack(a_stack);
	ft_printf("Stack B\n");
	reset_index(&b_stack);
	print_stack(b_stack);
	rr(&a_stack, &b_stack);
	ft_printf("Stack A\n");
	print_stack(a_stack);
	ft_printf("Stack B\n");
	print_stack(b_stack);
	clear_stack(&a_stack);
	clear_stack(&b_stack);
	system("leaks push_swap");
	return (0);
}
