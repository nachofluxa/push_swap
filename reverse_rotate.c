/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:52 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/08/24 09:51:42 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **a, int type)
{
	t_list	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	last = remove_last(a);
	ft_lstadd_front(a, last);
	if (type == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **b, int type)
{
	t_list	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	last = remove_last(b);
	ft_lstadd_front(b, last);
	if (type == 0)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_list **a, t_list **b)
{
	reverse_rotate_a(a, 1);
	reverse_rotate_b(b, 1);
	write(1, "rrr\n", 4);
}
