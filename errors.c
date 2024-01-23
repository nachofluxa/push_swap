/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:23 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/06 12:48:15 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_list **a, t_list **b)
{
	t_list	*aux;
	int		ordered;

	if (*a && *b)
		if (obj_order(*a) < obj_order(*b))
			return (0);
	ordered = 1;
	aux = *a;
	while (ordered && aux)
	{
		if (aux->next && obj_order(aux) > obj_order(aux->next))
			ordered = 0;
		aux = aux->next;
	}
	aux = *b;
	while (ordered && aux)
	{
		if (aux->next && obj_order(aux) > obj_order(aux->next))
			ordered = 0;
		aux = aux->next;
	}
	return (ordered);
}

int	check_just_one(t_list **list)
{
	t_list	*aux;
	int		ordered;

	ordered = 1;
	aux = *list;
	while (ordered && aux)
	{
		if (aux->next && obj_value(aux) > obj_value(aux->next))
			ordered = 0;
		aux = aux->next;
	}
	return (ordered);
}

void	check_aux_list(t_list **list, t_list **aux)
{
	if (!aux)
	{
		ft_lstclear(list, *free);
		free(list);
		exit(0);
	}
}

void	error_message(int type)
{
	if (type == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (type == 1)
		return ;
}

void	check_argv(int argc, char *argv[])
{
	int		i;
	int		j;
	long	n;

	if (argc < 2)
		exit(0);
	i = -1;
	while (argv[++i])
	{
		n = ft_strlen(argv[i]);
		if (n > 11 || (n > 10 && argv[i][0] != '-'))
			error_message(0);
		if (!is_number((char *)argv[i]))
			error_message(0);
		if (ps_atoi(argv[i]) == 6666666666)
			error_message(0);
		j = i;
		while (argv[++j])
			if (n == (long)ft_strlen(argv[j]) && !ft_strncmp(argv[i], argv[j],
					n))
				error_message(0);
	}
}
