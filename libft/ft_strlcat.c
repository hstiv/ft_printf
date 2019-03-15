/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:17:25 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 13:06:00 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	i;

	a = 0;
	b = 0;
	c = 0;
	i = 1;
	while (src[c] != '\0')
		c++;
	while (dst[a] != '\0' && a++ < size)
	{
		i++;
		c++;
	}
	if (c > size && size < a)
		return (c);
	while (src[b] != '\0' && i++ < size)
		dst[a++] = src[b++];
	dst[a] = '\0';
	return (c);
}
