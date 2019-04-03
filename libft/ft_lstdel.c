/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:38:26 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 14:20:15 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*dell;
	t_list	*sub;

	if (!*alst || !del)
		return ;
	dell = *alst;
	sub = dell->next;
	while (dell->next != NULL)
	{
		(*del)(dell->content, dell->content_size);
		free(*alst);
		*alst = sub;
		dell = *alst;
		sub = dell->next;
	}
	(*del)(dell->content, dell->content_size);
	free(*alst);
	*alst = NULL;
}
