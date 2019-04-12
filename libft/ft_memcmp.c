/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:56:25 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/23 15:17:08 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;
	int		b;
	int		b1;

	a = 0;
	while (a < n)
	{
		if ((((unsigned char*)s1)[a]) != (((unsigned char*)s2)[a]))
		{
			b = (((unsigned char*)s1)[a]);
			b1 = (((unsigned char*)s2)[a]);
			return (b - b1);
		}
		a++;
	}
	return (0);
}
