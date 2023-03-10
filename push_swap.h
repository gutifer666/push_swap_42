/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:37:20 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/14 09:48:28 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include	"libft/libft.h"
# include   <stdio.h>

/*
**  Lista doblemente enlazada
*/
typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

/*
**  Funciones de la lista
*/
void	list_prepend(t_list **stack, t_list *news);
void	list_append(t_list **stack, t_list *news);
t_list	*new_node(int num);
t_list	*list_last(t_list *stack);
int		list_size(t_list *stack);
/*
**  Funciones de indexación
*/
void	assign_ascending_index(t_list **stack);
void	reset_index(t_list **stack);

/*
** Operaciones del push_swap
*/

// swap
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// push
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// rotate
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rotate_min_node_to_head(t_list **stack, int size);

// reverse rotate
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*
**  Utilidades de ordenación
*/
int		is_sorted(t_list **stack);
int		is_order(t_list **stack, int size);

/*
**  Funciones de ordenación de stacks pequeños
*/
void	sort_three_elements(t_list **stack);
void	sort_four_elements(t_list **a_stack, t_list **b_stack);
void	sort_five_elements(t_list **a_stack, t_list **b_stack);
void	sort_small_stack(t_list **a_stack, t_list **b_stack);

/*
**  Funciones de ordenación de stacks grandes
*/
void	radix_sort(t_list **a_stack, t_list **b_stack);
#endif
