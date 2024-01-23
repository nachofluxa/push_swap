/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:28 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/08 11:25:45 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mount_two_args(char **argv)
{
	t_list	**list;
	char	**aux;
	char	*to_split;
	int		i;

	to_split = ft_strtrim(argv[1], " \t\n\v\r\f");
	aux = aux_split(to_split);
	check_two_args(aux);
	list = ft_calloc(1, sizeof(t_list **));
	if (!list)
	{
		free(aux);
		exit(0);
	}
	i = 0;
	*list = ft_lstnew(new_obj(ft_atoi(aux[i]), -1));
	while (aux[++i])
		if (ft_strlen(aux[i]))
			ft_lstadd_back(list, ft_lstnew(new_obj(ft_atoi(aux[i]), -1)));
	set_final_order(list);
	free_two_args(list, aux, to_split);
}

void	free_two_args(t_list **list, char **aux, char *to_split)
{
	int	i;

	ft_lstclear(list, *free);
	free(list);
	i = 0;
	while (aux[i])
		free(aux[i++]);
	free(aux);
	free(to_split);
}

void	mount_multiple_args(int argc, char **argv)
{
	t_list	**list;
	int		i;

	list = ft_calloc(1, sizeof(t_list **));
	if (!list)
		exit(1);
	i = 1;
	check_argv(argc, &argv[i]);
	*list = ft_lstnew(new_obj(ft_atoi(argv[i]), -1));
	if (!list)
		exit(1);
	while (++i < argc && argv[i])
	{
		check_argv(argc, &argv[i]);
		ft_lstadd_back(list, ft_lstnew(new_obj(ft_atoi(argv[i]), -1)));
	}
	set_final_order(list);
	ft_lstclear(list, *free);
	free(list);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	else if (argc == 2)
		mount_two_args(argv);
	else
		mount_multiple_args(argc, argv);
	return (0);
}
