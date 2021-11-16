/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:58:58 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/16 12:50:25 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack)
{
	int	i;

	i = size_la(stack);
	while (stack->a[i])
		stack->a[i--] = stack->a[i];
	stack->a[0] = stack->b[0];
}

void	push_b(t_stack *stack)
{
	int	i;

	i = size_lb(stack);
	while (stack->b[i])
		stack->b[i--] = stack->b[i];
	stack->b[0] = stack->a[0];
}
