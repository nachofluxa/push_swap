/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:39:32 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/19 13:48:11 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack, int w)
{
	int	i;
	int	aux;

	aux = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = aux;
	if (w == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack, int w)
{
	int	i;
	int	aux;

	aux = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = aux;
	if (w == 1)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack, 0);
	reverse_rotate_b(stack, 0);
	write (1, "rrr\n", 4);
}
