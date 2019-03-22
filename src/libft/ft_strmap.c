/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:14:07 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/30 19:09:14 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	char	*str;

	a = 0;
	if (s)
	{
		while (s[a] != '\0')
			a++;
		if (!(str = (char*)malloc(sizeof(*str) * (a + 1))))
			return (NULL);
		a = 0;
		while (s[a] != '\0')
		{
			str[a] = (*f)(s[a]);
			a++;
		}
		str[a] = '\0';
		return (&str[0]);
	}
	else
		return (NULL);
}
