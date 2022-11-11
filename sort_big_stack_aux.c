/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:28:55 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/11/11 11:35:58 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	side_of_nbr(int aux, int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (stack[i] == aux)
			break ;
	if (i < size / 2)
		return (0);
	else
		return (1);
}

int	best_nbr(t_stack *stack, int compare[])
{
	int	options[2];
	int	i[2];

	i[0] = -1;
	while (++i[0] < stack->size_a)
		if (stack->a[i[0]] >= stack->sorted[compare[0]]
			&& stack->a[i[0]] <= stack->sorted[compare[1]])
		{
			options[0] = stack->a[i[0]];
			break ;
		}
	i[1] = stack->size_a;
	while (--i[1] < stack->size_a)
		if (stack->a[i[1]] >= stack->sorted[compare[0]]
			&& stack->a[i[1]] <= stack->sorted[compare[1]])
		{
			options[1] = stack->a[i[1]];
			break ;
		}
	if (i[0] < (stack->size_a - i[1]))
		return (options[0]);
	else
		return (options[1]);
}

int	any_chunk_left(int *stack, int size, int compare[], int *sorted)
{
	int	x;

	x = -1;
	while (++x < size)
	{
		if (stack[x] >= sorted[compare[0]]
			&& stack[x] <= sorted[compare[1]])
			return (1);
	}
	return (0);
}
