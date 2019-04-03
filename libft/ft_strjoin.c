/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:14:07 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/30 19:29:50 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_stlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) *
					(ft_stlen((char*)s1) + ft_stlen((char*)s2)) + 1)))
		return (NULL);
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		str[a++] = s2[b++];
	}
	str[a] = '\0';
	return (&str[0]);
}
