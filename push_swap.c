/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:48:04 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/24 13:19:46 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		exit(0);
	else
		create_list(&stack, argc, argv);
}

void	create_list(t_stack *stack, int argc, char **argv)
{
	char	***l;
	int		i;
	int		j;

	l = NULL;
	i = -1;
	j = -1;
	l = malloc(sizeof(char **) * argc);
	while (i++ < argc - 1)
	{
		argv = argv + 1;
		l[i] = ft_split((char *)argv, ' ');
	}
	stack->a = malloc(sizeof(int) * size_l(l));
	stack->b = malloc(sizeof(int) * size_l(l));
	while (j++ < argc - 1)
	{
		i = 0;
		while (l[j][i])
		{
			stack->a[i] = atoi2(l[j][i]);
			i++;
		}
	}
	free_aux(l);
}

int	size_l(char ***l)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (l[i])
	{
		j = 0;
		while (l[i][j])
		{
			j++;
			count++;
		}
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
