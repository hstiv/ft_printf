/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:31:35 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/04 17:42:14 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (src[a] == '\0')
			break ;
		dst[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dst[a] = '\0';
		a++;
	}
	return (&dst[0]);
}
