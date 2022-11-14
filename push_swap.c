/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:04:45 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/11/14 10:50:57 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 1)
		error_message();
	else
	{
		mount_stack(argc, argv, &stack);
		check_repeat_numbers(&stack);
		nbr_arg(&stack, argc);
	}
	//free_stack(&stack);
	return (0);
}

void	mount_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	stack->a = ft_calloc(sizeof(int), argc - 1);
	stack->b = ft_calloc(sizeof(int), argc - 1);
	stack->sorted = ft_calloc(sizeof(int), argc - 1);
	stack->size_a = 0;
	while (i < argc && argv[j])
	{
		check_argv(argv[j]);
		stack->a[i] = get_nbrs(argv[j]);
		stack->size_a++;
		i++;
		j++;
	}
	if (check_if_sorted(stack) == 0)
	{
		printf ("Error: The stack is already sorted\n");
		exit(0);
	}
}

void	nbr_arg(t_stack *stack, int argc)
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
	else if (nbr > 5 && nbr < 250)
	{
		stack->chunk_size = 10;
		//sort_big_stack(stack);
		radix_sort(stack);
	}
	else
	{
		stack->chunk_size = 20;
		//sort_big_stack(stack);
		radix_sort(stack);
	}
}

int	get_nbrs(char *aux)
{
	int				i;
	int				j;
	unsigned int	k;

	i = 0;
	j = 1;
	if (aux[i] == '-' || aux[i] == '+')
	{
		if (aux[i] == '-')
			j = -1;
		i++;
	}
	k = 0;
	while (aux[i] >= '0' && aux[i] <= '9')
	{
		k = (k * 10) + (aux[i] - '0');
		if ((k > 2147483647 && j == 1) || (k > 2147483648 && j == -1))
			error_message();
		i++;
	}
	return (k * j);
}
