/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:25:29 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/24 12:55:52 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack)
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
}


void	reverse_rotate_b(t_stack *stack)
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
}

void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
