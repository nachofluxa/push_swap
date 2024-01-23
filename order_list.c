/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:26 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/08 11:17:44 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_3(t_list **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = obj_value(*a);
	n2 = obj_value((*a)->next);
	n3 = obj_value(ft_lstlast(*a));
	if (n3 > n2 && n1 > n3)
		rotate_a(a, 0);
	else if (n1 > n2 && n2 > n3)
	{
		rotate_a(a, 0);
		swap_a(a, 0);
	}
	else if (n1 > n2 && n3 > n1)
		swap_a(a, 0);
	else if (n1 > n3 && n2 > n1)
		reverse_rotate_a(a, 0);
	else if (n3 > n1 && n2 > n3)
	{
		reverse_rotate_a(a, 0);
		swap_a(a, 0);
	}
}

void	order_4(t_list **a, t_list **b)
{
	int		pos;
	t_list	*aux;

	pos = 0;
	aux = *a;
	while (aux->next && obj_order(aux) != 0)
	{
		aux = aux->next;
		pos++;
	}
	if (pos == 1)
		swap_a(a, 0);
	else if (pos == 2)
	{
		rotate_a(a, 0);
		swap_a(a, 0);
	}
	else if (pos == 3)
		reverse_rotate_a(a, 0);
	push_b(a, b);
	order_3(a);
	push_a(a, b);
}

void	help_order_5(t_list **a, int size, ssize_t order)
{
	int		pos;
	t_list	*curr;

	pos = 0;
	curr = *a;
	while (obj_order(curr) != order)
	{
		curr = curr->next;
		pos++;
	}
	if (pos > (size / 2))
		while (obj_order(*a) != order)
			reverse_rotate_a(a, 0);
	else
		while (obj_order(*a) != order)
			rotate_a(a, 0);
}

void	order_radix(t_list **a, t_list **b, ssize_t radix)
{
	int		size;
	ssize_t	order;

	size = ft_lstsize(*a);
	while (0 < size--)
	{
		if (is_ordered(a, b))
			break ;
		order = obj_order(*a);
		if ((order / radix % 2))
			rotate_a(a, 0);
		else
			push_b(a, b);
	}
	while (ft_lstsize(*b))
		push_a(a, b);
}

void	ini_radix(t_list **a, t_list **b, ssize_t max_order)
{
	ssize_t	radix;

	radix = 1;
	while (radix <= max_order)
	{
		order_radix(a, b, radix);
		radix *= 2;
	}
}
