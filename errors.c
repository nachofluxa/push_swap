/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:07:03 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/04 13:19:54 by ifluxa-c         ###   ########.fr       */
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

	i = 0;
	repeat = 0;
	if (stack->a)
	{
		while (stack->a[i] && repeat == 0)
		{
			if (stack->a[i + 1] == stack->a[i]
				|| stack->a[i - 1] == stack->a[i])
				repeat = 1;
			else
				i++;
		}
	}
	if (repeat == 1)
		error_message();
}

void	check_argv(char *argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9') || (argv[i] == '-')
			|| argv[i] == '+' || argv[i] == ' ')
			error_message();
		i++;
	}
}
