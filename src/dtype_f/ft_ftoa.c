/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:46:44 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 18:33:21 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void		prestr_maker(t_pf_list *base, char *str)
{
	int			l;
	int			i;

	i = 0;
	l = base->width - (base->wid_bool + base->acc);
	if (l > 0)
	{
		while (l >= i++ && base->nol != 0)
		{
			*str = '0';
			str++;
		}
		while (l >= i++)
		{
			*str = ' ';
			str++;
		}
	}
}

static int		ft_str_size(double n, t_pf_list *base)
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
	if (base->acc > 0)
		len++;
	len += base->acc;
	return (len);
}

static void		ft_convert_rest(char *str, double n, t_pf_list *base, int dot)
{
	size_t		i;
	
	i = 0;
	prestr_maker(base, str);
	while (dot--)
	{
		n *= 10;
		*str = (int)n + '0';
		str++;
		n -= (int)n;
	}
//	ft_putnbr(base->acc);
//	ft_putchar('\n');
	if (base->acc > 0)
	{
		*str = '.';
		str++;
		while (i++ < base->acc)
		{
			n *= 10;
			*str = (int)n + '0';
			str++;
			n -= (int)n;
		}
	}
	*str = '\0';
}

static void		ft_convert(char	*str, double n, t_pf_list *base)
{
	int			dot;

	dot = 0;
	if (n < 0)
	{
		*str = '-';
		n = -n;
		str++;
	}
	while (n >= 1)
	{
		n /= 10;
		dot++;
		base->wid_bool++;
	}
	ft_convert_rest(str, n, base, dot);
}

char			*pf_ftoa(double n, t_pf_list *base)
{
	char		*str;
	int			l;
	int			o;
	double		t;

	l = 0;
	t = n;
	while (t >= 1)
	{
		t /= 10;
		base->wid_bool++;
	}
	l = base->wid_bool + base->acc + 1;
	o = base->width - (l);
	if (o > 0)
		l += o;
	ft_putnbr(l);
	ft_putchar('\n');
	if (base->width != 0)
		str = (char *)malloc(sizeof(*str) * (l + 1));
	if (str)
		ft_convert(str, n, base);
	return (str);
}
