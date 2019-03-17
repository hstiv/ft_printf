/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:46:44 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 03:20:06 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		ft_str_size(double n, size_t prec)
{
	int			len;
	int			dot;

	len = 0;
	dot = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	if (prec > 0)
		len++;
	len += prec;
	return (len);
}

static void		ft_convert_rest(char *str, double n, size_t prec, int dot)
{
	size_t		i;
	
	i = 0;
	while (dot--)
	{
		n *= 10;
		*str = (int)n + '0';
		str++;
		n -= (int)n;
	}
	if (prec > 0)
	{
		*str = '.';
		str++;
		while (i++ < prec)
		{
			n *= 10;
			*str = (int)n + '0';
			str++;
			n -= (int)n;
		}
	}
	*str = '\0';
}

static void		ft_convert(char	*str, double n, size_t prec)
{
	int			dot;

	dot = 0;
	if (n < 0)
	{
		*str = '-';
		n = -n;
		str++;
	}
	while (n >= 1 && dot++ >= 0)
		n /= 10;
	ft_convert_rest(str, n, prec, dot);
}

char			*ft_ftoa(double n, int prec)
{
	char		*str;

	str = (char *)malloc(sizeof(*str) * ft_str_size(n, prec) + 1);
	if (str)
		ft_convert(str, n, prec);
//	ft_putstr(str);
//	free(str);
	return (str);
}
