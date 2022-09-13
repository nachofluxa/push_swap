/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:39:32 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/09/06 13:41:38 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack, int w)
{
	int	i;
	int	aux;

	i = 0;
	while (stack->a[i])
		i++;
	aux = stack->a[i];
	i = 1;
	while (stack->a[i])
	{
		stack->a[i] = stack->a[i - 1];
		i++;
	}
	stack->a[0] = aux;
	if (w == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack, int w)
{
	int	i;
	int	aux;

	i = 0;
	while (stack->b[i])
		i++;
	aux = stack->b[i];
	i = 1;
	while (stack->b[i])
	{
		stack->b[i] = stack->b[i - 1];
		i++;
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
