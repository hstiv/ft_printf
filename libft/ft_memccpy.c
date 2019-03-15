/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:25:20 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/04 19:19:46 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	a;

	a = 0;
	if (!dst && !src)
		return (NULL);
	while (a < n)
	{
		(((unsigned char*)dst)[a]) = (((unsigned char*)src)[a]);
		if ((((unsigned char*)dst)[a]) == (unsigned char)c)
		{
			a++;
			return (&dst[a]);
		}
		a++;
	}
	return (NULL);
}
