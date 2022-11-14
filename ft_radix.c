/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:37:47 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/11/14 13:14:59 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_stack *stack)
{
	int *aux;
	int max;
	int max_bits;
	int index;
	int i;

	i = 0;
	index = stack->size_a / 2;
	booble_sort(stack);
	max = stack->sorted[index];
	aux = stack->sorted;
	max_bits = 0;
	while (++i < stack->size_a)
	{
		if (stack->sorted[i] > max)
			max = aux[i];
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack)
{
	int *aux;
	int max_bits;
	int i;
	int j;
	int index;

	aux = stack->a;
	max_bits = get_max_bits(stack);
	i = -1;
	index = stack->size_a / 2;
	while (++i < max_bits)
	{
		j = 0;
		while (++j < stack->size_a)
		{
			aux = stack->a;
			if (((stack->sorted[index] >> i) & 1) == 1)
				rotate_a(stack, 1);
			else
				push_b(stack);
		}
		while (stack->size_b > 0)
			push_a(stack);
	}
	i = 0;
	while (i < stack->size_a)
	{
		printf("%d\n", stack->a[i]);
		i++;
	}
}
