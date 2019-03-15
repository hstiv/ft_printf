/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:47:51 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/29 21:39:11 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (a < len && haystack[a] != '\0' && needle[b] != '\0')
	{
		c = a;
		while (haystack[c] == needle[b] && c < len)
		{
			if (haystack[c++] == '\0' || needle[b++] == '\0')
				break ;
		}
		if (needle[b] == '\0')
			return ((char*)&haystack[a]);
		b = 0;
		a++;
	}
	return ((char*)0);
}
