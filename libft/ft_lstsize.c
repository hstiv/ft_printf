/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:22:41 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 17:37:31 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list **alst)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *alst;
	if (!tmp)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
