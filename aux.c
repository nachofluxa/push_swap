/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:04 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/08 11:18:20 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*remove_first(t_list **list)
{
	t_list	*first;
	size_t	size_list;

	if (!list)
		return (NULL);
	size_list = ft_lstsize(*list);
	if (size_list == 0)
		return (NULL);
	first = *list;
	*list = first->next;
	first->next = NULL;
	return (first);
}

t_list	*remove_last(t_list **list)
{
	t_list	*last;
	t_list	*aux;
	size_t	size_list;

	if (!list)
		return (NULL);
	size_list = ft_lstsize(*list);
	if (size_list == 0)
		return (NULL);
	last = ft_lstlast(*list);
	if (size_list == 1)
	{
		*list = NULL;
		return (last);
	}
	aux = *list;
	while (aux->next != last)
		aux = aux->next;
	aux->next = NULL;
	return (last);
}

char	**aux_split(char *to_split)
{
	int	i;

	i = -1;
	if (ft_strlen(to_split) == 0)
		exit(0);
	while (to_split[++i])
	{
		if (to_split[i] == '\t' || to_split[i] == '\n' || to_split[i] == '\v'
			|| to_split[i] == '\r' || to_split[i] == '\f')
			to_split[i] = ' ';
	}
	return (ft_split(to_split, ' '));
}

void	set_final_order(t_list **list)
{
	t_list	**aux;
	ssize_t	max_order;
	int		size;

	size = ft_lstsize(*list);
	if (size == 2 && obj_value(*list) > obj_value(ft_lstlast(*list)))
		rotate_a(list, 0);
	else if (size == 1 || size == 2)
		error_message(1);
	else if (size == 3)
		check_3_numbers(list);
	if (size < 4)
		return ;
	aux = ft_calloc(1, sizeof(t_list **));
	check_aux_list(list, aux);
	max_order = set_orders(list);
	if (is_ordered(list, aux) == 0)
		aux_order(list, aux, size, max_order);
	else
		error_message(1);
	ft_lstclear(aux, *free);
	free(aux);
}

void	aux_order(t_list **a, t_list **b, int size, ssize_t order)
{
	if (size == 4)
		order_4(a, b);
	else if (size == 5)
	{
		help_order_5(a, size, 0);
		push_b(a, b);
		help_order_5(a, size, 1);
		push_b(a, b);
		order_3(a);
		push_a(a, b);
		push_a(a, b);
	}
	else
		ini_radix(a, b, order);
}
