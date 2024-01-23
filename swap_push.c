/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:59 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/08/24 10:18:12 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a, int type)
{
	t_list	*first_to_second;
	t_list	*second_to_first;

	if (ft_lstsize(*a) < 2)
		return ;
	first_to_second = remove_first(a);
	second_to_first = remove_first(a);
	ft_lstadd_front(a, first_to_second);
	ft_lstadd_front(a, second_to_first);
	if (type == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **b, int type)
{
	t_list	*first_to_second;
	t_list	*second_to_first;

	if (ft_lstsize(*b) < 2)
		return ;
	first_to_second = remove_first(b);
	second_to_first = remove_first(b);
	ft_lstadd_front(b, first_to_second);
	ft_lstadd_front(b, second_to_first);
	if (type == 0)
		write(1, "sb\n", 3);
}

void	swap_a_b(t_list **a, t_list **b)
{
	swap_a(a, 1);
	swap_b(b, 1);
	write(1, "ss\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*aux;

	if (!ft_lstsize(*b))
		return ;
	aux = remove_first(b);
	ft_lstadd_front(a, aux);
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*aux;

	if (!ft_lstsize(*a))
		return ;
	aux = remove_first(a);
	ft_lstadd_front(b, aux);
	write(1, "pb\n", 3);
}
