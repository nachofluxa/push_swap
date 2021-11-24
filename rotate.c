/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:25:29 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/24 11:43:48 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_stack *stack)
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
}

void	rotate_b(t_stack *stack)
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
}

void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
