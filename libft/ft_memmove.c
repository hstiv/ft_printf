/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:12:48 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/29 17:36:38 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	a = 0;
	if (str2 < str1)
	{
		while (a < len)
		{
			a++;
			str1[len - a] = str2[len - a];
		}
	}
	else
	{
		while (a < len)
		{
			str1[a] = str2[a];
			a++;
		}
	}
	return (dst);
}
