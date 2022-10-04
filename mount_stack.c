/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:24:13 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/04 12:25:16 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mount_stack2(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a[i] < stack->a[i + 1])
		swap_a(stack, 1);
}

void	mount_stack3(t_stack *stack)
{
	int	min;

	min = found_min(stack->a);
	if (min == stack->a[1])
		swap_a(stack, 1);
	else if (min == stack->a[2])
		reverse_rotate_a(stack, 1);
	push_a(stack);
	mount_stack2(stack);
	push_b(stack);
}

void	mount_stack4(t_stack *stack)
{
	int	min;

	min = found_min(stack->a);
	if (min == stack->a[1])
		swap_a(stack, 1);
	else if (min == stack->a[2])
	{
		rotate_a(stack, 1);
		swap_a(stack, 1);
	}
	else if (min == stack->a[3])
		reverse_rotate_a(stack, 1);
	push_a(stack);
	mount_stack3(stack);
	push_b(stack);
}

void	mount_stack5(t_stack *stack)
{
	int	min;

	min = found_min(stack->a);
	if (min == stack->a[1])
		swap_a(stack, 1);
	else if (min == stack->a[2])
	{
		rotate_a(stack, 1);
		swap_a(stack, 1);
	}
	else if (min == stack->a[3])
	{
		reverse_rotate_a(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	else if (min == stack->a[4])
		reverse_rotate_a(stack, 1);
	push_a(stack);
	mount_stack4(stack);
	push_b(stack);
}
