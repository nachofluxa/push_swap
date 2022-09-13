/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:39:32 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/09/06 13:40:45 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack, int w)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (stack->a[i])
		i++;
	aux = stack->a[0];
	j = 1;
	while (j <= i)
	{
		stack->a[j - 1] = stack->a[j];
		j++;
	}
	stack->a[i] = aux;
	if (w == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack, int w)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (stack->b[i])
		i++;
	aux = stack->b[0];
	j = 1;
	while (j <= i)
	{
		stack->b[j - 1] = stack->b[j];
		j++;
	}
	stack->b[i] = aux;
	if (w == 1)
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	write(1, "rr\n", 3);
}
