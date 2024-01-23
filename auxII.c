/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxII.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:19 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/08/02 13:34:29 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_object	*new_obj(int value, ssize_t order)
{
	t_object	*new_o;

	new_o = ft_calloc(1, sizeof(t_object));
	if (!new_o)
		return (NULL);
	new_o->value = value;
	new_o->order = order;
	return (new_o);
}

void	set_order(t_list *list, ssize_t order)
{
	((t_object *)(list)->content)->order = order;
}

int	obj_value(t_list *list)
{
	return (((t_object *)(list)->content)->value);
}

ssize_t	obj_order(t_list *list)
{
	return (((t_object *)(list)->content)->order);
}

ssize_t	set_orders(t_list **list)
{
	ssize_t	order;
	int		i;
	t_list	*min;
	t_list	*current;

	order = -1;
	i = 0;
	while (i++ < ft_lstsize(*list))
	{
		min = *list;
		while (min && obj_order(min) != -1)
			min = min->next;
		current = min->next;
		while (current)
		{
			if (obj_order(current) == -1 && obj_value(min) > obj_value(current))
				min = current;
			current = current->next;
		}
		set_order(min, ++order);
	}
	return (order);
}
