/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:21:43 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/04 19:19:13 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (!dst && !src)
		return (NULL);
	while (a < n)
	{
		((unsigned char*)dst)[a] =
			((unsigned char*)src)[a];
		a++;
	}
	return (dst);
}
