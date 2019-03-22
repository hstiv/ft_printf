/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:05:04 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 13:12:55 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == (char)c)
			return ((char*)s + a);
		a++;
	}
	if (c == '\0')
		return ((char*)s + a);
	return (NULL);
}
