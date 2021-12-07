/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:40:28 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/12/07 16:03:56 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi2(char *str)
{
	int	i;
	int	num;
	int	signo;

	i = 0;
	num = 0;
	signo = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signo++;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num == 2147483647) || (num == -2147483648))
		exit(0);
	return (signo * num);
}

int	size_a(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack->a[len])
		len++;
	return (len);
}

int	size_b(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack->b[len])
		len++;
	return (len);
}

void	error_message(void)
{
	write(1, "Error\n", 5);
	exit(0);
}

void	is_nbr(int argc, char **argv)
{
	int	i;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] >= '0' && argv[i][j] <= '9')
			j++;
		else
			error_message();
		i++;
	}
}
