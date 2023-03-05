/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:36:57 by frgutier          #+#    #+#             */
/*   Updated: 2023/03/05 12:45:13 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int	main(void)
{
	t_node  *init;
	int     num;

	init = NULL;
	insert_init(&init, 1);
	insert_init(&init, 2);
	insert_init(&init, 3);

	while (init != NULL)
	{
		num = init->num;
		printf("%d\n", num);
		init = init->next;
	}
	return (0);
}