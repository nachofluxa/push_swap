/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:04:45 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/04 13:22:46 by ifluxa-c         ###   ########.fr       */
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
		check_repeat_numbers(&stack);
		nbr_arg(&stack, argc);
	}
	return (0);
}

void	mount_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 1;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			l = 0;
			check_argv(argv[i]);
			while (argv[i][j] == ' ' && argv[i][j++])
				k++;
			while (((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j++])
				j++;
			if (l > 0)
			{

			}

			k += l;
		}
		i++;
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
	/*else
		sort_big_stack(stack);
*/}

int	get_nbrs(char *aux)
{
	int				i;
	int				j;
	unsigned int	k;

	i = 0;
	while (aux[i] <= 13 || aux[i] == ' ')
		i++;
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
