/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:48:04 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/16 12:40:25 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		exit(0);
	create_list(&stack, argc, argv);
}

void	create_list(t_stack *stack, int argc, char **argv)
{
	char	***l;
	int		i;
	int		j;

	l = NULL;
	i = -1;
	j = 0;
	l = malloc(sizeof(char **) * argc);
	while (i++ < argc - 1)
	{
		argv = argv + 1;
		l[i] = ft_split((char *)argv, ' ');
	}
	stack->a = malloc(sizeof(int) * size_la(stack));
	stack->b = malloc(sizeof(int) * size_lb(stack));
	while (j++ < argc - 1)
	{
		i = 0;
		while (i++)
		{
			l[j] = atoi(l);
		}
	}
}

int	size_la(t_stack *stack)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (stack->a[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	size_lb(t_stack *stack)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (stack->b[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	free_aux(char ***l)
{
	int	i;
	int	j;

	i = 0;
	while (l[i])
	{
		j = 0;
		while (l[i][j])
		{
			free(l[i][j]);
			j++;
		}
		free(l[i]);
		i++;
	}
	free(l);
}
