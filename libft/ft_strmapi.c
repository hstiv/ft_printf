/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:24:03 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 12:57:09 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*str;

	a = 0;
	if (s && f)
	{
		while (s[a] != '\0')
			a++;
		if (!(str = (char*)malloc(sizeof(*str) * (a + 1))))
			return (NULL);
		a = 0;
		while (s[a] != '\0')
		{
			str[a] = (*f)(a, s[a]);
			a++;
		}
		str[a] = '\0';
		return (&str[0]);
	}
	else
		return (NULL);
}
