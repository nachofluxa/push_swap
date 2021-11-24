/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:58:58 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/24 13:04:50 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	aux;

	if (stack->a[0] && stack->a[1])
	{
		aux = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = aux;
	}
}

void	swap_b(t_stack *stack)
{
	int	aux;

	if (stack->b[0] && stack->b[1])
	{
		aux = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = aux;
	}
}

void	swap_a_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	push_a(t_stack *stack)
{
	int	i;
	int	aux;

	i = size_a(stack) + 1;
	if (!stack->b[0])
		return ;
	while (stack->a[i])
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = size_a(stack);
	while (stack->b[i])
	{
		aux = stack->b[i];
		stack->b[i] = stack->b[i - 1];
		stack->b[i - 1] = aux;
		i--;
	}
}

void	push_b(t_stack *stack)
{
	int	i;
	int	aux;

	i = size_b(stack) + 1;
	if (!stack->a[0])
		return ;
	while (stack->a[i])
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = size_b(stack);
	while (stack->b[i])
	{
		aux = stack->b[i];
		stack->b[i] = stack->b[i - 1];
		stack->b[i - 1] = aux;
		i--;
	}
}