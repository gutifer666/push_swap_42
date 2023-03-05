/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:37:20 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/05 12:45:07 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include	"libft/libft.h"
# include   <stdio.h>
/*
**  Lista enlazada para guardar los datos de entrada y ordenarlos
*/
typedef struct node
{
    int				num;
    struct node		*next;
}					t_node;

typedef struct list
{
    t_node  *head;
}               t_list;

t_node  *create_node(t_node **init, int num);
void    destroy_node(t_node *node);
void    prepend_node(t_list *list, int num);
void    append_node(t_list *list, int num);

#endif
