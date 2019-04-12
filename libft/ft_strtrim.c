/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:58:42 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/01 12:43:14 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlentrim(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a] == ' ' || str[a] == '\n' || str[a] == '\t')
		a++;
	while (str[a] != '\0')
	{
		a++;
		b++;
	}
	a--;
	while (str[a] == ' ' || str[a] == '\n' || str[a] == '\t')
	{
		a--;
		b--;
	}
	if (b < 0)
		b = 0;
	return (b);
}

static int		ft_stlen(char *str)
{
	int		a;

	a = 0;
	while (str[a])
		a++;
	a--;
	return (a);
}

char			*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	a = 0;
	c = 0;
	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * ft_strlentrim((char*)s) + 1)))
		return (NULL);
	str[a] = '\0';
	if (ft_strlentrim((char*)s) != 0)
	{
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
			a++;
		b = ft_stlen((char*)s);
		while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
			b--;
		while (a <= b)
			str[c++] = s[a++];
	}
	str[c] = '\0';
	return (&str[0]);
}
