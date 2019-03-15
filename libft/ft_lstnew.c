/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:37:04 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 17:31:21 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_clear(t_list *new)
{
	free(new);
	return (NULL);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	int		i;
	t_list	*new;

	i = 0;
	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (!content_size)
		new->content_size = 0;
	else
		new->content_size = content_size;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (char*)malloc(sizeof(char) * content_size)))
			return (ft_clear(new));
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
