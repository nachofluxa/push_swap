/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:55:54 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/19 12:28:24 by ifluxa-c         ###   ########.fr       */
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

	if (stack->size_b > 0)
	{
		i = stack->size_a + 1;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		j = stack->size_b - 1;
		while (++i < j)
			stack->b[i] = stack->b[i + 1];
		stack->size_a++;
		stack->size_b--;
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 0)
	{
		i = stack->size_b + 1;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		j = stack->size_a - 1;
		while (++i < j)
			stack->a[i] = stack->a[i + 1];
		stack->size_b++;
		stack->size_a--;
	}
	write(1, "pb\n", 3);
}
