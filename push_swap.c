/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:04:45 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/09/13 12:10:48 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 1)
		exit(0);
	else
	{
		mount_stack(argc, argv, &stack);
		nbr_arg(argc, &stack);
	}
	return (0);
}

void	mount_stack(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (i++ < argc - 1)
	{
		argv += 1;
		
	}
	stack->a = malloc(sizeof(int) * argc - 1);
	stack->b = malloc(sizeof(int) * argc - 1);
}

void	nbr_arg(int argc, t_stack *stack)
{
	int	nbr;

	nbr = argc - 1;
	if (nbr == 2)
		sort_small_stack(stack, 2);
	else if (nbr == 3)
		sort_small_stack (stack, 3);
	else if (nbr == 4)
		sort_small_stack(stack, 4);
	else if (nbr == 5)
		sort_small_stack(stack, 5);
	else
		sort_big_stack(stack);
}
