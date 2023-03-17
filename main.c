/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:36:57 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/17 08:35:50 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

static int	check_duplicate_values(t_list *head)
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
				return (-1);
		}
		head = head->next;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

static	void	clear_stack(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	clear_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

static int	init_stack(int ac, char **av, t_list **a_stack)
{
	int			i;
	int			j;
	char		**split;

	i = 1;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (0);
		while (split[j])
		{
			if (ft_atoi(split[j]) > INT_MAX
				|| ft_atoi(split[j]) < INT_MIN)
				return (0);
			list_append(a_stack, new_node(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
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


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack(argc, argv, &stack_a);
	if (check_duplicate_values(stack_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}else
	{
		print_stack(stack_a);
	}


	clear_stack(&stack_a);
	clear_stack(&stack_b);
	system("leaks push_swap");
	return (0);
}
