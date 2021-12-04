/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:39:39 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/01 17:32:40 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*buffer;

	(void) del;
	if (!lst)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		if (!begin)
		{
			buffer = ft_lstnew((*f)(lst->content));
			begin = buffer;
		}
		else
		{
			buffer->next = ft_lstnew((*f)(lst->content));
			buffer = buffer->next;
		}
		lst = lst->next;
	}
	return (begin);
}
