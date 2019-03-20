/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:58:08 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/03 13:36:08 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbrlen(int n)
{
	int	a;
	int	b;

	b = n;
	a = 0;
	if (b == 0)
		return (1);
	else if (b == -2147483648)
		return (10);
	else if (b < 0)
		b = -b;
	while (b != 0)
	{
		b = b / 10;
		a++;
	}
	return (a);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_nbrlen(n);
	sign = n < 0 ? 1 : 0;
	if (!(str = (char*)malloc(sizeof(*str) * (len + sign) + 1)))
		return (NULL);
	str[len-- + sign] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len-- + sign] = '8';
			n = -214748364;
		}
		n = n * -1;
	}
	while (len + sign >= sign)
	{
		str[len-- + sign] = n % 10 + '0';
		n = n / 10;
	}
	return (&str[0]);
}
