/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:27:58 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/30 19:22:21 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*str;

	a = 0;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
			return (NULL);
		while (a < len)
		{
			str[a] = s[start];
			a++;
			start++;
		}
		str[a] = '\0';
		return (&str[0]);
	}
	else
		return (NULL);
}
