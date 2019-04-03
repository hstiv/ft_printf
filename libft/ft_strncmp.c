/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:12:35 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/08 14:20:06 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n < 1)
		return (0);
	while (s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a] && a < n)
		a++;
	if (a == n)
		a--;
	return (((unsigned char*)s1)[a] - ((unsigned char*)s2)[a]);
}
