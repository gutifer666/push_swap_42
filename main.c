/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:36:57 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/25 12:14:54 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

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
			return (clean_init(split, a_stack));
		while (split[j])
		{
			if (ft_atol(split[j]) > INT_MAX
				|| ft_atol(split[j]) < INT_MIN || !is_number(split[j]))
				return (clean_init(split, a_stack));
			list_append(a_stack, new_node(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

/*
** Memory leaks
*/
void	check_memory_leaks(void)
{
	system("leaks push_swap");
	exit(0);
}

void	select_algorithm(t_list **a_stack, t_list **b_stack)
{
	if (list_size(*a_stack) <= 5)
		sort_small_stack(a_stack, b_stack);
	else
		radix_sort(a_stack, b_stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (init_stack(argc, argv, &stack_a) == 0)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	else if (check_duplicate_values(stack_a) == -1)
	{
		clear_stack(&stack_a);
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	}
	else
	{
		assign_ascending_index(&stack_a);
		if (is_sorted(&stack_a) != 1)
			select_algorithm(&stack_a, &stack_b);
	}
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
