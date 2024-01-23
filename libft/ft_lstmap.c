/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:12:38 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/27 11:14:02 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*start;		

	if (!f)
		return (NULL);
	start = NULL;
	while (lst)
	{	
		aux = ft_lstnew((*f)(lst->content));
		if (!aux)
		{
			ft_lstclear(&start, (*del));
			return (NULL);
		}
		ft_lstadd_back(&start, aux);
		lst = lst->next;
	}	
	return (start);
}
