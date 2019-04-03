/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmpi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:17:18 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/08 14:28:24 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmpi(char const *s1, char const *s2, size_t n)
{
	size_t	a;

	a = 0;
	if ((!s1 || !s2) || (((!s1[a] && s2[a]) || (s1[a] && !s2[a])) && n > 0))
		return (0);
	while ((s1[a] != '\0' || s2[a] != '\0') && a < n)
	{
		while (s1[a] >= 'a' && s1[a] <= 'z' && a < n)
		{
			if ((s1[a] != s2[a]) && (s1[a] != (s2[a] - ('a' - 'A'))) && a < n)
				return (0);
			a++;
		}
		while (s1[a] >= 'A' && s1[a] <= 'Z' && a < n)
		{
			if ((s1[a] != s2[a]) && (s1[a] != (s2[a] + ('a' - 'A'))) && a < n)
				return (0);
			a++;
		}
		if ((s1[a] < 'a' || s1[a] > 'z') && (s1[a] < 'A' || s1[a] > 'Z') &&
				((unsigned char*)s1)[a] != ((unsigned char*)s2)[a] && a < n)
			return (0);
		a++;
	}
	return (1);
}
