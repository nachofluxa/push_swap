/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:04:45 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/09/21 10:24:34 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 1)
		exit(0);
	else
	{
		mount_stack(argc, argv, &stack);
		nbr_arg(argc, &stack);
	}
	return (0);
}

void	mount_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	int		k;
	char	**list;

	i = -1;
	list = malloc(sizeof(char *) * argc);
	j = 0;
	while (i++ < argc - 1)
	{
		argv += 1;
		list[i] = ft_split((char *) * argv, ' ');
	}
	stack->a = malloc(sizeof(int) * argc - 1);
	stack->b = malloc(sizeof(int) * argc - 1);
	k = -1;
	while (list[j])
	{
		i = 0;
		while(list[i][j])
			stack->a[k++] = ft_atoi(l[i][j]);
	}
}

void	nbr_arg(int argc, t_stack *stack)
{
	int	nbr;

	nbr = argc - 1;
	if (nbr == 2)
		mount_stack2(stack);
	else if (nbr == 3)
		mount_stack3(stack);
	else if (nbr == 4)
		mount_stack4(stack);
	else if (nbr == 5)
		mount_stack5(stack);
	else
		sort_big_stack(stack);
}
