/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:37:47 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/11/16 11:56:50 by ifluxa-c         ###   ########.fr       */
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
	int aux_size;
	int max_bits;
	int i;
	int j;

	aux_size = stack->size_a;
	max_bits = get_max_bits(stack);
	i = -1;
	while(++i < max_bits)
	{
		j = 0;
		while (j++ < aux_size)
		{
			aux = stack->a;
			if (((aux->index >>  i) & 1) == 1)
				rotate_a(stack, 1);
			else
				push_b(stack);
		}
		while (stack->size_b > 0)
			push_a(stack);
	}
}
/*typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;*/