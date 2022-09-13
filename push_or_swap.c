/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:55:54 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/09/06 13:56:45 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack, int w)
{
	int	aux;

	if (stack->a[0] && stack->a[1])
	{
		aux = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = aux;
	}
	if (w == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack, int w)
{
	int	aux;

	if (stack->b[0] && stack->b[1])
	{
		aux = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = aux;
	}
	if (w == 1)
		write(1, "sb\n", 3);
}

void	swap_a_b(t_stack *stack)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	write (1, "ss\n", 3);
}

void	push_a(t_stack *stack)
{
	int	i;
	int	j;

	if (size_stack(stack, 1) > 0)
	{
		i = size_stack(stack, 0) + 1;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		j = size_stack(stack, 1) - 1;
		while (++i < j)
			stack->b[i] = stack->b[i + 1];
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	int	i;
	int	j;

	if (size_stack(stack, 0) > 0)
	{
		i = size_stack(stack, 1) + 1;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		j = size_stack(stack, 0) - 1;
		while (++i < j)
			stack->a[i] = stack->a[i + 1];
	}
	write(1, "pb\n", 3);
}
