/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:29:43 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/24 10:31:03 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = NULL;
	list = (t_list *) malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = 0;
	return (list);
}
