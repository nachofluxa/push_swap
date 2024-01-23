/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:55 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/06 13:08:19 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a, int type)
{
	t_list	*first;

	if (ft_lstsize(*a) < 2)
		return ;
	first = remove_first(a);
	ft_lstadd_back(a, first);
	if (type == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **b, int type)
{
	t_list	*first;

	if (ft_lstsize(*b) < 2)
		return ;
	first = remove_first(b);
	ft_lstadd_back(b, first);
	if (type == 0)
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_list **a, t_list **b)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	write(1, "rr\n", 3);
}
