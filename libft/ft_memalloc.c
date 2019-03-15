/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:09:10 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/29 22:02:53 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t			a;
	unsigned char	*str;

	a = 0;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (a < size)
	{
		str[a] = 0;
		a++;
	}
	return ((void*)&str[0]);
}
