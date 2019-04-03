/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:13:15 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/07 16:00:24 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_freedel(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*copy;
	t_list		*begin;

	if (!lst || !f)
		return (NULL);
	tmp = 0;
	copy = (*f)(lst);
	if (!(tmp = ft_lstnew(copy->content, copy->content_size)))
		return (NULL);
	lst = lst->next;
	begin = tmp;
	while (lst != NULL)
	{
		copy = (*f)(lst);
		if (!(tmp->next = ft_lstnew(copy->content, copy->content_size)))
		{
			ft_lstdel(&begin, ft_freedel);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
		copy = lst;
	}
	return (begin);
}
