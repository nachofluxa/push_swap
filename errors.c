/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:07:03 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/19 14:27:08 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	check_repeat_numbers(t_stack *stack)
{
	int	i;
	int	repeat;
	int x;

	i = -1;
	repeat = 0;
	while (++i < stack->size_a && repeat == 0)
	{
		x = -1;
		while (++x < stack->size_a)
		{
			if (stack->a[x] == stack->a[i] && x != i)
				repeat = 1;
		}
			
	}
	if (repeat == 1)
		error_message();
}

void	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			error_message();
		i++;
	}
}

int	check_if_sorted(t_stack *stack)
{
	int i;
	int sorted;

	sorted = 0;
	i = 0;
	while (i < stack->size_a - 1 && sorted == 0)
	{
		if (stack->a[i] > stack->a[i + 1])
			sorted++;
		i++;
	}
	return (sorted);
}