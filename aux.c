/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:03:50 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/19 13:36:51 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nbr(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '+' \
		|| str[i][j] == '-' || str[i][j] == ' ')
		{
			j++;
			i++;
		}
		else
			return (-1);
	}
	return (1);
}

int	found_min(int *list, int size)
{
	int	min;
	int	i;

	i = 0;
	min = list[0];
	while (i < size)
	{
		if (min > list[i])
			min = list[i];
		i++;
	}
	return (min);
}

int	found_max(int *list, int size)
{
	int	max;
	int	i;

	i = 0;
	while (i < size)
	{
		if (max < list[i])
			max = list[i];
		i++;
	}
	return (max);
}

int	size_stack(t_stack *stack, int aux)
{
	int	size;

	size = 0;
	if (aux == 0)
	{
		while (stack->a[size])
			size++;
	}
	else if (aux == 1)
	{
		while (stack->b[size])
			size++;
	}
	return (size);
}
