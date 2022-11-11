/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:24:34 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/11/11 11:36:03 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_nbr(int a, int *sorted, int size)
{
	int	x;

	x = -1;
	while (++x < size)
		if (a == sorted[x])
			return (1);
	return (0);
}

void	booble_sort(t_stack *stack)
{
	int	x[2];
	int	aux;

	x[0] = -1;
	while (++x[0] < stack->size_a)
	{
		aux = found_max(stack->a, stack->size_a);
		x[1] = -1;
		while (++x[1] < stack->size_a)
		{
			if (aux > stack->a[x[1]] \
				&& try_nbr(stack->a[x[1]], stack->sorted, stack->size_a) == 0)
				aux = stack->a[x[1]];
		}
		stack->sorted[x[0]] = aux;
	}
}

void	rotate_and_push_a(int aux, t_stack *stack)
{
	int	flag;

	flag = side_of_nbr(aux, stack->a, stack->size_a);
	if (flag == 0)
		while (stack->a[0] != aux)
			rotate_a(stack, 1);
	else
		while (stack->a[0] != aux)
			reverse_rotate_a(stack, 1);
	push_b(stack);
}

void	rotate_and_push_b(int aux, t_stack *stack)
{
	int	flag;

	flag = side_of_nbr(aux, stack->b, stack->size_b);
	if (flag == 0)
		while (stack->b[0] != aux)
			rotate_b(stack, 1);
	else
		while (stack->b[0] != aux)
			reverse_rotate_b(stack, 1);
	push_a(stack);
}

void	sort_big_stack(t_stack *stack)
{
	int	compare[2];
	int	aux;

	compare[0] = stack->size_a / 2 - stack->chunk_size;
	compare[1] = stack->size_a / 2 + stack->chunk_size;
	if (compare[0] < 0)
		compare[0] = 0;
	if (compare[1] > stack->size_a)
		compare[1] = stack->size_a - 1;
	booble_sort(stack);
	while (stack->size_a)
	{
		if (any_chunk_left(stack->a, stack->size_a, compare, stack->sorted) == 1)
		{
			aux = best_nbr(stack, compare);
			rotate_and_push_a(aux, stack);
		}
		else
		{
			compare[0] -= stack->chunk_size;
			compare[1] += stack->chunk_size;
			if (compare[0] < 0)
				compare[0] = 0;
			if (compare[1] > stack->size_a)
				compare[1] = stack->size_a - 1;
		}
	}
	while(stack->size_b)
	{
		int i = -1;
		while (++i < stack->size_b)
			printf("%d\n", stack->b[i]);
		printf("AQUI TERMINA\n");
		sleep(1);
		aux = found_max(stack->b, stack->size_b);
		rotate_and_push_b(aux, stack);
	}
}
