/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:08:36 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 13:09:33 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*str;

	a = 0;
	while (s1[a] != '\0')
		a++;
	if (!(str = ((char*)malloc(sizeof(*str) * (a + 1)))))
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	str[a] = '\0';
	return (&str[0]);
}
